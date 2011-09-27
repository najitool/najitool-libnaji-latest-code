#include "../najio.c"
#include "../naji_bmp.c"

void file2bmp(char *namein, char *nameout)
{
int a;


najin(namein);
bmpout(nameout);


while (1)
{
a = fgetc(naji_input);

if (a == EOF)
break;

fputc(a, naji_bmp_out);
}


najinclose();
bmpoutclose();
}


int main(int argc, char *argv[])
{



if (argc != 3)
{
printf("\nusage: a <input file> <output bmp file>\n\n");
return 1;
}

file2bmp(argv[1], argv[2]);


return 0;
}
