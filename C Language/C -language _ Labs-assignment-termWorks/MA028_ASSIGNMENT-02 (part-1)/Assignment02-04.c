#include<stdio.h>
int main()
{
    int a[10],b[10];
    int small=0,l1,l2,i,flag=0;
    scanf("%d",&l1);
    for(i=0;i<l1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&l2);
    for(i=0;i<l2;i++)
    {
        scanf("%d",&b[i]);
    }
    small=a[0];
    for(i=1;i<l1;i++)
    {
        if(small>a[i])
          small=a[i];
    }
    for(i=0;i<l2;i++)
    {
        if(small==b[i])
          flag=1;
    }
        if(flag==1)
        {
            printf("NO");
        }
        else
        {
            printf("%d",small);
        } 
   return 0;
}