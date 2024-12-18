#include<stdio.h>
int main(){

    int m , n , result=0 ;

    printf("Enter The value for M : \n");
    scanf("%d", &m) ;
    printf("Enter The value for N : \n");
    scanf("%d", &n) ;

    if(m%n==0){
        result = m/n ; 
        printf("\n%d ",result) ;
    }
    else{
        printf("\n%d", result);
    }
    return 0;
}