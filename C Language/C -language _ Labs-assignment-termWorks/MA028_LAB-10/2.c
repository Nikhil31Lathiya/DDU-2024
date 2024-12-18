#include<stdio.h>

struct StudentData {
    int rno;
    char name[25];
    int marks[5];
    int total, perce;
};

typedef struct StudentData StudentData;

void getData(StudentData *s) {
    printf("Enter student rollno : ");
    scanf("%d", &s->rno);

    printf("Enter student name : ");
    scanf("%s", s->name);

    for (int i = 0; i < 5; i++) {
        printf("Enter student sub%d mark : ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

void calc(StudentData *s) {
    s->total = 0;
    for (int i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->perce = (s->total * 100) / 500; 
}

void displayData(StudentData *s) {
    printf("\nRollno : %d", s->rno);
    printf("\nName : %s", s->name);
    for (int i = 0; i < 5; i++) {
        printf("\nSub%d mark : %d", i + 1, s->marks[i]);
    }
    printf("\n\nTotal Marks : %d", s->total);
    printf("\nPercentage : %d%%", s->perce);
}

int main() {
    StudentData st[10];

    for (int i = 0; i < 10; i++) {
        getData(&st[i]);
        calc(&st[i]);
        displayData(&st[i]);
        printf("\n--------------------------------\n");
    }

    return 0;
}
