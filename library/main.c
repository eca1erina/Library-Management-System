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
char first[20], last[50], t[]=".csv", file_name[51], login[10]="";

int main()
{
    FILE *account;
    int nr_books = 0;
    book *books = malloc(sizeof(book)*100);
    nr_books = Read_from_file(books, "library.csv");

    printf("\n\tWelcome to our library!\n\n");

    while(cont != 0)
    {
        printf("\t1. Log in\n");
        printf("\t2. Search books\n\n");
        Yellow();
        printf("\t0. Exit\n\n\t");
        White();
        do {
            scanf("%d", &cont);
            switch(cont) {
            case 0:
                break;

            case 1:
                system("cls");
                printf("\n\tWrite your name and surname in the format 'login [NAME] [SURNAME]':\n\n\t");
                int ok = 0;
                while (!ok) {
                    scanf("%s", &login);
                    scanf("%s", &first);
                    scanf("%s", &last);
                    if (is_word(first) == 0 || is_word(last) == 0)
                        printf("\n\tYou are not allowed to use numbers in your name!\n\n\t");
                    if (strcmp(login, "login") != 0)
                    printf("\n\tPlease write the word 'login' before your name and surname\n\n\t");
                    if (strcmp(login, "login") == 0 && is_word(first) == 1 && is_word(last) == 1) ok = 1;
                    strcat(last, first);
                    strcat(last, t);
                    if (exists(last) == 0 && ok) {
                        account = fopen(last, "w");
                        fclose(account);
                    }
                }
                break;

            case 2:
                Search(books, nr_books, file_name);
                break;

            default:
                printf("\n\tYou need to type in 0, 1 or 2.\n\n\t");
                break;
            }
        } while(cont != 0 && cont != 1 && cont != 2);

        while(n != 0 && cont != 0)
        {
            Menu();
            scanf("%d", &n);

            switch(n) {
            case 1:
                Borrow(books, nr_books, last);
                break;
            case 2:
                Return(books, nr_books, last);
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
