#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void SearchMenu()
{
    system("cls");

    printf("\n\tHow would you like to search?\n\n");
    printf("\t1. By title\n");
    printf("\t2. By author\n");
    printf("\t3. By title and author\n\n\t");
}

void Search(book *books, int n, char file_name[]){

    char text[50];
    char text1[50];
    int option = 0, ok = 0, choice, sw = 0;

    SearchMenu();

    while (option != 1 && option != 2 && option != 3) {

    scanf("%d", &option);

    switch(option) {
    case 1:
        system("cls");
        printf("\n\tType in the title of the book you are looking for:\n\n\t");
        scanf(" %[^\n]s", text);
        system("cls");

        for (int i=0; i<n; i++) {
            if (strcmp(books[i].title,text)==0) {
                printf("\t'%s' by %s, %d copies available\n", books[i].title, books[i].author, books[i].copies);
                ok = 1;
            }
        }
        break;

    case 2:
        system("cls");
        printf("\n\tType in the name of the author you are looking for:\n\n\t");

        //checks if the name of the author doesn't contain symbols different than letters
        while (!sw) {
            scanf(" %[^\n]s", text1);
            if (is_word(text1) == 0) {
                sw = 0;
                printf("\n\tThe name of the author must contain only letters. Please try again:\n\n\t");
            }
            else sw = 1;
        }

        system("cls");

        for (int i=0; i<n; i++) {
            if (strcmp(books[i].author,text1)==0) {
                printf("\t'%s' by %s, %d copies available\n", books[i].title, books[i].author, books[i].copies);
                ok = 1;
            }
        }
        break;

    case 3:
        system("cls");
        printf("\n\tType in the title and the name of the author, separated by a newline:\n\n\t");
        scanf(" %[^\n]s", text); //reads until a newline is encountered
        printf("\t");

        //checks if the name of the author doesn't contain symbols different than letters
        while (!sw) {
            scanf(" %[^\n]s", text1);
            if (is_word(text1) == 0) {
                sw = 0;
                printf("\n\tThe name of the author must contain only letters. Please try again:\n\n\t");
            }
            else sw = 1;
        }

        system("cls");

        for (int i=0; i<n; i++) {
            if (strcmp(books[i].title, text)==0 && strcmp(books[i].author, text1)==0) {
                printf("\t'%s' by %s, %d copies available\n", books[i].title, books[i].author, books[i].copies);
                ok=1;
            }
        }
        break;

    default:
        printf("\n\tChoose one of the options by typing in the corresponding number. Try again:\n\n\t");
        break;
    }
    }

    if (!ok) {
        printf("\n\tUnfortunately, we don't have any books matching your criteria :(\n");
        MakeTextYellow();
        printf("\n\tPress 0 to go back to the menu.\n\n\t");
        MakeTextWhite();
        int n;
        scanf("%d", &n);
    }
    else {
        printf("\n\tPress 0 to go back to the menu.\n\n\t");
        MakeTextWhite();
        int n;
        scanf("%d", &n);
    }
}