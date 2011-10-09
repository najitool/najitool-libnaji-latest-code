#include "../najio.c"

void file2oct(char *namein, char *nameout)
{
    int a;

    najin(namein);
    najout(nameout);

    while (1)
    {
        a = fgetc(naji_input);

        if (a == EOF)
            break;

        fprintf(naji_output, "%o\n", a);
    }

    najinclose();
    najoutclose();

}
