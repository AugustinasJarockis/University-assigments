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

        int counterDemo = 0; // for counting students
        for (int i = 0; i < size; ++i){ // process all the student records in database
            Student s = students[i]; // store data for each student in s

            int name_longer = 0;
            int i;
            for(i = 0; s.name[i] != '\0' && s.surname[i] != '\0'; i++)
            { }
            if(s.name[i] != '\0')
            {
                name_longer = 1;
            }

            if(name_longer){ // *** first filter, conditions on the student
                printf("%s %s: Course: %d Average mark: %f Load: %d\nSubjects:\n", s.name, s.surname, s.course, s.average, s.load); // print student data
                int anotherDemo = 0; // for counting courses/grades
                for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                    if(1){ // *** second filter, conditions on the course/grade
                        ++anotherDemo; // counting courses
                        printf("%s. Mark: %d\n", s.courses[i], s.grades[i]);
                    }
                }
                printf("Languages: %s\n\n", s.languages);

                if (anotherDemo == s.load) // *** third filter, various other conditions
                    ++counterDemo; // counting students
            }
        }
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
        fclose(db);
    } else {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}
