#ifndef BORROW_BOOKS_H_INCLUDED
#define BORROW_BOOKS_H_INCLUDED

void Borrow(book *books, int nr_books, char file_name[])
{
    system("cls");

    int nr_borrowed = 0, n;
    char nr[10];

    printf("\n\tHow many books would you like to borrow?\n\n\t");
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
            nr_borrowed = nr_borrowed*10 + j;
        }
    }

    if (nr_borrowed == 0) return;

    printf("\n\tType in the title, the author and the number of copies of each book you'd like to borrow, all separated by a newline:\n\n\t");

    book *borrows = malloc(sizeof(book)*nr_borrowed);

    for (int i=0; i<nr_borrowed; i++) {
        scanf(" %[^\n]s", borrows[i].title);
        printf("\t");
        scanf(" %[^\n]s", borrows[i].author);
        printf("\t");
        scanf("%d", &borrows[i].copies);
        printf("\t");
    }

    for (int i=0; i<nr_borrowed; i++) {
        int ok = 0;
        for (int j=0; j<nr_books; j++) {
            if (strcmp(books[j].title, borrows[i].title) == 0 && strcmp(books[j].author, borrows[i].author) == 0) {
                if (books[j].copies < borrows[i].copies) {
                    printf("You can only borrow %d copies of the book '%s'.\n\n", books[j].copies, books[j].title);
                    borrows[i].copies = books[j].copies;
                    books[j].copies = 0;
                }
                else {
                    books[j].copies -= borrows[i].copies;
                }
                ok = 1;
                break;
            }
        }
        if (!ok) {
            printf("\n\t'%s' by %s is not in the library.", borrows[i].title, borrows[i].author);
            for (int k=i; k<nr_borrowed-1; k++) {
                borrows[i] = borrows[i+1];
            }
            nr_borrowed--;
        }
        else printf("\n\t'%s' by %s was successfully borrowed.", borrows[i].title, borrows[i].author);
    }

    int nr_loans;
    book *loans = malloc(sizeof(book)*100);
    nr_loans = Read_from_file(loans, file_name);

    for (int i=0; i<nr_borrowed; i++) {
        int ok = 0;
        for (int j=0; j<nr_loans; j++) {
            if (strcmp(loans[j].title, borrows[i].title) == 0 && strcmp(loans[j].author, borrows[i].author) == 0) {
                ok = 1;
                loans[j].copies += borrows[i].copies;
                break;
            }
        }
        if (!ok) {
            strcpy(loans[nr_loans].title, borrows[i].title);
            strcpy(loans[nr_loans].author, borrows[i].author);
            loans[nr_loans].copies = borrows[i].copies;
            nr_loans++;
        }
    }

    Write_to_file(loans, nr_loans, file_name);

    Write_to_file(books, nr_books, "library.csv");

    Write_to_history_file(borrows, nr_borrowed, file_name);

    Yellow();
    printf("\n\tPress 0 to go back to the menu\n\n\t");
    White();
    scanf("%d", &n);

    free(loans);
    free(borrows);
}

#endif // BORROW_BOOKS_H_INCLUDED
