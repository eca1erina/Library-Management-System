#ifndef DONATE_BOOKS_H_INCLUDED
#define DONATE_BOOKS_H_INCLUDED

void Donate(book *books, int nr_books)
{
    system("cls");

    int nr_donated, n;
    char nr[10];

    printf("\n\tHow many books would you like to donate?\n\n\t");
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
            nr_donated = nr_donated*10 + j;
        }
    }

    if (nr_donated == 0) return;
    printf("\n\tType in the title, the author and the number of copies of each book you'd like to donate, all separated by a newline:\n\n\t");

    book *donated = malloc(sizeof(book)*nr_donated);

    for (int i=0; i<nr_donated; i++) {
        scanf(" %[^\n]s", donated[i].title);
        printf("\t");
        scanf(" %[^\n]s", donated[i].author);
        printf("\t");
        scanf("%d", &donated[i].copies);
        printf("\t");
    }

    for (int i=0; i<nr_donated; i++) {
        int ok=0;
        for (int j=0; j<nr_books; j++) {
            if (strcmp(books[j].title, donated[i].title) == 0 && strcmp(books[j].author, donated[i].author) == 0) {
                books[j].copies += donated[i].copies;
                ok=1;
            }
        }
        if (!ok) {
            strcpy(books[nr_books].title, donated[i].title);
            strcpy(books[nr_books].author, donated[i].author);
            books[nr_books].copies = donated[i].copies;
            nr_books++;
        }
    }

    Write_to_file(books, nr_books, "library.csv");

    free(donated);
}

#endif // DONATE_BOOKS_H_INCLUDED
