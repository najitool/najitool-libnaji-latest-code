void unblankb(char *namein, char *nameout)
{
int a;
int i=0;


najin(namein);
najout(nameout);


	while(1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;

	if (a == '\n')
	i++;

		if ((a == ' ') && (i != 0))
		{
		fputc((i-1), naji_output);
		i = 0;
		}

	}


najinclose();
najoutclose();
}
