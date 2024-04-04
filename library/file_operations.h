#ifndef FILE_OPERATIONS_H_INCLUDED
#define FILE_OPERATIONS_H_INCLUDED

typedef struct book {
    char title[51];
    char author[51];
    int copies;
} book;

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

#endif // FILE_OPERATIONS_H_INCLUDED
