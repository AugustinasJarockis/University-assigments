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
        //Find which courses have a single student
        char courses_with_one_student [1000][30];
        int bad_course_count = 0;
        int course_count = 0;
        char courses [1000][30];
        int course_student_count [1000];
        //Count students for all courses
        for (int i = 0; i < size; ++i){ // process all the student records in database
            Student s = students[i]; // store data for each student in s
            for(int i2 = 0; i2 < s.load; i2++)
            {
                int has_two = 0;
                int has_been = 0;
                for(int i3 = i2 - 1; i3 >= 0; i3--)
                {
                    if(strcmp(s.courses[i2], s.courses[i3]) == 0)
                    {
                        has_two = 1;
                        break;
                    }
                }
                if(!has_two)
                {
                    for(int i3 = 0; i3 < course_count; i3++)
                    {
                        if(strcmp(s.courses[i2], courses[i3]) == 0)
                        {
                            has_been = 1;
                            course_student_count[i3]++;
                            break;
                        }
                    }
                    if(has_been == 0)
                    {
                        strcpy(courses[course_count], s.courses[i2]);
                        course_student_count[course_count] = 1;
                        course_count++;
                    }
                }
            }
        }
        //Pick out courses with only a single student
        for(int i = 0; i < course_count; i++)
        {
            if(course_student_count[i] == 1)
            {
                strcpy(courses_with_one_student[bad_course_count], courses[i]);
                bad_course_count++;
            }
        }
        for (int i = 0; i < size; ++i){ // process all the student records in database
            int student_ok = 1;
            Student s = students[i]; // store data for each student in s
            //Find if student doesn't have the course where he is the only student
            for(int i2 = 0; i2 < s.load; i2++)
            {
                for(int i3 = 0; i3 < bad_course_count; i3++)
                {
                    if(strcmp(s.courses[i2], courses_with_one_student[i3]) == 0)
                    {
                        student_ok = 0;
                        i2 = s.load;
                        break;
                    }
                }
            }
            //Print student data if the student isn't filtered
            if(student_ok)
            {
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
