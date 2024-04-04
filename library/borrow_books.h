#ifndef BORROW_BOOKS_H_INCLUDED
#define BORROW_BOOKS_H_INCLUDED

void Borrow(book *books, int nr_books, char file_name[])
{
    system("cls");

    int nr_borrowed;
    book *borrows = malloc(sizeof(book)*100);

    printf("\n\tHow many books would you like to borrow?\n\n\t");
    scanf("%d", &nr_borrowed);
    printf("\n\tType in the title, the author and the number of copies of each book you'd like to borrow, all separated by a newline:\n\n\t");

    for (int i=0; i<nr_borrowed; i++) {
        scanf(" %[^\n]s", borrows[i].title);
        printf("\t");
        scanf(" %[^\n]s", borrows[i].author);
        printf("\t");
        scanf("%d", &borrows[i].copies);
        printf("\t");
    }

    for (int i=0; i<nr_borrowed; i++) {
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
            }
        }
    }

    Append_to_file(borrows, nr_borrowed, file_name);

    Write_to_file(books, nr_books, "library.txt");
}

#endif // BORROW_BOOKS_H_INCLUDED
