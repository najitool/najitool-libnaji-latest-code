
void blankc(char *namein, char *nameout, char ch1, char ch2)
{
int a;
int i;

najin(namein);
najout(nameout);

	while(1)
	{
	a = fgetc(naji_input);

	if (a == EOF)
	break;

	for (i=0; i<=a; i++)
	fputc(ch1, naji_output);

	fputc(ch2, naji_output);
	}

najinclose();
najoutclose();
}
