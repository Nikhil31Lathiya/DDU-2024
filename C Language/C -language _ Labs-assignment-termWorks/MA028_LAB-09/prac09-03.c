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
    printf("%d", sizeof(s1));
    return 0;
}