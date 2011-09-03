/* ---------- */
/* najitool.c */
/* ---------- */

/* najitool main module */

/* this  .c  is a part of */
/* najitool version 0.8.4 */

/* from najitool version 0.2.0 and */
/* above najitool will use libnaji */
/* this version uses libnaji 0.6.4 */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "najitool.h"


/* ------------------- */
/* Program Exit Values */
/* ------------------- */

/* 0 - Program exited normally.
 * 1 - Too many or too few parameters.
 * 2 - Error opening input file.
 * 3 - Ouput file already exists.
 * 4 - Error opening output file.
 * 5 - Error opening second input file.
 * 6 - Error opening edit file.
 * 7 - Unknown command.
 * 8 - Help error.
 * 9 - Memory allocation error.
 */


unsigned long int naji_max_unsigned_long_int = 0;





const char * najitool_valid_commands[NAJITOOL_MAX_COMMANDS] = {
"8bit256",
"addim",
"addline",
"allbmp16",
"allfiles",
"arab2eng",
"asc2ebc",
"asctable",
"ay",
"ayinkaci",
"bigascif",
"bigascii",
"bin2c",
"bin2hexi",
"bin2text",
"blanka",
"bremline",
"bugun",
"bytsplit",
"calc",
"cat_head",
"cat_tail",
"cat_text",
"catrandl",
"ccompare",
"cfind",
"cfindi",
"charaftr",
"charbefr",
"charfile",
"charsort",
"charwrap",
"chchar",
"chchars",
"chstr",
"coffset",
"compare",
"copyfile",
"copyoffs",
"copyself",
"cpfroml",
"cptiline",
"credits",
"database",
"datetime",
"dayofmon",
"dos2unix",
"downlist",
"dumpoffs",
"e2ahtml",
"ebc2asc",
"eng2arab",
"engnum",
"eremline",
"f2lower",
"f2upper",
"filbreed",
"file2bin",
"file2dec",
"file2hex",
"filechop",
"filejoin",
"fillfile",
"find",
"findi",
"flipcopy",
"freverse",
"fswpcase",
"ftothe",
"gbsplit",
"gdivide",
"genhelp",
"genlic",
"getlinks",
"gigabyte",
"gminus",
"gplus",
"gtimes",
"help",
"hexicat",
"hilist",
"hmaker",
"hmakerf",
"howline",
"html2txt",
"html_db",
"htmlfast",
"htmlhelp",
"istrael",
"istreml",
"kbsplit",
"kitten",
"lcharvar",
"lcvfiles",
"leetfile",
"leetstr",
"length",
"lensortl",
"lensorts",
"license",
"lineback",
"linesnip",
"listdigt",
"listlowr",
"listprnt",
"listuppr",
"longline",
"makarray",
"mathgame",
"mbsplit",
"mergline",
"mjoin",
"mkpatch",
"month",
"mp3split",
"mp3taged",
"mp3tagnf",
"n2ch",
"n2str",
"najcrypt",
"naji_bmp",
"najirle",
"najisum",
"numlines",
"onlalnum",
"onlalpha",
"onlcntrl",
"onldigit",
"onlgraph",
"onllower",
"onlprint",
"onlpunct",
"onlspace",
"onlupper",
"onlxdigt",
"onlycat",
"onlychar",
"patch",
"printftx",
"putlines",
"qcrypt",
"qpatch",
"randkill",
"rbcafter",
"rbcbefor",
"rcharvar",
"rcvfiles",
"remline",
"removel",
"repcat",
"repcatpp",
"repchar",
"repcharp",
"replacel",
"revcat",
"revlines",
"rmunihtm",
"rndbfile",
"rndbsout",
"rndffill",
"rndlines",
"rndtfile",
"rndtsout",
"rrrchars",
"rstrach",
"rstrbch",
"rtcafter",
"rtcbefor",
"saat",
"saatarih",
"showline",
"skipcat",
"skipchar",
"skipstr",
"skpalnum",
"skpalpha",
"skpcntrl",
"skpdigit",
"skpgraph",
"skplower",
"skpprint",
"skppunct",
"skpspace",
"skpupper",
"skpxdigt",
"sort",
"sortlast",
"sp2ce2sp",
"sp2re2sp",
"spyramid",
"strachar",
"strbchar",
"strbline",
"streline",
"strfile",
"swapfeb",
"systemdt",
"tabspace",
"telltime",
"today",
"tothe",
"ttt",
"turnum",
"txt2html",
"unajirle",
"unblanka",
"unihtml",
"unix2dos",
"uudecode",
"uuencode",
"vowelwrd",
"weakrypt",
"wordline",
"wordwrap",
"wrdcount",
"year",
"yil",
"zerokill",
};

