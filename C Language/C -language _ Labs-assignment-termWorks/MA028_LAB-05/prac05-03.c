#include <stdio.h>

int main() {
    float h;

    printf("Enter the height in centimeters: ");
    scanf("%f", &h);

    if(h<240 && h>60)
    {
        if (h < 121) 
        {
            printf("The person is Low in Height\n");
        } 
        else if (h >= 121 && h <= 160)
         {
            printf("The person is Average in Height\n");
         } 
         else 
         {
            printf("The person is Tall in Height\n");
         }
    }
    else 
    {
        printf("Plese enter valid hight in cm \n");
    }

    return 0;
}
