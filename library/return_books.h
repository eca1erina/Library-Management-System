#ifndef RETURN_BOOKS_H_INCLUDED
#define RETURN_BOOKS_H_INCLUDED

void Return(book *books, int nr_books)
{
    system("cls");

    int nr_returned;
    book *returned = malloc(sizeof(book)*100);

    printf("\n\tHow many books would you like to return?\n\n\t");
    scanf("%d", &nr_returned);
    printf("\n\tType in the title, the author and the number of copies of each book you'd like to return, all separated by a newline:\n\n\t");

    for (int i=0; i<nr_returned; i++) {
        scanf(" %[^\n]s", returned[i].title);
        printf("\t");
        scanf(" %[^\n]s", returned[i].author);
        printf("\t");
        scanf("%d", &returned[i].copies);
        printf("\t");
    }

    for (int i=0; i<nr_returned; i++) {
        for (int j=0; j<nr_books; j++) {
            if (strcmp(books[j].title, returned[i].title) == 0 && strcmp(books[j].author, returned[i].author) == 0) {
                if (books[j].copies < returned[i].copies) {
                    printf("You can only borrow %d copies of the book '%s'.\n\n", books[j].copies, books[j].title);
                    returned[i].copies = books[j].copies;
                    books[j].copies = 0;
                }
                else {
                    books[j].copies += returned[i].copies;
                }
            }
        }
    }

    Write_to_file(books, nr_books, "library.txt");
}

#endif // RETURN_BOOKS_H_INCLUDED
