#include<stdio.h>

void swap(int *n1,int *n2){
    int temp;  
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(){

    int n1,n2;

    printf("Enter n1 value : ");
    scanf("%d",&n1);
    printf("Enter n2 value : ");
    scanf("%d",&n2);
    swap(&n1,&n2);
    printf("\nn1 value : %d",n1);
    printf("\nn2 value : %d",n2);

    return 0;
}