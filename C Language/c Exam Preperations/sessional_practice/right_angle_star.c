#include<stdio.h>
int main(){
    int n=5;

    for(int i=1 ; i<=n ; i++){

        for(int j =n ; j>0 ; j--)
        {
            if(i>=j)
            {
                printf("* ");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

}