void forhelp(void)
{

    printf("\n");
    printf("  For a list of najitool commands type the following:\n\n");

    printf("    najitool help commands\n\n");

    printf("  And to get detailed information on a particular command\n");
    printf("  for example the command bin2c type the following:\n");
    printf("\n");
    printf("    najitool help bin2c\n\n");

}


void najitool_check_command(char *cmd)
{
int i;


 for (i=0; i<NAJITOOL_MAX_COMMANDS; i++)
 {

  if (!strcmp(cmd, najitool_valid_commands[i]))
  {
#ifdef NAJI_DEBUG
 fprintf(stderr, "\n\nNAJI_DEBUG - VALID COMMAND: %s\n\n", cmd);
 fgetc(stdin);
#endif
  return;
  }

 }

fprintf(stderr, "\nError, unknown command: %s\n\n", cmd);
forhelp();

exit(7);
}




void naji_stdin_msg(void)
{
    fprintf(stderr, "\nTaking input from standard input,\n");
    fprintf(stderr, "usually keyboard.\n\n");
    fprintf(stderr, "On most systems you can quit with\n");
    fprintf(stderr, "pressing Ctrl and C at the same time.\n");
}


void tooparam(char *cmd)
{
fprintf(stderr, "\n\n%s: too many parameters.\n", cmd);
najitool_command_help(cmd);
exit(1);
}


void notparam(char *cmd)
{
fprintf(stderr, "\n\n%s: not enough parameters.\n", cmd);
najitool_command_help(cmd);
exit(1);
}


