#include<stdio.h>

int main(){

    int n=7;
    int k=n;

    for(int m=1; m<=n+1 ; m++){
        printf("* ");
    }
    printf("\n");

    for(int i=1 ; i<=n ; i++){

        for(int j=0; j<=k+2 ; j++){
            if(j==0 || j==k+1){
                printf("* ");
            }
            else{
                printf(" ");
            }
        }
        k-=2;
        printf("\n");
    }

    return 0;
}