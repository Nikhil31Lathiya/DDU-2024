#include <stdio.h>
struct books{
    char b_cat;
    int b_code, price, edition, copies;
    char b_title[30], a_name[30];
} b[10];

void get_val(){
    printf("Enter Category : ");
    scanf("%c", &b[0].b_cat);
    printf("Enter Code : ");
    scanf("%d", &b[0].b_code);
    printf("Enter Title : ");
    scanf(" %s", b[0].b_title);
    printf("Enter Name : ");
    scanf(" %s", b[0].a_name);
    printf("Enter Price : ");
    scanf("%d", &b[0].price);
    printf("Enter Edition : ");
    scanf("%d", &b[0].edition);
    printf("Enter No of copies : ");
    scanf("%d", &b[0].copies);
}
void display(){
    printf("\nCategory : %c\n", b[0].b_cat);
    printf("Code : %d\n", b[0].b_code);
    printf("Title : %s\n", b[0].b_title);
    printf("Name : %s\n", b[0].a_name);
    printf("Price : %d\n", b[0].price);

    printf("Edition : %d\n", b[0].edition);
    printf("No of copies : %d\n", b[0].copies);
}
int main(){
    get_val();
    display();
    return 0;
}