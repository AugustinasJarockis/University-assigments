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
        //Find students who now most languages
        int max_languages = 0;
        int most_multilingual_student_nr[1000];
        int counter = 0; // for counting students
        for(int i = 0; i < size; i++)
        {
            Student s = students[i]; // store data for each student in s
            int language_count = 1;

            for(int i2 = 0; s.languages[i2] != '\0'; i2++)
            {
                if(s.languages[i2] == ' ')
                    language_count++;
            }

            if(language_count == max_languages)
            {
                most_multilingual_student_nr[counter] = i;
                counter++;
            }
            else if(language_count > max_languages)
            {
                max_languages++;
                most_multilingual_student_nr[0] = i;
                counter = 1;
            }
        }

        for (int i = 0; i < counter; ++i){ // process all the student records in database
            Student s = students[most_multilingual_student_nr[i]]; // store data for each student in s
            printf("%s %s: Course: %d Average mark: %f Load: %d\nSubjects:\n", s.name, s.surname, s.course, s.average, s.load); // print student data
            for (int i2 = 0; i2 < s.load; ++i2){ // process each course taken by the student
                printf("%s. Mark: %d\n", s.courses[i2], s.grades[i2]);
            }
            printf("Languages: %s\n\n", s.languages);
        }
        printf("Filter applied, %d students found\n", counter); // how many passed the filters
        fclose(db);
    } else {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}
