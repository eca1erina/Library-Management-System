#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void Mov(void){
printf("\033[0;35m");
}
void Tur(void){
printf("\033[0;36m");
}
void Rosu(void)
{
    printf("\033[0;31m");
}
void Alb(void)
{
    printf("\033[0m");
}
void Galben(void)
{
    printf("\033[0;33m");
}
void Blue(void)
{
    printf("\033[0;34m");
}
void Verde(void)
{
    printf("\033[0;32m");
}

void Menu(void)
{
    system("cls");
    printf("\n");
    printf("\tWhat would you like to do?\n");
    printf("\n");
    printf("\t1. Borrow books\n");
    printf("\t2. Return books\n");
    printf("\t3. Donate books\n");
    printf("\t4. View my loans\n");
    printf("\t5. Search books\n");
    printf("\n");
    Galben();
    printf("\t0. Exit\n\n\t");
    Alb();
}

#endif // MENU_H_INCLUDED
