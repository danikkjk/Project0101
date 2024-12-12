#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <locale.h>

typedef struct Student {
    char name[50];
    int birth_year;
    int course;
    float average_grade;
} STUDENT;

void print_student(const STUDENT* ps) {
    printf("{%s; %d; %d; %.2f}\n", ps->name, ps->birth_year, ps->course, ps->average_grade);
}

void print_students(STUDENT students[], int size) {
    for (int i = 0; i < size; ++i) {
        print_student(&students[i]);
    }
}

int compare_average_grade_asc(const void* s1, const void* s2) {
    STUDENT* ps1 = (STUDENT*)s1;
    STUDENT* ps2 = (STUDENT*)s2;
    return (ps1->average_grade > ps2->average_grade) - (ps1->average_grade < ps2->average_grade);
}

int compare_average_grade_desc(const void* s1, const void* s2) {
    STUDENT* ps1 = (STUDENT*)s1;
    STUDENT* ps2 = (STUDENT*)s2;
    return (ps2->average_grade > ps1->average_grade) - (ps2->average_grade < ps1->average_grade);
}

int main() {
    setlocale(LC_ALL, "RU");
    STUDENT students[3] = {
        {"Ivan Petrenko", 2000, 2, 4.5},
        {"Oksana Ivanova", 1999, 3, 4.8},
        {"Pavlo Shevchenko", 2001, 1, 3.9},
    };

    int sz = sizeof(students) / sizeof(students[0]);

    printf("—писок студентов по выростанию середнего бала:\n");
    qsort(students, sz, sizeof(STUDENT), compare_average_grade_asc);
    print_students(students, sz);

    printf("---------------------------------------------\n");
    printf("—писок студентов по спаданием середнего бала:\n");
    qsort(students, sz, sizeof(STUDENT), compare_average_grade_desc);
    print_students(students, sz);

    return 0;
}