#define begin_cmd(nt_cmd, minargs)\
if (!strcmp(argv[1], nt_cmd))\
{\
if (argc > minargs)\
tooparam(nt_cmd);\
if (argc < minargs)\
notparam(nt_cmd);\
if (argc == minargs) {

#define end_cmd() } return 0; }


int main(int argc, char *argv[])
{
unsigned int repeat=0;
char **tags;
int i;
int a;
int b;
float gdivide_a;
float gdivide_b;


char are_you_sure[100];

#ifdef NAJI_DEBUG

 fprintf(stderr, "\n\n");
 fprintf(stderr, "NAJI_DEBUG - check if two commands are displayed as one joined string,\n");
 fprintf(stderr, "             you might have missed a , in najitool_valid_commands[]\n\n");

 for (i=0; i<NAJITOOL_MAX_COMMANDS; i++)               
 fprintf(stderr, "%s ", najitool_valid_commands[i]);
 fgetc(stdin);

#endif /* NAJI_DEBUG */



#ifdef NAJI_DEBUG
    fprintf(stderr, "\n\nNAJI_DEBUG - YOUR PARAMETERS/ARGUMENTS:\n\n");
    
    for (i=0; i<argc; i++)
    fprintf(stderr, "%s ", argv[i]);
    
    fprintf(stderr, "\n\n");

    fgetc(stdin);
#endif /* NAJI_DEBUG */



    if (argc >= 2)
    {
    tolowers(argv[1]);
    najitool_check_command(argv[1]);
    }


    if (argc == 1)
    {
    printf("\n\n");


/*
printf("           __    |         \n");
printf("          /  \\   |        \n");
printf("     /   _____|  | o \\    \n");
printf("    |    \\  o    |___|    \n");
printf("     \\____\\              \n");
printf("      o o    T O O L       \n");
*/


printf("           __    |          ********************************************\n");
printf("          /  \\   |               najitool 0.8.4 using libnaji 0.6.4     \n");
printf("     /   _____|  | o \\            both written by NECDET COKYAZICI      \n");
printf("    |    \\  o    |___|                   and contributors              \n");
printf("     \\____\\                 ********************************************\n");
printf("      o o    T O O L         No warranty, to view the license type:     \n");
printf("                                         najitool license               \n");
printf("  http://najitool.sf.net/   ********************************************\n");
printf("                             To view the credits type: najitool credits \n");
printf("  Public Domain, 2003-2011  ********************************************\n");
printf("\n");


forhelp();


    return 0;
    }



    if (argc >= 2)
    {


        if (!strcmp(argv[1], "mp3taged"))
        {

            if ((argc % 2 != 1) | (argc == 3))
            {
            printf("mp3taged: too few arguments '%s'\n", argv[1]);
            return 1;
            }

            /*
             * we save the tags' options:
             * tags[i] = <tag name>
             * tags[i+1] = <user content>
             * ..
             */

            tags = (char**) malloc (sizeof(char*)*(argc-3)*2);

            for (i=0; i<(argc-3)*2; i+=2)
            tags[i] = (char*) malloc(7*sizeof(char));

            for (i=1; i<(argc-3)*2; i+=2)
            tags[i] = argv[i+2];

            for (i=0; i<(argc-3)*2; i+=2)
            memcpy (tags[i], argv[i+2], 7);

            mp3editag (argv[argc-1], tags, argc-3);

            for (i=0; i<(argc-3)*2; i+=2)
            free(tags[i]);

            free(tags);

        return 0;
        }

        if (!strcmp(argv[1], "credits"))
        {

            if (argc > 2)
            tooparam("credits");

            naji_credits();

            return 0;
        }

        if (!strcmp(argv[1], "asctable"))
        {

            if (argc > 2)
            tooparam("asctable");

            asctable();
            return 0;
        }

        if (!strcmp(argv[1], "engnum"))
        {

            if (argc > 2)
            tooparam("engnum");

            engnum();
            return 0;
        }

        if (!strcmp(argv[1], "turnum"))
        {

            if (argc > 2)
            tooparam("turnum");
     
            turnum();
            return 0;
        }

        if (!strcmp(argv[1], "najcrypt"))
        {

            if (argc > 2)
            tooparam("najcrypt");

            najcrypt();
            return 0;
        }

        if (!strcmp(argv[1], "database"))
        {

            if (argc > 2)
            tooparam("database");
    
            naji_database();
            return 0;
        }

        if (!strcmp(argv[1], "html_db"))
        {

            if (argc > 2)
            tooparam("html_db");

            naji_html_database();
            return 0;
        }

        if (!strcmp(argv[1], "calc"))
        {

            if (argc > 2)
            tooparam("calc");

            naji_calc();
            return 0;
        }

        if (!strcmp(argv[1], "length"))
        {

            if (argc > 2)
            tooparam("length");

            length();
            return 0;
        }

        if (!strcmp(argv[1], "mathgame"))
        {

            if (argc > 2)
            tooparam("mathgame");

            mathgame();
            return 0;
        }

        if (!strcmp(argv[1], "license"))
        {

            if (argc > 2)
            tooparam("license");

            naji_license();
            return 0;
        }

        if (!strcmp(argv[1], "ttt"))
        {

            if (argc > 2)
            tooparam("ttt");

            ttt();
            return 0;
        }

        if (!strcmp(argv[1], "naji_bmp"))
        {
            if (argc > 2)
            tooparam("naji_bmp");

            naji_bmp();
            return 0;
        }

        if (!strcmp(argv[1], "unihtml"))
        {

            if (argc > 2)
            tooparam("unihtml");

            naji_gen_unicode_html_pages();
            return 0;
        }
    
        if (!strcmp(argv[1], "rmunihtm"))
        {

            if (argc > 2)
            tooparam("rmunihtm");
    
            naji_del_gen_unicode_html_pages();
            return 0;
        }
    
        if (!strcmp(argv[1], "cat_text"))
        {

            if (argc == 2)
            {
            naji_stdin_msg();
            cat_text_stdin();
            return 0;
            }

            if (argc == 3)
            {
            cat_text(argv[2]);
            return 0;
            }

            if (argc > 3)
            tooparam("cat_text");

            return 0;
        }

        if (!strcmp(argv[1], "kitten"))
        {

            if (argc == 2)
            {
            naji_stdin_msg();
            kitten_stdin();
            return 0;
            }

            if (argc == 3)
            {
            kitten(argv[2]);
            return 0;
            }

            if (argc > 3)
            tooparam("kitten");

        return 0;
        }

        if (!strcmp(argv[1], "genlic"))
        {

            if (argc > 2)
            tooparam("genlic");

            naji_genlic();
            return 0;
        }

        if (!strcmp(argv[1], "genhelp"))
        {

            if (argc > 2)
            tooparam("genhelp");

            najitool_generate_help();
            return 0;
        }

        if (!strcmp(argv[1], "htmlhelp"))
        {
            if (argc > 2)
            tooparam("htmlhelp");

            najitool_generate_help_html();
            return 0;
        }

        if (!strcmp(argv[1], "systemdt"))
        {
            if (argc > 2)
            tooparam("systemdt");
        
            systemdt();
            return 0;
        }


        if (!strcmp(argv[1], "datetime"))
        {

            if (argc > 2)
            tooparam("datetime");

            datetime();
            return 0;
        }

        if (!strcmp(argv[1], "telltime"))
        {

            if (argc > 2)
            tooparam("telltime");

            printf("\n\n");
            telltime();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "today"))
        {

            if (argc > 2)
            tooparam("today");

            printf("\n\n");
            today();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "dayofmon"))
        {

            if (argc > 2)
            tooparam("dayofmon");
    
            printf("\n\n");
            dayofmon();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "month"))
        {

            if (argc > 2)
            tooparam("month");

            printf("\n\n");
            month();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "year"))
        {

            if (argc > 2)
            tooparam("year");

            printf("\n\n");
            year();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "saatarih"))
        {

            if (argc > 2)
            tooparam("saatarih");

            saatarih();
            return 0;
        }

        if (!strcmp(argv[1], "saat"))
        {

            if (argc > 2)
            tooparam("saat");

            printf("\n\n");
            saat();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "bugun"))
        {
            if (argc > 2)
            tooparam("bugun");

            printf("\n\n");
            bugun();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "ayinkaci"))
        {

            if (argc > 2)
            tooparam("ayinkaci");

            printf("\n\n");
            ayinkaci();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "ay"))
        {

            if (argc > 2)
            tooparam("ay");

            printf("\n\n");
            ay();
            printf("\n\n");

            return 0;
        }

        if (!strcmp(argv[1], "yil"))
        {
            if (argc > 2)
            tooparam("yil");

            printf("\n\n");
            yil();
            printf("\n\n");

            return 0;
        }


        if (!strcmp(argv[1], "allbmp16"))
        {
            if (argc > 2)
            tooparam("allbmp16");

            printf("\n\n");
            allbmp16();
            printf("\n\n");

            return 0;
        }


        if (!strcmp(argv[1], "help"))
        {

            if (argc == 2)
            {
            printf("\n\nAvailable help catagories:\n\n");
            printf("commands\n");
            printf("\n\n");
            forhelp();
            return 0;
            }


            if (argc == 3)
            {

                  if (!strcmp(argv[2], "commands"))
                  najitool_help_commands();

                  else najitool_command_help(argv[2]);

                  return 0;
            }


            if (argc > 3)
            tooparam("help");

            return 0;
        }



