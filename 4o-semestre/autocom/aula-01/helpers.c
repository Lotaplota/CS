int lenOf(char * a)
{
    int i = 0;
    
    while (a[i] != '\0') i++;

    return i;
}

char lowerize(char c)
{
    if (c > 64 && c < 91) return c + 32;
    else return c;
}