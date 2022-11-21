#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[30];
    char surname[30];
    int course;                 // year of study
    double average;             // average grade

    int load;                   // number of courses
    char courses[10][30];       // course names
    int grades[10];             // course grades

    char languages[100];        // spoken languages

} Student;

int main(int argc, char *argv[]) {
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");

    if (db){
        Student students[1000];         // all the data goes here
        int size = 0;                   // how many students in database

        // reading data from file
        fread(&size, sizeof(int), 1, db);

        for (int i = 0; i < size; i++){
            fread(&students[i], sizeof(Student), 1, db);
        }
        printf("%d records loaded succesfully\n", size);


        // MODIFY CODE BELOW
        int counter = 0; // for counting students
        for (int i = 0; i < size; ++i){ // process all the student records in database
            int student_ok = 0;
            Student s = students[i]; // store data for each student in s
            //Find if student has duplications
            for(int i2 = 0; i2 < s.load; i2++)
            {
                for(int i3 = i2 - 1; i3 >= 0; i3--)
                {
                    if(strcmp(s.courses[i2], s.courses[i3]) == 0)
                    {
                        student_ok = 1;
                        i2 = s.load;
                        break;
                    }
                }
            }
            //Check languages
            if(!student_ok)
            {
                char languages[100][100] = {0};
                int language_count = 0;
                int letter_nr = 0;

                for(int i2 = 0; s.languages[i2] != '\0'; i2++)
                {
                    if(s.languages[i2] == ' ')
                    {
                        for(int i3 = language_count - 1; i3 >= 0; i3--)
                        {
                            if(strcmp(languages[language_count], languages[i3]) == 0)
                            {
                                goto WRITING;
                            }
                        }
                        letter_nr = 0;
                        language_count++;
                        i2++;
                    }
                    languages[language_count][letter_nr] = s.languages[i2];
                    letter_nr++;
                }
                for(int i2 = language_count - 1; i2 >= 0; i2--)
                {
                    if(strcmp(languages[language_count], languages[i2]) == 0)
                    {
                        student_ok = 1;
                        break;
                    }
                }
            }
            //Print student data if the student isn't filtered
            if(student_ok)
            {
                WRITING:
                counter++;
                printf("%s %s: Course: %d Average mark: %f Load: %d\nSubjects:\n", s.name, s.surname, s.course, s.average, s.load); // print student data
                for (int i2 = 0; i2 < s.load; ++i2){ // process each course taken by the student
                    printf("%s. Mark: %d\n", s.courses[i2], s.grades[i2]);
                }
                printf("Languages: %s\n\n", s.languages);
            }
        }
        printf("Filter applied, %d students found\n", counter); // how many passed the filters
        fclose(db);
    } else {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}