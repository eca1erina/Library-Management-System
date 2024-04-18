#ifndef RETURN_BOOKS_H_INCLUDED
#define RETURN_BOOKS_H_INCLUDED

void Return(book *books, int nr_books, char user[])
{
    system("cls");

    int nr_returned, n;
    char nr[10];

    printf("\n\tHow many books would you like to return?\n\n\t");
    scanf("%s", &nr);

    if (is_word(nr)) {
        printf("\n\tError. The number of books must be an integer! Please try again.\n");
        Yellow();
        printf("\n\tPress 0 to go back to the menu.\n\n\t");
        scanf("%d", &n);
        White();
    }
    else {
        for (int i=0; i<strlen(nr); i++) {
            int j = nr[i] - '0';
            nr_returned = nr_returned*10 + j;
        }
    }

    if (nr_returned == 0) return;
    printf("\n\tType in the title, the author and the number of copies of each book you'd like to return, all separated by a newline:\n\n\t");

    book *returned = malloc(sizeof(book)*nr_returned);

    for (int i=0; i<nr_returned; i++) {
        scanf(" %[^\n]s", returned[i].title);
        printf("\t");
        scanf(" %[^\n]s", returned[i].author);
        printf("\t");
        scanf("%d", &returned[i].copies);
        printf("\t");
    }

    int nr_loans;
    book *loans = malloc(sizeof(book)*100);
    nr_loans = Read_from_file(loans, user);

    system("cls");

    for (int i=0; i<nr_returned; i++) {
        int ok = 0;
        for (int j=0; j<nr_loans; j++) {
            if (strcmp(loans[j].title, returned[i].title) == 0 && strcmp(loans[j].author, returned[i].author) == 0) {
                ok = 1;
                printf("\n\t'%s' by %s was successfully returned.", returned[i].title, returned[i].author);
                loans[j].copies -= returned[i].copies;
                break;
            }
        }
        if (!ok) printf("\n\tYou did not borrow '%s' by %s.", returned[i].title, returned[i].author);
    }

    for (int i=0; i<nr_returned; i++) {
        for (int j=0; j<nr_books; j++) {
            if (strcmp(books[j].title, returned[i].title) == 0 && strcmp(books[j].author, returned[i].author) == 0) {
                books[j].copies += returned[i].copies;
                break;
            }
        }
    }

    for (int i=0; i<nr_loans; i++) {
        if (loans[i].copies <= 0) {
            for (int j=i; j<nr_loans-1; j++) {
                loans[j] = loans[j+1];
            }
            nr_loans--;
        }
    }

    Write_to_file(books, nr_books, "library.csv");
    Write_to_file(loans, nr_loans, user);

    Yellow();
    printf("\n\n\tPress 0 to go back to the menu.\n\n\t");
    White();
    scanf("%d", &n);

    free(returned);
}

#endif // RETURN_BOOKS_H_INCLUDED
