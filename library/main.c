#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "file_operations.h"
#include "menu.h"
#include "search_books.h"
#include "return_books.h"
#include "donate_books.h"
#include "borrow_books.h"
#include "loans.h"

int cont=10, n=10; //variables to make the menu work

int main()
{
    FILE *account;
    char first[20], last[50], t[]=".txt";
    char file_name[51];
    int nr_books = 0;
    book *books = malloc(sizeof(book)*100);
    nr_books = Read_from_file(books, "library.txt");

    printf("\n\tWelcome to our library!\n\n");

    while(cont != 0)
    {
        printf("\t1. Log in\n");
        printf("\t2. Search books\n\n");
        Galben();
        printf("\t0. Exit\n\n\t");
        Alb();
        scanf("%d", &cont);
        system("cls");

        switch(cont) {
        case 0:
            break;

        case 1:
            printf("\n\tWrite your name and surname to log in:\n\n\t");
            scanf("%s", &first);
            scanf("%s", &last);
            strcat(last, first);
            strcat(last, t);
            if (exists(last) == 0) {
                account = fopen(last, "w");
                fclose(account);
            }
            break;

        case 2:
            Search(books, nr_books, file_name);
            break;
        }

        while(n != 0 && cont != 0)
        {
            Menu();
            scanf("%d", &n);

            switch(n) {
            case 1:
                Borrow(books, nr_books, last);
                break;
            case 2:
                Return(books, nr_books);
                break;
            case 3:
                Donate(books, nr_books);
                break;
            case 4:
                Loans(last);
                break;
            case 5:
                Search(books, nr_books, last);
                break;
            case 0:
                cont=0;
                break;
            }
        }

        if(n == 0) cont=0;
    }

    free(books);

    return 0;
}
