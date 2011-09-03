/* ---------- */
/* naji_bmp.c */
/* ---------- */

/* naji BMP (device independent bitmap) functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */


#include "libnaji.h"

FILE *naji_bmp_out;

#define naji_bmp_size (640 * 480)

void naji_bmpheader(void)
{
int a=0;
int i=0;

/* BM header */
fputc('B', naji_bmp_out);
fputc('M', naji_bmp_out);

/* file size */
a = ((640 * 480) + 54);
/* printf("%d\n",a); */

fputc(a, naji_bmp_out);
fputc(a >> 8, naji_bmp_out);
fputc(a >> 16, naji_bmp_out);
fputc(a >> 24, naji_bmp_out);

/* other things; which are ok to set to zero */
for (i=0; i<4; i++)
fputc(0, naji_bmp_out);

/* write the offset for the actual bmp data */
fputc(54, naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);

/* bmp file info header */
fputc(40,naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);


fputc(0x80,naji_bmp_out);
fputc(0x2,naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);


fputc(0xe0,naji_bmp_out);
fputc(0x1,naji_bmp_out);
fputc(0,naji_bmp_out);
fputc(0,naji_bmp_out);

fputc(1,naji_bmp_out);
fputc(0,naji_bmp_out);

fputc(8,naji_bmp_out);

/* other things; which are ok to set to zero */
for (i=0; i<=25; i++)
fputc(0,naji_bmp_out);

return;
}


void bmpout(char *nameout)
{

        naji_bmp_out = fopen(nameout, "wb");

        if (naji_bmp_out == NULL)
        {
        fprintf(stderr, "Error making file %s\n", nameout);
        exit(1);
        }

        naji_bmpheader();
        printf("%s\n", nameout);

}

void bmpoutclose(void)
{
fclose(naji_bmp_out);
}


