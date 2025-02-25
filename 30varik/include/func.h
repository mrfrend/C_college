#include "structure.h"
#include <stdio.h>

int read_string(FILE * file, Student * student, Student students[], int * size);

int indexOfStudent(Student * student, Student students[], int amount);

void print_string_out(Student * student);

int compare_students (Student *, Student *);

void sort_students(Student students[], int size, int (*sort_func) (Student *, Student *));
