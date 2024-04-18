#ifndef SEARCH_BOOKS_H_INCLUDED
#define SEARCH_BOOKS_H_INCLUDED

void Search(book *books, int n, char file_name[]){

    char text[50];
    char text1[50];
    int option = 0, ok = 0, choice, sw = 0;

    system("cls");

    printf("\n\tHow would you like to search?\n\n");
    printf("\t1. By title\n");
    printf("\t2. By author\n");
    printf("\t3. By title and author\n\n\t");

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
            if (strcmp(books[i].author,text)==0) {
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
        printf("\n\tUnfortunately, we don't have any books by this author :(\n");
        Yellow();
        printf("\n\tPress 0 to go back to the menu.\n\n\t");
        White();
        int n;
        scanf("%d", &n);
    }
    else {
        printf("\n\tWould you like to borrow any of these books?\n\t");
        printf("1. Yes\n\t");
        printf("2. No\n\n\t");

        while (choice != 1 && choice != 2) {
            scanf("%d", &choice);

            switch(choice) {

            case 1:
                Borrow(books, n, file_name);
                break;

            case 2:
                break;

            default:
                printf("\n\tChoose one of the options by typing in the corresponding number. Try again:\n\n\t");
                break;
            }
        }
    }
}

#endif // SEARCH_BOOKS_H_INCLUDED
