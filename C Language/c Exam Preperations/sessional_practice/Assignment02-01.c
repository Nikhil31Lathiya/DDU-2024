#include<stdio.h>
int main()
{
    int val= -1;
    int n,k ;
    int count = 0;
    printf("Enter the occurence : ");
    scanf("%d", &k);

    while(1)
    {
        scanf("%d", &n);

        if(n==-1)
        {
            break;
        }
        if(n%2==0){
            count++;
        }
        if(count == k){
            val = n;
            break;
        }
    }
    printf("%d\n", val);
return 0;
}