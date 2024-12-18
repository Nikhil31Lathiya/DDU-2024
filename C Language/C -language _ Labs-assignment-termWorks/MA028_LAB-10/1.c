#include <stdio.h>

struct StudentData {
    int id, marks;
    char name[25];
};

typedef struct StudentData StudentData;

void getData(StudentData *s) {
    printf("\nEnter Student ID: ");
    scanf("%d", &s->id);
    
    printf("Enter Student marks: ");
    scanf("%d", &s->marks);
    
    printf("Enter Student name: ");
    scanf("%s", s->name);
}

void DisplayData(StudentData *s) {
    printf("\nStudent ID: %d", s->id);
    printf("\nStudent marks: %d", s->marks);
    printf("\nStudent name: %s", s->name);
}

int main() {
    int N, M;

    printf("Enter the No of students (N): ");
    scanf("%d", &N);

    printf("Enter the marks (M): ");
    scanf("%d", &M);

    StudentData students[N];

    for (int i = 0; i < N; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        getData(&students[i]);
    }

    printf("\nStudents with marks less than %d:\n", M);
    for (int i = 0; i < N; i++) {
        if (students[i].marks < M) {
            DisplayData(&students[i]);
            printf("\n");
        }
    }

    return 0;
}
