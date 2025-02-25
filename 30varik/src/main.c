#include <stdio.h>
#include <stdlib.h>
#include "..\include\func.h"

int main() {
    Student *student = malloc(sizeof(Student));
    if (student == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    FILE *input = stdin;
    Student *students = malloc(sizeof(Student) * 100);
    if (students == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        free(student);
        return 1;
    }

    int amount_students = 0;
    while (read_string(input, student, students, &amount_students) && !feof(input));

    sort_students(students, amount_students, compare_students);

    for (size_t i = 0; i < amount_students; i++) {
        print_string_out(&students[i]);
    }

    free(students);
    free(student);
    return 0;
}