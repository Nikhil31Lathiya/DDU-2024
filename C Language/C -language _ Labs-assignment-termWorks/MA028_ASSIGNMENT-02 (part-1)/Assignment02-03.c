#include <stdio.h>

int main() {
    printf("Enter a line of text: ");

    
    int c,count=0;
    while ((c = getchar()) != '\n' && c != EOF) 
    {
       if(c==' ' || c=='\t' ||c== '.' ||c== ',' || c==';')
       {
        count++;      
       }
    }

   
  printf("%d",count);
    return 0;
}
