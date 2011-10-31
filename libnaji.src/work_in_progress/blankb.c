
void blankb(char *namein, char *nameout)
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
	fputc('\n', naji_output);

	fputc(' ', naji_output);
	}

najinclose();
najoutclose();
}
