#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define PATH "contacts.txt"

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct
{
    char nome[100];
    char ddd[3];
    char telefone[10];
    DATA nasc;
} CONTACT;

// Loads the contacts to a CONTACT array
int loadContacts(CONTACT contacts[], FILE *agenda)
{
    // Amount of contacts in file
    int count = 0;

    FILE *fileptr = fopen(PATH, "r");
    if (fileptr == NULL)
    {
        return count;
    }

    char buffer[1000];

    // Reads lines until it hits the end of the file
	// Will pass the line's content to the contact's properties
    while (fgets(buffer, sizeof(buffer), fileptr) != NULL)
    {
        CONTACT cur = contacts[count];
        printf("%s\n", buffer);
        sscanf(buffer,"%99[^,],%[^,],%[^,],%d/%d/%d\n",
            contacts[count].nome,
            contacts[count].ddd,
            contacts[count].telefone,
            &contacts[count].nasc.dia,
            &contacts[count].nasc.mes,
            &contacts[count].nasc.ano);
        
        count++;
    }

    fclose(fileptr);

    return count;
}

// Presents a menu then returns the char that the user chooses
char menuChoice()
{
    system("cls");

    char choice = '0';

    printf("- MENU -\n");
    printf("1. add contact\n");
    printf("2. remove contact\n");
    printf("3. print contact\n");
    printf("4. print all contacts\n");
    printf("0. exit\n");

    printf("\nchoose an option: ");

    char usrinput[4]; // I won't risk setting this array to be any lower...

    fgets(usrinput, sizeof(usrinput), stdin);
    fflush(stdin);
    
    choice = usrinput[0];
    return choice;
}

void addContact(CONTACT *list, int *place)
{
    CONTACT newc;

    // Getting the contact's name
    char cname[100];
    printf("enter the contact's name: ");
    fgets(cname, sizeof(cname), stdin);
    strcpy(newc.nome, cname);

    // Getting the contact's DDD
    char cddd[3];
    printf("enter the contact's DDD: ");
    fgets(cddd, sizeof(cddd), stdin);
    strcpy(newc.ddd, cddd);
    printf("cddd: %s\n", newc.ddd); // DONKEY CONTINUE maybe do the safe way of storing a null terminated array...

    char phone[9];
    int cbirthday;
    int birthmonth;
    int birthyear;

}

void removeContact(FILE *agenda)
{
    // TODO
}
void printContact(FILE *agenda)
{
    // TODO
}
void printAll(FILE *agenda)
{
    // TODO
}
void exitProgram()
{
    // TODO
}

char *main(void)
{
    // Opening the file
    FILE *agendaptr;
    agendaptr = fopen("contacts.txt", "r");

    // Creating a contact array to be loaded
    CONTACT contacts[100];

    // Loading contacts to contact array
    int ccount = loadContacts(contacts, agendaptr);

    // Loop will break only if user chooses a valid option
    while (1)
    {
        char usrchoice = menuChoice();
        int validchoice = 1;
        
        switch (usrchoice)
        {
            case '1':
                addContact(contacts, &ccount);
                break;
            case '2':
                // removeContact();
                break;
            case '3':
                // printContact();
                break;
            case '4':
                // printAll();
                break;
            case '0':
                exitProgram();
                break;
            
            default:
                validchoice = 0;
                break;
        }

        if (validchoice)
        {
            break;
        }
    }
}