#include<stdio.h>
int main(){
    int a,b,z;
    printf("Enter Number 1 : \n");
    scanf("%d",&a);
    printf("Enter Number 2 : \n");
    scanf("%d",&b);


    for(int i=1; i<=b ; i++ ){
        z+=a;     
    }
    printf("\n%d",z);
    return 0;
}