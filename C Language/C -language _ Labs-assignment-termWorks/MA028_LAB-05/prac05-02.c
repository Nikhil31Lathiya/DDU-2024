#include <stdio.h>

int main() {
    int s_no;
    float sales_amt,comm_rate,comm,netAmt;
    char salesman_name[30];
    char salesman_type;
   

    printf("Salesman number: ");
    // scanf(" %d", &s_no);
    // printf("Salesman name: ");
    // scanf(" %s", salesman_name);
    // printf("Sales amt: ");
    // scanf(" %f", &sales_amt);
    // printf("Salesman type (P/D/H): ");
    // scanf(" %c", &salesman_type);
    scanf("%d %s %f %c" , &s_no, &salesman_name, &sales_amt, &salesman_type);
    if (salesman_type == 'P') 
    {
        comm_rate = 0.09;  
    } 
    else if (salesman_type == 'D') 
    {
        comm_rate = 0.05;  
    } else if (salesman_type == 'H') 
    {
        comm_rate = 0.02;  
    } else 
    {
        printf("Invalid salesman type!\n");
    }

    comm = sales_amt * comm_rate;
    netAmt = sales_amt - comm;

    printf("\nSalesman report\n");
    printf("--------------------------------------------------\n");
    printf("Salesman number: %d\n", s_no);
    printf("Salesman name: %s\n", salesman_name);
    printf("Sales amt: %.2f\n", sales_amt);
    printf("comm rate: %.2f%%\n", comm_rate * 100);
    printf("comm (Rs.): %.2f\n", comm);
    printf("--------------------------------------------------\n");
    printf("Net amt: %.2f\n", netAmt);
    printf("--------------------------------------------------\n");

    return 0;
}
