#include<stdio.h>

int main(){
    int i,j,k ;
    int z=1;
    int n=5;

    for(i=1 ; i<=n ; i++){

        for(j=n-1 ; j>=i ; j--){
            printf(" ");
        }
        for(k=1 ; k<=i*2-1 ; k++){
            printf("*");
        }   

        printf("\n");
    }

    for(i=1 ; i<=n ; i++){
        
        for(j=1; j<=i ; j++){
            printf(" ");
        }
        for(k=1 ; k<=2*(n-i)-1 ; k++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}