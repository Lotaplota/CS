#include <stdio.h>
#include "./helpers.c"

int isFinite(char * a)
{
    int i = 0;
    while(i < __INT_MAX__)
    {
        if (a[i] == '\0') { return 1; }
        i++;
    }
}

int isEmpty(char * a)
{
    return (a[0] == '\0') ? 1 : 0;
}

int isUnique(char * a)
{
    int len = lenOf(a);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] == a[j]) { return 0; }
        }
    }

    return 1;
}

int main(void)
{
    char * isIt = "lsdkjfan!";
    int finite = isFinite(isIt);
    int empty = isEmpty(isIt);
    int unique = isUnique(isIt);

    printf("The string \'%s\' %s finite, %s empty, %s unique, therefore, it is %s alphabet.\n", isIt,
        finite ? "is" : "is not",
        empty ? "is" : "is not",
        unique ? "is" : "is not",
        (finite && !empty && unique) ? "an" : "not an");
}