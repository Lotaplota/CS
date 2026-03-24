#include <stdio.h>
#include <stdlib.h>

int find(int * vector, size_t size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (vector[i] == target)
            return i;
    }

    return -1;
}

int main(void)
{
    int numbers[] =
    {
        14, 29, 37, 11, 43, 25, 19, 32, 16, 22,
        40, 13, 28, 35, 10, 45, 20, 38, 17, 24,
        30, 41, 15, 27, 33, 18, 26, 39, 12, 2
    };

    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 16;

    int pos = find(numbers, size, target);

    printf("ce queria o numero %i?", numbers[pos]);
}