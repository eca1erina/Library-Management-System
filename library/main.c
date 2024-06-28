#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int cont=10, n=10; //variables to make the menu work
char first[20], last[50], t[]=".csv", file_name[51], login[10]="";

int main(int argc, char* argv[])
{
    FILE *account;
    int nr_books = 0;
    book *books = malloc(sizeof(book)*100);
    nr_books = Read_from_file(books, "library.csv");

    if (argc != 4) mainMenu();

    else {
        int ok=0;
        strcpy(login, argv[1]);
        strcpy(first, argv[2]);
        strcpy(last, argv[3]);
        if (is_word(first) == 0 || is_word(last) == 0) {
            printf("\n\tYour name must contain only letters! Please try again: \n\n\t");
            return 1;
        }
        if (strcmp(login, "login") != 0) {
            printf("\n\tPlease write the word 'login' before your name and surname\n\n\t");
            return 1;
        }

        if (strcmp(login, "login") == 0 && is_word(first) == 1 && is_word(last) == 1) ok = 1;
        strcat(last, first);
        strcat(last, t);
        if (exists(last) == 0 && ok) {
            account = fopen(last, "w");
            fclose(account);
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
                Return(books, nr_books, last);
                break;
            case 3:
                Donate(books, nr_books);
                nr_books = Read_from_file(books, "library.csv");
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
    }

    return 0;
}