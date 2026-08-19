// Esse eh um exemplo qualquer

int main(void)
{
    int x = 2;

    if (x > 2)
    {
        printf("eh maior\n");
    }
    else
    {
        printf("naum eh maior\n");
    }

    return 0;
}

// ---- turns into:

int main(){int x=2;if(x>2)printf("eh maior\n");else printf("naum eh maior\n");return 0;}