#include <stdio.h>
struct booktemplate
{
    int code;
    char name[150];
    float price;
    int stock;
};

int main()
{
    FILE *file_ptr;
    int choise;
    while (1)
    {
        printf("Enter Choise : \n1 -> To Add New Book.\n2 -> Display All Books.\n3 -> Search Particular Book.\n0 -> Exit.\n");
        scanf("%d", &choise);
        if (choise == 0)
        {
            break;
        }

        // insert single record into file
        else if (choise == 1)
        {
            file_ptr = fopen("book_records.txt", "a");
            struct booktemplate book;
            printf("Enter Book Code : ");
            scanf("%d", &book.code);
            printf("Enter Book Name : ");
            getchar();
            fgets(book.name, sizeof(book.name), stdin);
            printf("Enter Price : ");
            scanf("%f", &book.price);
            printf("Enter Total Stock : ");
            scanf("%d", &book.stock);

            fprintf(file_ptr, "Code : %d\n", book.code);
            fprintf(file_ptr, "Name : %s", book.name);
            fprintf(file_ptr, "Price : %f\n", book.price);
            fprintf(file_ptr, "Stock : %d\n\n", book.stock);
            fclose(file_ptr);
        }

        // display all contents of the file
        else if (choise == 2)
        {
            file_ptr = fopen("book_records.txt", "r");
            char ch;
            while (!feof(file_ptr))
            {
                ch = fgetc(file_ptr);
                printf("%c", ch);
            }
        }

        // display particular record from the file

        else if (choise == 3)
        {
            int code, found = 0;
            char ch;
            struct booktemplate book;
            printf("Enter Book Code : ");
            scanf("%d", &code);
        }
    }
    return 0;
}