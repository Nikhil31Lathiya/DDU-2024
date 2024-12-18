#include<stdio.h>

int main(){
        int n;

    printf("Enter your Numbr : \n");
    scanf("%d",&n);

        for(int i=1 ; i<=n ; i++){

            for(int j=n-1 ; j>=i ; j--){
                printf(" ");
            }

            for(int k=1 ; k<=i ; k++){
                printf("* ");
            }
            printf("\n");
        }


        for(int i=n ; i>0 ; i--){

            for(int j=n ; j>i ; j--){
                printf(" ");
            }

            for(int k=1 ; k<=i ; k++){
                printf("* ");
            }
            printf("\n");
        }
        return 0 ;

}