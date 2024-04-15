#ifndef SEARCH_BOOKS_H_INCLUDED
#define SEARCH_BOOKS_H_INCLUDED

void Search(book *books, int n, char file_name[]){

    char text[50];
    char text1[50];
    int option=0, ok=0, choice;

    system("cls");

    printf("\n\tHow would you like to search?\n\n");
    printf("\t1. By title\n");
    printf("\t2. By author\n");
    printf("\t3. By title and author\n\n\t");
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
                ok=1;
            }
        }
        break;

    case 2:
        system("cls");
        printf("\n\tType in the name of the author you are looking for:\n\n\t");
        scanf(" %[^\n]s", text);
        system("cls");

        for (int i=0; i<n; i++) {
            if (strcmp(books[i].author,text)==0) {
                printf("\t'%s' by %s, %d copies available\n", books[i].title, books[i].author, books[i].copies);
                ok=1;
            }
        }
        break;

    case 3:
        system("cls");
        printf("\n\tType in the title and the name of the author, separated by a newline:\n\n\t");
        scanf(" %[^\n]s", text); //reads until a newline is encountered
        printf("\t");
        scanf(" %[^\n]s", text1);
        system("cls");

        for (int i=0; i<n; i++) {
            if (strcmp(books[i].title, text)==0 && strcmp(books[i].author, text1)==0) {
                printf("\t'%s' by %s, %d copies available\n", books[i].title, books[i].author, books[i].copies);
                ok=1;
            }
        }
        break;

    default:
        printf("Error");
        break;
    }

    if (!ok) {
            printf("\n\tUnfortunately, we don't have any books by this author :(\n");
            printf("\n\tWould you like to search again or log in?\n");
            printf("\n\t1. Log in\n");
            printf("\n\t2. Search books\n\n\t");
            scanf("%d", &choice);

            switch(choice)
            {
            case 1:
                system("cls");

                if (exists(file_name) == 0) {
                    FILE *account;
                    char first[20], last[50], t[]=".csv";
                    printf("\n\tWrite your name and surname to log in:\n\n\t");
                    scanf("%s", &first);
                    scanf("%s", &last);
                    strcat(last, first);
                    strcat(last, t);
                    if (exists(last) == 0) {
                        account = fopen(last, "w");
                        fclose(account);
                    }
                    strcpy(file_name, last);
                }
                break;
            case 2:
                Search(books, n, file_name);
                break;
            }
    }
    else {
        printf("\n\tWould you like to borrow any of these books?\n\t");
        printf("1. Yes\n\t");
        printf("2. No\n\n\t");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            if (exists(file_name) == 0) {
                FILE *account;
                char first[20], last[50], t[]=".csv";
                printf("\n\tWrite your name and surname to log in:\n\n\t");
                scanf("%s", &first);
                scanf("%s", &last);
                strcat(last, first);
                strcat(last, t);

                if (exists(last) == 0) {
                    account = fopen(last, "w");
                    fclose(account);
                }
                strcpy(file_name, last);
            }
            Borrow(books, n, file_name);
            break;
        case 2:
            system("cls");
            printf("\n\tWould you like to search again or log in?\n");
            printf("\n\t1. Log in\n");
            printf("\n\t2. Search books\n\n\t");
            scanf("%d", &choice);

            switch(choice)
            {
            case 1:
                system("cls");

                if (exists(file_name) == 0) {
                    FILE *account;
                    char first[20], last[50], t[]=".csv";
                    printf("\n\tWrite your name and surname to log in:\n\n\t");
                    scanf("%s", &first);
                    scanf("%s", &last);
                    strcat(last, first);
                    strcat(last, t);
                    if (exists(last) == 0) {
                        account = fopen(last, "w");
                        fclose(account);
                    }
                    strcpy(file_name, last);
                }
                break;
            case 2:
                Search(books, n, file_name);
                break;
            }
            break;
        }
    }
}

#endif // SEARCH_BOOKS_H_INCLUDED
