#include <stdio.h>
union stud
{
    int roll;
    char gender;
    double balance;
};
int main()
{
    union stud s1;
    s1.gender = 'A';
    printf("%d \n", sizeof(s1));
    printf("%d", s1.roll);
    return 0;
}