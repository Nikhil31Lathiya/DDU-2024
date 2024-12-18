// #include<stdio.h>

// struct student {
//     int r_no;
//     char name[50];
//     int marks[2];
//     int total;
//     // float per; 
// }s[3];

//     void getData(struct student s[]){
//         for(int i=0; i<3; i++){
//         printf("Enter roll No for student %d " , i+1);
//         scanf("%d",&s[i].r_no);
//         printf("Enter Name for student %d " , i+1);
//         scanf("%s",&s[i].name);
//         for(int j=0; j<2; j++){
//             printf("Enter marks for sub %d " , j+1);
//             scanf("%d",&s[i].marks[j]);
//         }
//     }
//     }

//     // void calcData(const int marks[]){
//     //     int total = 0;
//     //         for(int j=0 ; j<2 ; j++){
//     //         total +=  marks[j]; 
//     //         }
//     //     printf("\n total marks of student  is %d " , total );
//     // }

//     void calaData(struct student s[]){
//         for(int i=0 ; i<3 ; i++){
//             for(int j=0 ; j<2 ; j++){
//                s[i].total += s.marks[j]; 
//             }
//         }
//          printf("\n total marks of student %d is %d " , i + 1 , s[i].total );
//     }
// int main()
// {
//     getData(s);
    
//     for(int i=0 ; i<3 ; i++){
//         calcData(s[i]);
//     }
// return 0;
// }

#include<stdio.h>

struct student {
    int r_no;
    char name[50];
    int marks[2];
    int total;
    float per; 
}s[3];

void getData(struct student s[]) {
    for(int i = 0; i < 3; i++) {
        printf("Enter roll No for student %d: ", i + 1);
        scanf("%d", &s[i].r_no);
        printf("Enter Name for student %d: ", i + 1);
        scanf("%s", s[i].name);
        for(int j = 0; j < 2; j++) {
            printf("Enter marks for sub %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
}

void calaData(struct student s[]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            s[i].total += s[i].marks[j];
        }
        s[i].per = ((float)s[i].total/200)*100;
        printf("\nTotal marks of student %d is %d", i + 1, s[i].total);
        printf("\nTotal per of student %d is %f", i + 1, s[i].per);
    }
}

int main() {
    getData(s);

        calaData(s);
   

    return 0;
}
