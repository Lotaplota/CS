#include <stdio.h>
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

    char buffer[100];

    // Reads lines until it hits the end of the file
	// Will pass the line's content to the contact's properties
    while (fgets(&buffer, sizeof(buffer), agenda) != NULL)
    {
        CONTACT cur = contacts[count];

        sscanf(buffer,"%99[^,],%[^,],%i,%i,%i\n",
            cur.nome,
            cur.ddd,
            cur.telefone,
            &cur.nasc.dia,
            &cur.nasc.mes,
            &cur.nasc.ano); // CONTINUE
    }
    
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

    scanf(" %c", &choice);
    
    return choice;
}

void addContact(FILE *agenda)
{
    // TODO
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

void waitPrompt()
{
    int trash;
    scanf("%i", &trash);
}

char *main(void)
{
    // Opening the file
    FILE *agenda;
    agenda = fopen("contacts.txt", "r");

    // Creating a contact array to be loaded
    CONTACT contacts[100];

    // Loading contacts to contact array
    int ccount = loadContacts(&contacts, agenda);

    // Loop will break only if user chooses a valid option
    while (1)
    {
        char usrchoice = menuChoice();
        int validchoice = 1;
        
        switch (usrchoice)
        {
            case '1':
                addContact();
                break;
            case '2':
                removeContact();
                break;
            case '3':
                printContact();
                break;
            case '4':
                printAll();
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
        else
        {
            printf("invalid choice!\n");
            waitPrompt();
        }
    }
    



}