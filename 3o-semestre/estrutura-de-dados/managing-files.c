#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Creating the file
    system("type nul > new-file.txt");

    // Deleting the file
    // system("del new-file.txt");

    // Renaming the file
    system("ren new-file.txt renamed-file.txt");

    // Creating a copy of the file in another location
    system("copy renamed-file.txt 2026.01\\copy-of-renamed-file.txt");

    // Showing contents of the file
    system("cat .\\renamed-file.txt"); // cat is not being recognized by vscode
}