#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void)
{
    DIR * database = opendir("../database/");
    if (!database)
    {
        perror("directory path invalid");
        return 1;
    }

    struct dirent * entry;

    int i = 0;
    while (i < 36)
    {
        entry = readdir(database);

        printf("%i. ", i);
        printf("%i\n", entry->d_namlen);
        printf("%s\n", entry->d_name);

        i++;
    }
}