#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("mkdir 2026.01");
    system("mkdir 2026.01\\pasta-1"); // I tried using cd at first, but apparently each system() command happens from the source's folder
    system("mkdir 2026.01\\pasta-2"); // makes sens if you think about it...
    system("mkdir 2026.01\\pasta-3");

    system("cd 2026.01 && dir");
    system("cd 2026.01\\pasta-1 && dir");
}