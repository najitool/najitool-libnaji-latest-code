void unblankc(char *namein, char *nameout, char ch1, char ch2)
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

	if (a == ch1)
	i++;

		if ((a == ch2) && (i != 0))
		{
		fputc((i-1), naji_output);
		i = 0;
		}

	}


najinclose();
najoutclose();
}
