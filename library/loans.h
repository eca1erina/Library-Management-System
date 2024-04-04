#ifndef LOANS_H_INCLUDED
#define LOANS_H_INCLUDED

void Loans(char file_name[])
{
    system("cls");
    int nr_loans, n;
    book *loans = malloc(sizeof(book)*100);
    nr_loans = Read_from_file(loans, file_name);
    for (int i=0; i<nr_loans; i++)
        printf("\t%d. '%s' by %s, %d copies\n",i, loans[i].title, loans[i].author, loans[i].copies);
    printf("\n\tPress 0 to go back to menu.\n\n\t");
    scanf("%d", &n);
    free(loans);
}

#endif // LOANS_H_INCLUDED