begin_cmd("mergline", 7)
mergline(argv[2], argv[3], argv[4], argv[5], argv[6]);
end_cmd()

begin_cmd("mp3split", 6)
mp3split(argv[4], argv[5], atoi(argv[2]), atoi(argv[3]));
end_cmd()

begin_cmd("rrrchars", 6)
rrrchars(argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
end_cmd()

begin_cmd("chstr", 6)
chstr(argv[2], argv[3], argv[4], argv[5]);
end_cmd()

begin_cmd("chchars", 6)
chchars(argv[2], argv[3], argv[4], argv[5]);
end_cmd()

begin_cmd("chchar", 6)
chchar(argv[2], argv[3], argv[4][0], argv[5][0]);
end_cmd()

begin_cmd("filechop", 6)
filechop( (strtol(argv[2], NULL, 0)), argv[3], argv[4], argv[5]);
end_cmd()
        
begin_cmd("putlines", 6)
putlines(argv[2], argv[3], argv[4], argv[5]);
end_cmd()

begin_cmd("copyoffs", 6)
copyoffs(argv[2], strtoul(argv[3], NULL, 0), strtoul(argv[4], NULL, 0), argv[5]);
end_cmd()

begin_cmd("istrael", 6)
istrael(argv[2], atoi(argv[3]), argv[4], argv[5]);
end_cmd()

begin_cmd("addline", 6)
addline(argv[2], argv[3], argv[4], strtoul(argv[5], NULL, 0));
end_cmd()

begin_cmd("replacel", 6)
replacel(argv[2], argv[3], argv[4], strtoul(argv[5], NULL, 0));
end_cmd()


begin_cmd("bremline", 5)
bremline(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("eremline", 5)
eremline(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("remline", 5)
remline(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("skipstr", 5)
skipstr(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("makarray", 5)
makarray(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("streline", 5)
streline(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("strbline", 5)
strbline(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("swapfeb", 5)
swapfeb(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("filbreed", 5)
filbreed(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("skipchar", 5)
skipchar(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("onlychar", 5)
onlychar(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("repchar", 5)
repeat = (unsigned int) atoi(argv[4]);
repchar(argv[2], argv[3], repeat);
end_cmd()

begin_cmd("linesnip", 5)
repeat = (unsigned int) atoi(argv[2]);
linesnip(repeat, argv[3], argv[4]);
end_cmd()

begin_cmd("charwarp", 5)
repeat = (unsigned int) atoi(argv[4]);
charwrap(repeat, argv[2], argv[3]);
end_cmd()

begin_cmd("repcharp", 5)
repeat = (unsigned int) atoi(argv[4]);
repcharp(argv[2], argv[3], repeat);
end_cmd()

begin_cmd("coffset", 5)
coffset(argv[2], strtoul(argv[3], NULL, 0), strtoul(argv[4], NULL, 0));
end_cmd()

begin_cmd("dumpoffs", 5)
dumpoffs(argv[2], strtoul(argv[3], NULL, 0), strtoul(argv[4], NULL, 0));
end_cmd()

begin_cmd("bin2c", 5)
bin2c(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("filejoin", 5)
filejoin(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("mkpatch", 5)
mkpatch(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("charfile", 5)
repeat = (unsigned int) atoi(argv[3]);
charfile(argv[2], repeat, argv[4][0]);
end_cmd()

begin_cmd("strfile", 5)
repeat = (unsigned int) atoi(argv[3]);
strfile(argv[2], repeat, argv[4]);
end_cmd()

begin_cmd("tabspace", 5)
repeat = atoi(argv[2]);
tabspace(repeat, argv[3], argv[4]);
end_cmd()

begin_cmd("charaftr", 5)
charaftr(argv[2], argv[3], argv[4][0]);
end_cmd()

begin_cmd("charbefr", 5)
charbefr(argv[2], argv[3], argv[4][0]);
end_cmd()

begin_cmd("strachar", 5)
strachar(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("strbchar", 5)
strbchar(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("rstrach", 5)
rstrach(atoi(argv[2]), argv[3], argv[4]);
end_cmd()

begin_cmd("rstrbch", 5)
rstrbch(atoi(argv[2]), argv[3], argv[4]);
end_cmd()

begin_cmd("cpfroml", 5)
cpfroml(atoi(argv[2]), argv[3], argv[4]);
end_cmd()

begin_cmd("cptiline", 5)
cptiline(atoi(argv[2]), argv[3], argv[4]);
end_cmd()

begin_cmd("n2ch", 5)
n2ch(argv[2][0], argv[3], argv[4]);
end_cmd()

begin_cmd("n2str", 5)
n2str(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("weakrypt", 5)
weakrypt(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("sp2ce2sp", 5)
sp2ce2sp(argv[2][0], argv[3], argv[4]);
end_cmd()

begin_cmd("istreml", 5)
istreml(argv[2], argv[3], argv[4]);
end_cmd()

begin_cmd("removel", 5)
removel(argv[2], argv[3], strtoul(argv[4], NULL, 0));
end_cmd()




begin_cmd("printftx", 4)
printftx(argv[2], argv[3]);
end_cmd()

begin_cmd("lensorts", 4)
lensorts(argv[2], argv[3]);
end_cmd()

begin_cmd("lensortl", 4)
lensortl(argv[2], argv[3]);
end_cmd()

begin_cmd("find", 4)
find(argv[2], argv[3]);
end_cmd()

begin_cmd("findi", 4)
findi(argv[2], argv[3]);
end_cmd()

begin_cmd("cfind", 4)
cfind(argv[2], argv[3]);
end_cmd()

begin_cmd("cfindi", 4)
cfindi(argv[2], argv[3]);
end_cmd()

begin_cmd("showline", 4)
showline(argv[2], atoi(argv[3]));
end_cmd()

begin_cmd("cat_tail", 4)
cat_tail(argv[2], atoi(argv[3]));
end_cmd()

begin_cmd("cat_head", 4)
cat_head(argv[2], atoi(argv[3]));
end_cmd()

begin_cmd("getlinks", 4)
getlinks(argv[2], argv[3]);
end_cmd()

begin_cmd("f2upper", 4)
f2upper(argv[2], argv[3]);
end_cmd()

begin_cmd("f2lower", 4)
f2lower(argv[2], argv[3]);
end_cmd()

begin_cmd("fswpcase", 4)
fswpcase(argv[2], argv[3]);
end_cmd()

begin_cmd("downlist", 4)
downlist(argv[2], argv[3]);
end_cmd()

begin_cmd("hilist", 4)
hilist(argv[2], argv[3]);
end_cmd()

begin_cmd("rtcafter", 4)
rtcafter(argv[2], argv[3]);
end_cmd()

begin_cmd("rtcbefor", 4)
rtcbefor(argv[2], argv[3]);
end_cmd()

begin_cmd("rbcafter", 4)
rbcafter(argv[2], argv[3]);
end_cmd()

begin_cmd("rbcbefor", 4)
rbcbefor(argv[2], argv[3]);
end_cmd()

begin_cmd("numlines", 4)
numlines(argv[2], argv[3]);
end_cmd()

begin_cmd("file2dec", 4)
file2dec(argv[2], argv[3]);
end_cmd()

begin_cmd("file2hex", 4)
file2hex(argv[2], argv[3]);
end_cmd()

begin_cmd("file2bin", 4)
file2bin(argv[2], argv[3]);
end_cmd()

begin_cmd("wordline", 4)
wordline(argv[2], argv[3]);
end_cmd()

begin_cmd("8bit256", 4)
repeat = (unsigned int) atoi(argv[3]);
_8bit256(argv[2], repeat);
end_cmd()

begin_cmd("eng2arab", 4)
eng2arab(argv[2], argv[3]);
end_cmd()

begin_cmd("arab2eng", 4)
arab2eng(argv[2], argv[3]);
end_cmd()

begin_cmd("e2ahtml", 4)
e2ahtml(argv[2], argv[3]);
end_cmd()

begin_cmd("freverse", 4)
freverse(argv[2], argv[3]);
end_cmd()

begin_cmd("repcat", 4)
repeat = (unsigned int) atoi(argv[3]);
repcat(argv[2], repeat);
end_cmd()

begin_cmd("repcatpp", 4)
repeat = (unsigned int) atoi(argv[3]);
repcatpp(argv[2], repeat);
end_cmd()

begin_cmd("copyfile", 4)
copyfile(argv[2], argv[3]);
end_cmd()

begin_cmd("qpatch", 4)
qpatch(argv[2], argv[3]);
end_cmd()

begin_cmd("flipcopy", 4)
flipcopy(argv[2], argv[3]);
end_cmd()

begin_cmd("fillfile", 4)
fillfile(argv[2], argv[3][0]);
end_cmd()

begin_cmd("bin2text", 4)
bin2text(argv[2], argv[3]);
end_cmd()

begin_cmd("bin2hexi", 4)
bin2hexi(argv[2], argv[3]);
end_cmd()

begin_cmd("rndbfile", 4)
rndbfile(argv[2], strtoul(argv[3], NULL, 0));
end_cmd()

begin_cmd("rndtfile", 4)
rndtfile(argv[2], strtoul(argv[3], NULL, 0));
end_cmd()

begin_cmd("skipcat", 4)
skipcat(argv[2], argv[3]);
end_cmd()

begin_cmd("onlycat", 4)
onlycat(argv[2], argv[3]);
end_cmd()

begin_cmd("bigascif", 4)
bigascif(argv[2], argv[3]);
end_cmd()

begin_cmd("leetfile", 4)
leetfile(argv[2], argv[3]);
end_cmd()

begin_cmd("asc2ebc", 4)
asc2ebc(argv[2], argv[3]);
end_cmd()

begin_cmd("ebc2asc", 4)
ebc2asc(argv[2], argv[3]);
end_cmd()

begin_cmd("unix2dos", 4)
unix2dos(argv[2], argv[3]);
end_cmd()

begin_cmd("dos2unix", 4)
dos2unix(argv[2], argv[3]);
end_cmd()

begin_cmd("uuencode", 4)
uuencode(argv[2], argv[3]);
end_cmd()

begin_cmd("uudecode", 4)
uudecode(argv[2], argv[3]);
end_cmd()

begin_cmd("wordwrap", 4)
wordwrap(argv[2], argv[3]);
end_cmd()

begin_cmd("compare", 4)
compare(argv[2], argv[3]);
end_cmd()

begin_cmd("ccompare", 4)
ccompare(argv[2], argv[3]);
end_cmd()

begin_cmd("hmakerf", 4)
hmakerf(argv[2], argv[3]);
end_cmd()

begin_cmd("qcrypt", 4)
qcrypt(argv[2], argv[3]);
end_cmd()

begin_cmd("revlines", 4)
revlines(argv[2], argv[3]);
end_cmd()

begin_cmd("html2txt", 4)
html2txt(argv[2], argv[3]);
end_cmd()

begin_cmd("txt2html", 4)
txt2html(argv[2], argv[3]);
end_cmd()

begin_cmd("htmlfast", 4)
htmlfast(argv[2], argv[3]);
end_cmd()

begin_cmd("onlalnum", 4)
onlalnum(argv[2], argv[3]);
end_cmd()

begin_cmd("onlalpha", 4)
onlalpha(argv[2], argv[3]);
end_cmd()

begin_cmd("onlcntrl", 4)
onlcntrl(argv[2], argv[3]);
end_cmd()

begin_cmd("onldigit", 4)
onldigit(argv[2], argv[3]);
end_cmd()

begin_cmd("onlgraph", 4)
onlgraph(argv[2], argv[3]);
end_cmd()

begin_cmd("onllower", 4)
onllower(argv[2], argv[3]);
end_cmd()

begin_cmd("onlprint", 4)
onlprint(argv[2], argv[3]);
end_cmd()

begin_cmd("onlpunct", 4)
onlpunct(argv[2], argv[3]);
end_cmd()

begin_cmd("onlspace", 4)
onlspace(argv[2], argv[3]);
end_cmd()

begin_cmd("onlupper", 4)
onlupper(argv[2], argv[3]);
end_cmd()

begin_cmd("onlxdigt", 4)
onlxdigt(argv[2], argv[3]);
end_cmd()

begin_cmd("skpalnum", 4)
skpalnum(argv[2], argv[3]);
end_cmd()

begin_cmd("skpalpha", 4)
skpalpha(argv[2], argv[3]);
end_cmd()

begin_cmd("skpcntrl", 4)
skpcntrl(argv[2], argv[3]);
end_cmd()

begin_cmd("skpdigit", 4)
skpdigit(argv[2], argv[3]);
end_cmd()

begin_cmd("skpgraph", 4)
skpgraph(argv[2], argv[3]);
end_cmd()

begin_cmd("skplower", 4)
skplower(argv[2], argv[3]);
end_cmd()

begin_cmd("skpprint", 4)
skpprint(argv[2], argv[3]);
end_cmd()

begin_cmd("skppunct", 4)
skppunct(argv[2], argv[3]);
end_cmd()

begin_cmd("skpspace", 4)
skpspace(argv[2], argv[3]);
end_cmd()

begin_cmd("skpupper", 4)
skpupper(argv[2], argv[3]);
end_cmd()

begin_cmd("skpxdigt", 4)
skpxdigt(argv[2], argv[3]);
end_cmd()

begin_cmd("ftothe", 4)
ftothe(argv[2], argv[3]);
end_cmd()

begin_cmd("blanka", 4)
blanka(argv[2], argv[3]);
end_cmd()

begin_cmd("unblanka", 4)
unblanka(argv[2], argv[3]);
end_cmd()

begin_cmd("najirle", 4)
najirle(argv[2], argv[3]);
end_cmd()

begin_cmd("unajirle", 4)
unajirle(argv[2], argv[3]);
end_cmd()


begin_cmd("gplus", 4)
a = atoi(argv[2]);
b = atoi(argv[3]);
gplus(a, b);
end_cmd()


begin_cmd("gminus", 4)
a = atoi(argv[2]);
b = atoi(argv[3]);
gminus(a, b);
end_cmd()


begin_cmd("gtimes", 4)
a = atoi(argv[2]);
b = atoi(argv[3]);
gtimes(a, b);
end_cmd()


begin_cmd("gdivide", 4)
gdivide_a = atof(argv[2]);
gdivide_b = atof(argv[3]);
gdivide(gdivide_a, gdivide_b);
end_cmd()


begin_cmd("bytsplit", 4)
bytsplit(argv[2], atol(argv[3]));
end_cmd()

begin_cmd("kbsplit", 4)
kbsplit(argv[2], atol(argv[3]));
end_cmd()

begin_cmd("mbsplit", 4)
mbsplit(argv[2], atol(argv[3]));
end_cmd()

begin_cmd("gbsplit", 4)
gbsplit(argv[2], atol(argv[3]));
end_cmd()

begin_cmd("mjoin", 4)
mjoin(argv[2], argv[3]);
end_cmd()


begin_cmd("listdigt", 4)
listdigt(atoi(argv[2]), argv[3]);
end_cmd()

begin_cmd("listlowr", 4)
listlowr(atoi(argv[2]), argv[3]);
end_cmd()

begin_cmd("listprnt", 4)
listprnt(atoi(argv[2]), argv[3]);
end_cmd()

begin_cmd("listuppr", 4)
listuppr(atoi(argv[2]), argv[3]);
end_cmd()

begin_cmd("charsort", 4)
charsort(argv[2], argv[3]);
end_cmd()

begin_cmd("sp2re2sp", 4)
sp2re2sp(argv[2], argv[3]);
end_cmd()









begin_cmd("lcvfiles", 3)
lcvfiles(argv[2]);
end_cmd()

begin_cmd("rcvfiles", 3)
rcvfiles(argv[2]);
end_cmd()


begin_cmd("mp3tagnf", 3)
mp3info(argv[2]);
end_cmd()

begin_cmd("catrandl", 3)
catrandl(argv[2]);
end_cmd()

begin_cmd("leetstr", 3)
printf("\n\n");
leetstr(argv[2]);
printf("\n\n");
end_cmd()

begin_cmd("lcharvar", 3)
lcharvar(argv[2]);
end_cmd()

begin_cmd("rcharvar", 3)
rcharvar(argv[2]);
end_cmd()

begin_cmd("hexicat", 3)
hexicat(argv[2]);
end_cmd()

begin_cmd("rndffill", 3)
rndffill(argv[2]);
end_cmd()

begin_cmd("zerokill", 3)
zerokill(argv[2]);
end_cmd()

begin_cmd("randkill", 3)
randkill(argv[2]);
end_cmd()

begin_cmd("najisum", 3)
najisum(argv[2]);
end_cmd()


begin_cmd("rndbsout", 3)
rndbsout(strtoul(argv[2], NULL, 0));
end_cmd()

begin_cmd("rndtsout", 3)
rndtsout(strtoul(argv[2], NULL, 0));
end_cmd()

begin_cmd("patch", 3)
patch(argv[2]);
end_cmd()

begin_cmd("revcat", 3)
revcat(argv[2]);
end_cmd()

begin_cmd("copyself", 3)
copyfile(argv[0], argv[2]);
end_cmd()

begin_cmd("bigascii", 3)
bigascii(argv[2]);
end_cmd()

begin_cmd("hmaker", 3)
hmaker(argv[2]);
end_cmd()

begin_cmd("wrdcount", 3)
printf("\n\n%i\n\n", wrdcount(argv[2]));
end_cmd()

begin_cmd("addim", 3)
addim(atoi(argv[2]));
end_cmd()

begin_cmd("allfiles", 3)

fprintf(stderr, 
"\n"
"NOTE: On most systems you can stop with Ctrl+C\n"
"WARNING: This will make a lot of files.\n"
"Are you sure? type YES to continue\n"
"or anything else to quit.\n"
);
safegets(are_you_sure, 80);
            
if (!strcmp(are_you_sure, "YES"))
allfiles(atol(argv[2]));
end_cmd();        

begin_cmd("tothe", 3)
tothe(argv[2]);
end_cmd()

begin_cmd("vowelwrd", 3)
vowelwrd(argv[2]);
end_cmd()

begin_cmd("gigabyte", 3)
gigabyte(strtoul(argv[2], NULL, 0));
end_cmd()

begin_cmd("sort", 3)
sort(argv[2]);
end_cmd()

begin_cmd("sortlast", 3)
sortlast(argv[2]);
end_cmd()

begin_cmd("lineback", 3)
lineback(argv[2]);
end_cmd()

begin_cmd("longline", 3)
longline(argv[2]);
end_cmd()

begin_cmd("howline", 3)
howline(argv[2]);
end_cmd()

begin_cmd("rndlines", 3)
rndlines(argv[2]);
end_cmd()

begin_cmd("spyramid", 3)
spyramid(argv[2]);
end_cmd()


    } /* if (argc >= 2) */

return 0;         
}
