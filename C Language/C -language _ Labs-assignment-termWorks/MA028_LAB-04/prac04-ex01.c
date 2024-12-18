#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter Co-ordinates : ");
    scanf("%d %d",&x,&y);
    if (x>0 && y>0)
    {
        printf("First Quadrant");
    }
    else if(x<0 && y>0)
    {
        printf("Second Quadrant");
    }
    else if(x<0 && y<0)
    {
        printf("Third Quadrant");
    }
    else if(x>0 && y<0)
    {
        printf("Fourth Quadrant");
    }
    else
    {
        printf("0 0");
    }
    return 0;
}