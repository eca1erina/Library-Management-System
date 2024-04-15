#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void White(void)
{
    printf("\033[0m");
}

void Yellow(void)
{
    printf("\033[0;33m");
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
    Yellow();
    printf("\t0. Exit\n\n\t");
    White();
}

#endif // MENU_H_INCLUDED
