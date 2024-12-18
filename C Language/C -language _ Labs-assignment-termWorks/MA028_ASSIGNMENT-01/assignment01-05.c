#include<stdio.h>
int main(){

    int i  , flag= 1;
    static int temp = -1;
    while (1){

        printf("Enter Number : ");
        scanf("%d",&i);
        
        if(i==-1){
            break;
        }

        if(temp == i){          
            flag = 0;
        }
        else{
            flag = 1;
            temp = i;
        
        }
    }
        printf("\n%d",flag);

    return 0;
}