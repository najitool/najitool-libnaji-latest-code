/* ---------- */
/* najcrypt.c */
/* ---------- */

/* naji encryption/decryption functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */


/*
plans for najcrypt version 2.0
maybe make it just read a defined file like input.txt to output.txt
make the file bigger depending on the password size.
do something else to the encrypted byte instead of bit flipping it
such as changing certain bits instead depending on the password.
scramble the data, split/join files?

make an unlimited amount of encryption strength like 100000000 bits (hehe)
and make it user definable
*/

#include "libnaji.h"

#define MIN_PASS_LENGTH 5

void get_password(void);
void wipe_pwd(void);
void get_strength(void);
void check_ps(void);
void naji_enc(void);
void naji_dec(void);
void endnaji(int error_level);

char choice;
char letter;

char *naji_data;

char iname[256];
char oname[256];
char password[256];
char tmpusr[30];

int strength=128;
int pwd_len=0;

long ifilesize=0;

void endnaji(int error_level)
{
najinclose();
najoutclose();
wipe_pwd();
exit(error_level);
}

void get_password(void)
{
printf("\nEnter password: ");
safegets(password, 255);
printf("\n");
pwd_len = strlen(password);

if (pwd_len < MIN_PASS_LENGTH)
{
fprintf(stderr,
"\nPassword must be at least %d characters in length. Exiting program.\n\n",
MIN_PASS_LENGTH);
endnaji(10);
}

}

void wipe_pwd(void)
{
int i=0;
for (i=0; i<pwd_len; i++)
password[i] = rand() % 255;
}

void get_strength(void)
{
printf("(1)  128 Bit\n");
printf("(2)  256 Bit\n");
printf("(3)  512 Bit\n");
printf("(4) 1024 Bit\n");
printf("(5) 2048 Bit\n");

printf("Choose encryption strength: ");

safegets(tmpusr, 25);

choice = tmpusr[0];

        switch(choice)
        {
        case '1': strength=16;
        case '2': strength=32;
        case '3': strength=64;
        printf("\n\n\nSorry, only 1024 Bit and 2048 Bit encryption is available in this version.\n");
        endnaji(10);
        }

if (choice == '4') strength=128;
if (choice == '5') strength=256;

printf("\n\nThe strength of the encryption is %d Bits\n\n\n", (strength * 8));
}


void check_ps(void)
{
int a=0;

  for (a=0; a<pwd_len; a++)
  if (password[a] > strength)
  {
  fprintf(stderr, "The digit %d in the password contains a character with a value larger than %d.\n", a, strength);
  fprintf(stderr, "This is currently unsupported in this version on %d Bit encryption mode.\n", (strength * 8));
  fprintf(stderr, "Encryption failed. Exiting program.\n\n\n");
  endnaji(11);
  }

}


void naji_enc(void)
{
int a=0;
int i=0;


printf("Encrypting...\n\n");

ifilesize = najinsize();

        while (ifilesize != 0)
        {
        ifilesize--;

        letter = fgetc(naji_input);
        
        a++;

        if (a > pwd_len) a=0;
        
        for (i=0; i<strength; i++)
        naji_data[i] = rand() % 255;
                
        naji_data[(uchar)password[a]] = ~letter;

        for (i=0; i<strength; i++)
        fputc(naji_data[i], naji_output);
        }

printf("Done.\n\n");
}


void naji_dec(void)
{
int a=0;
int i=0;

printf("Decrypting...\n\n");

        loop
        {
        a++;

        if (a > pwd_len) a=0;

        for (i=0; i<strength; i++)
        naji_data[i] = fgetc(naji_input);

        naji_data[strength] = '\0';

        if (feof(naji_input))
        endloop;

        letter = ~naji_data[(uchar)password[a]];

        fputc(letter, naji_output);
        }

printf("Done.\n\n");
}


void najcrypt(void)
{
char e_d;

srand(time(NULL));

                printf("Enter input file name: ");
                safegets(iname, 255);
                printf("\n\n");
                
                najin(iname);

                printf("Enter output file name: ");
                safegets(oname, 255);
                printf("\n\n");

                if (!strcmp(iname, oname))
                {
                fprintf(stderr, "Input and output file cannot be the same!");
                exit(10);
                }

                najout(oname);

get_password();
get_strength();
check_ps();

naji_data = (char *) malloc( sizeof(char *) * strength);

printf("[E]ncrypt or [D]ecrypt or any other key to cancel: ");
safegets(tmpusr, 25); e_d = tmpusr[0];

if (e_d == 'E' || e_d == 'e') naji_enc();
if (e_d == 'D' || e_d == 'd') naji_dec();

wipe_pwd();
}

/* Bellow are seperate encryption function to the najcrypt functions. */

void qcrypt(char *namein, char *nameout)
{
int i=0;
int c;

najin(namein);
najout(nameout);

    while ( (c = getc(naji_input)) != EOF )
    putc((char) (((char) c) ^ (128 | (i++ & 127))), naji_output);

najinclose();
najoutclose();
}

void weakrypt(const char *password, char *namein, char *nameout)
{
int a;
int pwdlen;

najin(namein);
najout(nameout);

			pwdlen = strlen(password);

			while (1)
			{
			a = getc(naji_input);

			if (a == EOF)
			break;

			if (*password == '\0')
			password -= pwdlen;

			a ^= *password;

			password++;

			fputc(a, naji_output);
            }

najinclose();
najoutclose();
}
