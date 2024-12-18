#include<stdio.h> 
void main() 
{ 
  int a,b,c; 
  scanf("%d %d %d",&a,&b,&c); 
  printf("%0.1f ",(a+b+c)/3.0); 
  while(1) 
  { 
    a=b; 
    b=c; 
    scanf("%d",&c); 
    if(c==-1) 
      break; 
    printf("%0.1f ",(a+b+c)/3.0); 
} 
} 