void naji_bmp(void)
{
int a;
int b;
int c;

/*
int d;
int e;
int f;
int g;
int h;
*/

int i;
int x;

/*
int y;
char filename[100];
*/

        srand(time(NULL));

        bmpout("rndpixel.bmp");
        for (i=0; i<=3000000; i++)
        {
        a = rand() % 255;
        fputc(a, naji_bmp_out);
        }
        bmpoutclose();

        bmpout("matches.bmp");
        for (a=0; a<1000; a++)
        for (b=0; b<1000; b++)
        fputc(a+b, naji_bmp_out);
        bmpoutclose();


        bmpout("lightnin.bmp");
        for (a=0; a<150; a++)
        for (b=0; b<150; b++)
        for (c=0; c<150; c++)
        fputc(a+b-c, naji_bmp_out);
        bmpoutclose();

        bmpout("marble.bmp");
        for (a=0; a<150; a++)
        for (b=0; b<130; b++)
        for (c=0; c<120; c++)
        fputc(a-b+c, naji_bmp_out);
        bmpoutclose();

        bmpout("metal.bmp");
        for (a=0; a<150; a++)
        for (b=0; b<130; b++)
        for (c=0; c<120; c++)
        fputc(a+b+c, naji_bmp_out);
        bmpoutclose();

        bmpout("roads.bmp");
        for (a=0; a<50; a++)
        for (b=0; b<110; b++)
        for (c=0; c<112; c++)
        fputc(a-b+c, naji_bmp_out);
        bmpoutclose();

        bmpout("rinoskin.bmp");
        for (a=1; a<100; a++)
        for (b=1; b<100; b++)
        for (c=1; c<100; c++)
        {
        fputc(a*b+c, naji_bmp_out);
        }
        bmpoutclose();


        bmpout("waves.bmp");
        for (a=10; a<100; a++)
        for (b=10; b<100; b++)
        for (c=10; c<100; c++)
        {
        fputc(cos(a)+b+c*PI, naji_bmp_out);
        }
        bmpoutclose();


        bmpout("waves2.bmp");
        for (a=10; a<100; a++)
        for (b=10; b<100; b++)
        for (c=10; c<100; c++)
        {
        fputc(tan(a)+b+c*PI, naji_bmp_out);
        }
        bmpoutclose();


        bmpout("zigzag.bmp");
        for (a=10; a<100; a++)
        for (b=10; b<100; b++)
        for (c=10; c<100; c++)
        {
        fputc(cos(a)+b-c*PI, naji_bmp_out);
        }
        bmpoutclose();





        bmpout("rustneed.bmp");
        c=0;
        for (a=0; a<50000; a++)
        {
        for (b=0; b<8; b++)
        fputc(c, naji_bmp_out);

        c++;
        }
        bmpoutclose();



        bmpout("needle2.bmp");
        c=0;
        for (a=0; a<50000; a++)
        {
        for (b=0; b<=8; b++)
        fputc(c, naji_bmp_out);

        c++;
        }
        bmpoutclose();


        bmpout("needle.bmp");
        c=0;
        for (a=0; a<60000; a++)
        {
        for (b=0; b<6; b++)
        fputc(c, naji_bmp_out);

        c++;
        }
        bmpoutclose();


        bmpout("nice1.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(b, naji_bmp_out);

        for (i=0; i<8; i++)
        fputc(a, naji_bmp_out);

        b++;
        }
        bmpoutclose();




        bmpout("nice2.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(b, naji_bmp_out);
        fputc(b, naji_bmp_out);

        for (i=0; i<7; i++)
        fputc(a, naji_bmp_out);

        b++;
        }
        bmpoutclose();



        bmpout("nice3.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        for (i=0; i<7; i++)
        fputc(a, naji_bmp_out);

        b++;
        }
        bmpoutclose();




        bmpout("nice4.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        for (i=0; i<4; i++)
        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        fputc(a, naji_bmp_out);
        fputc(a, naji_bmp_out);

        b++;
        }
        bmpoutclose();



        bmpout("nice5.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        fputc(a, naji_bmp_out);
        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        fputc(a, naji_bmp_out);
        fputc(a, naji_bmp_out);


        b++;
        }
        bmpoutclose();



        bmpout("blueblak.bmp");
        b=255;
        for (x=0; x<=200; x++)
        for (a=0; a<=255; a++)
        {


        for (i=0; i<7; i++)
        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        b--;
        }
        bmpoutclose();


        bmpout("pinkwite.bmp");
        b=0;
        for (x=0; x<=200; x++)
        for (a=255; a>=0; a--)
        {

        fputc(b, naji_bmp_out);

        for (i=0; i<7; i++)
        fputc(a, naji_bmp_out);

        b++;
        }
        bmpoutclose();


        bmpout("cyanblak.bmp");
        b=255;
        for (x=0; x<=200; x++)
        for (a=0; a<=255; a++)
        {


        fputc(b, naji_bmp_out);

        for (i=0; i<6; i++)
        fputc(a, naji_bmp_out);

        fputc(b, naji_bmp_out);

        b--;
        }
        bmpoutclose();



        bmpout("erfquake.bmp");
        c=0;
        for (a=0; a<120000; a++)
        {
        for (b=0; b<3; b++)
        fputc(c, naji_bmp_out);

        c++;
        }
        bmpoutclose();


        bmpout("carpet1.bmp");
        for (a=0; a<5000; a++)
        {
        fputc(0,  naji_bmp_out);
        fputc(75, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(75, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(37, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(150,naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(18, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(44, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(9,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(88, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(4,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(176,naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(2,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(96, naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(1,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(192,naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(0,  naji_bmp_out);
        fputc(128,naji_bmp_out);

        for (i=0; i<96; i++)
        fputc(0,  naji_bmp_out);

        }
        bmpoutclose();

        bmpout("pipes.bmp");
        for (i=0; i<=3000000; i++)
        {
        fputc(i, naji_bmp_out);
        }
        bmpoutclose();



        bmpout("diagpipe.bmp");
        for (i=0; i<=255; i++)
        {


        for (a=0; a<=255; a++)
        for (b=0; b<=255; b++)
        fputc(a+b, naji_bmp_out);
        }
        bmpoutclose();


        bmpout("coolgren.bmp");
        for (i=0; i<=1500000; i++)
        {
        fputc(i, naji_bmp_out);
        fputc(0, naji_bmp_out);
        }
        bmpoutclose();

        bmpout("lines1.bmp");
        for (i=0; i<=1500000; i++)
        {
        fputc(i, naji_bmp_out);

        for (a=0; a<=3; a++)
        fputc(a, naji_bmp_out);

        }
        bmpoutclose();



        bmpout("rainbow.bmp");
        for (i=0; i<=150000; i++)
        {


	for (a=0; a<=255; a++)
	fputc(((a*a)*PI), naji_bmp_out);

        }
        bmpoutclose();



        bmpout("fuzypipe.bmp");
        for (i=0; i<=150000; i++)
        {


	for (a=0; a<=255; a++)
	fputc((a*PI), naji_bmp_out);

        }
        bmpoutclose();



        bmpout("rdpplpnk.bmp");
	for (i=0; i<20; i++)
	{

	for (a=0; a<=255; a++)
	for (b=0; b<=255; b++)
	{
	fputc(((a*a)*PI), naji_bmp_out);
	fputc(((b*b)*PI), naji_bmp_out);
	}

	}
        bmpoutclose();







        /*
        for (i=0; i<256; i++)
        {

        sprintf(filename, "%03d.bmp", i);
        bmpout(filename);

        for (a=0; a<3000000; a++)
        fputc(i, naji_bmp_out);


        bmpoutclose();
        }
        */


}
