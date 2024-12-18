#include<stdio.h>
int main(){
    int n,sum=0;

    printf("Enter No : ");
    scanf("%d", &n);

    printf("\n pv div : ");

    for(int i=1 ; i<= n ; i++){
        
        if(n%i==0)
        {
            sum= sum+i;
            printf("%d ",i);
        }
    }
    printf("Sum is : %d",sum);

    if(sum==n){
        printf("No is Perfect ");
    }
    else{
        printf("is is not ");
    }
    return 0;
}