#include<stdio.h>
#include<stdlib.h>
int main(){

    int i ;
    static int a= -1;
    static int count = 0; 
    start: 
    printf("Enter The Number : ");
    scanf("%d",&i);
    if(i==-1){
        goto end;
    }
    else{
        if(i!=a){
            count+=1;
            a = i;
            goto start;
        }
        goto start;
    }     
    end: 
        printf("result = %d\n", count);
    return 0;
}
