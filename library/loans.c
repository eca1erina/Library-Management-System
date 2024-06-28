#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void Loans(char file_name[])
{
    system("cls");

    int nr_loans, n;
    book *loans = malloc(sizeof(book)*100);

    nr_loans = Read_from_file(loans, file_name);

    for (int i=0; i<nr_loans; i++)
        printf("\t%d. '%s' by %s, %d copies\n",i, loans[i].title, loans[i].author, loans[i].copies);

    MakeTextYellow();
    printf("\n\tPress 0 to go back to the menu.\n\n\t");
    MakeTextWhite();
    scanf("%d", &n);

    free(loans);
}
