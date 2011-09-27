#include "../najio.c"


void delxtral(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);


	while(1)
	{
	a = fgetc(naji_input);
	
	if (a == EOF)
	break;
	
		if (a == '\n')
		{
		fputc(a, naji_output);
			
			while (1)
			{
				
				a = fgetc(naji_input);

				if (a == EOF)
				break;
	
				else if (a == '\n')
				continue;
				
				else	
				{
				fputc(a, naji_output);
				break;
				}
			}	
	
		}
	
		else fputc(a, naji_output);
	
	
	}




najinclose();
najoutclose();
}




int main(int argc, char *argv[])
{


	if (argc != 3)
	{
	printf("usage: a <intput> <output>");
	return 1;
	}


delxtral(argv[1], argv[2]);



}