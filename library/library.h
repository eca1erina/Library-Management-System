
typedef struct book {
    char title[51];
    char author[51];
    int copies;
} book;

int is_word(char s[]);
int exists(char fname[]);

int Read_from_file(book *books, char file_name[]);
void Write_to_file(book *books, int nr_books, char file_name[]);
void Append_to_file(book *books, int nr_books, char file_name[]);
void Write_to_history_file(book *books, int nr_books, char username[]);

void MakeTextYellow(void);
void MakeTextWhite(void);

void Menu(void);
void mainMenu(void);
void SearchMenu(void);

void Search(book *books, int n, char file_name[]);
void Return(book *books, int nr_books, char user[]);
void Borrow(book *books, int nr_books, char file_name[]);
void Loans(char file_name[]);
void Donate(book *books, int nr_books);
