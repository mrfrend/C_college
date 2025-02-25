#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int indexOfStudent(Student * student, Student students[], int amount) {
    for (size_t i = 0; i < amount; i++)
    {
        if (strcmp(student->name, students[i].name) == 0 
        && strcmp(student->group, students[i].group) == 0
        ) return i;
    }
    return -1;
    
}


int read_string(FILE * file, Student * student, Student students[], int * size) {
    float avrg = 0;
    int count_marks = 0;
    char ch;

    if (fscanf(file, "%[^;]; %[^;]; %[^;];", student->name, student->group, student->favourite_subject) != 3) return 0;
    // if (fscanf(file, " %39s;", student->name) != 1) return 0;
    // if (fscanf(file, " %2s;", student->group) != 1) return 0;
    // if (fscanf(file, " %29s;", student->favourite_subject) != 1) return 0;

    while ( (ch = fgetc(file)) != '\n' && !feof(file)) {
        if (ch >= '2' && ch <= '5') {
            avrg += ch - '0';
            count_marks++;
        }
}
    avrg /= (float) count_marks;
    student->avrg_mark = avrg;
    int index = indexOfStudent(student, students, *size);
    if (index != -1 && students[index].avrg_mark < student->avrg_mark) {
        students[index] = *student;
    } else {
        students[*size] = *student;
        (*size)++;
    }
    return 1;

    
}



void set_favourite_subject(Student * student);

void print_string_out(Student * student) {
    printf("%s %s %s\n", student->group, student->name, student->favourite_subject);
}

int compare_students(Student *student_a, Student *student_b) {
    int cmp = strcmp(student_a->group, student_b->group);
    if (cmp != 0) {
        return cmp;
    }
    return strcmp(student_a->name, student_b->name);
}

void sort_students(Student students[], int size, int (*sort_func) (Student *, Student *)) {
    for (size_t i = 0; i < size - 1; i++)
    {
        if (sort_func(&students[i], &students[i + 1]) == 1) {
            Student temp = students[i];
            students[i] = students[i + 1];
            students[i + 1] = temp;
        }
    }
    
}