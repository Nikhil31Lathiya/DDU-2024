#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,d;

  printf("Enter the No : ");
  scanf("%d",&n);

  while(n>0)
  {
    d = n%10;

    if(d>=2)
    {
      printf("It is Not binary  ");
      exit(0);
    }
    n= n/10;
  }

  printf("It is a binary No  ");
return 0;
}