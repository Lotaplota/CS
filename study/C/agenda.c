#include <stdio.h>

char menuChoice()
{
    int choice = NULL;

    while (!choice)
    {
        printf("choose option:\n");
        printf("1. add contact");
        printf("2. remove contact");
        printf("3. print contact");
        printf("4. print all contacts");
        printf("0. exit");
    }
    

    scanf("%i", &choice);
}

char *main(void)
{
    FILE *fptr;
    fptr = fopen("contacts.txt", "r");

    char usrchoice = menuChoice();

}