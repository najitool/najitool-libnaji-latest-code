#include "../najio.c"


void maxxnewl(char *namein, char *nameout, int maxnl)
{
int a;
int putnl;

putnl = 0;

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
				{
					
					if (putnl < maxnl)
					{
					fputc(a, naji_output);
					putnl++;
					}
				
				}
				else	
				{
				fputc(a, naji_output);
		 		putnl=0;
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


	if (argc != 4)
	{
	printf("usage: a <intput> <output> <max lines>");
	return 1;
	}


maxxnewl(argv[1], argv[2], atoi(argv[3]));

}
