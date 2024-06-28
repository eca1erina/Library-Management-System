#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int is_word(char s[])
{
    for (int i=0; i<strlen(s); i++) {
        if (isalpha(s[i]) == 0 && s[i] != ' ') return 0;
    }
    return 1;
}

int exists(char fname[])
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int Read_from_file(book *books, char file_name[]){

    FILE *library;
    library = fopen(file_name, "r");
    if (library == NULL) {
        printf("Error opening file.\n");
    }

    int read = 0, records = 0;

    do {

        read = fscanf(library, //the function fscanf returns the number of records read
                      "%49[^,],%49[^,],%d\n", //reads up to 49 characters until a comma is encountered
                      books[records].title,
                      books[records].author,
                      &books[records].copies);

        if (read == 3) records++;
        else if (!feof(library)) {
            printf("File format incorrect.\n");
            break;
        }

    } while(!feof(library));

    fclose(library);

    return records;
}

void Write_to_file(book *books, int nr_books, char file_name[])
{
    FILE *file;

    file = fopen(file_name, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
    }

    for (int i=0; i<nr_books; i++) {
        fprintf(file,"%s,%s,%d\n",
                books[i].title,
                books[i].author,
                books[i].copies);
    }
    fclose(file);
}

void Append_to_file(book *books, int nr_books, char file_name[])
{
    FILE* file = fopen(file_name, "a+");

    if (!file) {
        printf("Can't open file\n");
    }

    for (int i=0; i<nr_books; i++) {
        fprintf(file, "%s,%s,%d\n",
                books[i].title,
                books[i].author,
                books[i].copies);
    }

    fclose(file);
}

void Write_to_history_file(book *books, int nr_books, char username[])
{
    FILE* file = fopen("history.csv", "a+");

    if (!file) {
        printf("Can't open file\n");
    }

    char user[50] = "";

    for (int i=0; i<strlen(username)-4; i++) {
        user[i] = username[i];
    }

    for (int i=0; i<nr_books; i++) {
        fprintf(file, "%s,%s,%s,%d\n",
                user,
                books[i].title,
                books[i].author,
                books[i].copies);
    }

    fclose(file);
}