/* ---------- */
/* najilang.c */
/* ---------- */

/* naji language functions */

/* this  .c  file is a part */
/* of libnaji version 0.6.3 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include "libnaji.h"
#include "naji_uni.h"

int naji_e2a_unicode(int a)
{
        if (a == 'A') return UCODE_AR_ALIF;
        if (a == 'a') return UCODE_AR_FATHA;
        if (a == 'b') return UCODE_AR_BEH;
        if (a == 'c') return UCODE_AR_AIN;
        if (a == 'd') return UCODE_AR_DAL;
        if (a == 'e') return UCODE_AR_FATHA;
        if (a == 'f') return UCODE_AR_FEH;
        if (a == 'g') return UCODE_AR_GHAIN;
        if (a == 'h') return UCODE_AR_HEH;
        if (a == 'i') return UCODE_AR_KASRA;
        if (a == 'j') return UCODE_AR_JEEM;
        if (a == 'k') return UCODE_AR_KAF;
        if (a == 'l') return UCODE_AR_LAM;
        if (a == 'm') return UCODE_AR_MEEM;
        if (a == 'n') return UCODE_AR_NOON;
        if (a == 'o') return UCODE_AR_DAMMA;
        if (a == 'p') return UCODE_AR_BEH;
        if (a == 'q') return UCODE_AR_QAF;
        if (a == 'r') return UCODE_AR_REH;
        if (a == 's') return UCODE_AR_SEEN;
        if (a == 't') return UCODE_AR_TEH;
        if (a == 'u') return UCODE_AR_DAMMA;
        if (a == 'v') return UCODE_AR_THEH;
        if (a == 'w') return UCODE_AR_WAW;
        if (a == 'x') return UCODE_AR_HAH;
        if (a == 'y') return UCODE_AR_YEH;
        if (a == 'z') return UCODE_AR_THAL;
        if (a == 'K') return UCODE_AR_KHAH;
        if (a == 'D') return UCODE_AR_DAD;
        if (a == 'S') return UCODE_AR_SAD;
        if (a == '$') return UCODE_AR_SHEEN;
        if (a == 'T') return UCODE_AR_TAH;
        if (a == 'U') return UCODE_AR_WAW;
        if (a == 'V') return UCODE_AR_ZAIN;
        if (a == '\'') return UCODE_AR_HAMZA;
        if (a == 'W') return UCODE_AR_WAW_WITH_HAMZA_ABOVE;
        if (a == 'I') return UCODE_AR_ALIF_WITH_HAMZA_BELOW;
        if (a == 'Y') return UCODE_AR_ALIF_MAKSURA;
        if (a == 'Z') return UCODE_AR_ZAH;
        if (a == 'H') return UCODE_AR_TEH_MARBUTA;
        if (a == 'E') return UCODE_AR_ALIF_WITH_HAMZA_ABOVE;
        if (a == '@') return UCODE_AR_ALIF_WITH_MADDA_ABOVE;
        if (a == '~') return UCODE_AR_SHADDA;
        if (a == 'N') return UCODE_AR_FATHATAN;
        if (a == '=') return UCODE_AR_KASRATAN;
        if (a == '%') return UCODE_AR_DAMMATAN;
        if (a == '^') return UCODE_AR_SUKUN;
        if (a == '?') return UCODE_AR_QUESTION_MARK;
        if (a == ',') return UCODE_AR_COMMA;
        if (a == ';') return UCODE_AR_SEMICOLON;

return a; /* returns what it got if it couldn't convert it */
}

int naji_e2a(int a)
{
        if (a == 'A') return 199;
        if (a == 'a') return 243;
        if (a == 'b') return 200;
        if (a == 'c') return 218;
        if (a == 'd') return 207;
        if (a == 'e') return 243;
        if (a == 'f') return 221;
        if (a == 'g') return 219;
        if (a == 'h') return 229;
        if (a == 'i') return 246;
        if (a == 'j') return 204;
        if (a == 'k') return 223;
        if (a == 'l') return 225;
        if (a == 'm') return 227;
        if (a == 'n') return 228;
        if (a == 'o') return 245;
        if (a == 'p') return 200;
        if (a == 'q') return 222;
        if (a == 'r') return 209;
        if (a == 's') return 211;
        if (a == 't') return 202;
        if (a == 'u') return 245;
        if (a == 'v') return 203;
        if (a == 'w') return 230;
        if (a == 'x') return 205;
        if (a == 'y') return 237;
        if (a == 'z') return 210;
        if (a == 'K') return 206;
        if (a == 'D') return 214;
        if (a == 'S') return 213;
        if (a == '$') return 212;
        if (a == 'T') return 216;
        if (a == 'U') return 230;
        if (a == 'V') return 208;
        if (a == '\'') return 193;
        if (a == 'W') return 196;
        if (a == 'I') return 197;
        if (a == 'Y') return 236;
        if (a == 'Z') return 217;
        if (a == 'H') return 201;
        if (a == 'E') return 195;
        if (a == '@') return 194;
        if (a == '~') return 248;
        if (a == 'N') return 240;
        if (a == '=') return 242;
        if (a == '%') return 241;
        if (a == '^') return 250;
        if (a == '?') return 191;
        if (a == ',') return 161;
        if (a == ';') return 186;
return a; /* returns what it got if it couldn't convert it */
}

int naji_a2e(int a)
{
        if (a == 243) return 'a';
        if (a == 246) return 'i';
        if (a == 245) return 'u';
        if (a == 248) return '~';
        if (a == 240) return 'N';
        if (a == 242) return '=';
        if (a == 241) return '%';
        if (a == 250) return '^';
        if (a == 199) return 'A';
        if (a == 200) return 'b';
        if (a == 202) return 't';
        if (a == 203) return 'v';
        if (a == 204) return 'j';
        if (a == 205) return 'x';
        if (a == 206) return 'K';
        if (a == 207) return 'd';
        if (a == 208) return 'V';
        if (a == 209) return 'r';
        if (a == 210) return 'z';
        if (a == 211) return 's';
        if (a == 212) return '$';
        if (a == 213) return 'S';
        if (a == 214) return 'D';
        if (a == 216) return 'T';
        if (a == 218) return 'c';
        if (a == 219) return 'g';
        if (a == 221) return 'f';
        if (a == 222) return 'q';
        if (a == 223) return 'k';
        if (a == 225) return 'l';
        if (a == 227) return 'm';
        if (a == 228) return 'n';
        if (a == 229) return 'h';
        if (a == 230) return 'w';
        if (a == 237) return 'y';
        if (a == 193) return '\'';
        if (a == 196) return 'W';
        if (a == 197) return 'I';
        if (a == 236) return 'Y';
        if (a == 217) return 'Z';
        if (a == 201) return 'H';
        if (a == 195) return 'E';
        if (a == 194) return '@';
        if (a == 191) return '?';
        if (a == 161) return ',';
        if (a == 186) return ';';

return a; /* returns what it got if it couldn't convert it */
}

void eng2arab(char *namein, char *nameout)
{
int letter;

najin(namein);
najout(nameout);

        loop
        {
        letter = fgetc(naji_input);
        
        if (letter == EOF)
        endloop;

        letter = naji_e2a(letter);
        fputc(letter, naji_output);
        }

najinclose();
najoutclose();
}

void arab2eng(char *namein, char *nameout)
{
int letter;

najin(namein);
najout(nameout);

        loop
        {
        letter = fgetc(naji_input);
        
        if (letter == EOF)
        endloop;

        letter = naji_a2e(letter);
        fputc(letter, naji_output);
        }

najinclose();
najoutclose();
}




void e2ahtml(char *namein, char *nameout)
{
int letter;

najin(namein);
najout(nameout);

        loop
        {
        letter = fgetc(naji_input);
        
        if (letter == EOF)
        endloop;

        letter = naji_e2a_unicode(letter);
        
        if (letter == '\n')
        fprintf(naji_output, "\n<br>");
        else
        fprintf(naji_output, "&#%i;", letter);
        }

najinclose();
najoutclose();
}




void elite_char_fprint(char a, FILE *out)
{
char b = a;

naji_tolower(b);


  if (b == 'a') { fprintf(out, "4"); return; }
  if (b == 'b') { fprintf(out, "8"); return; }
  if (b == 'e') { fprintf(out, "3"); return; }
  if (b == 'i') { fprintf(out, "1"); return; }
  if (b == 'o') { fprintf(out, "0"); return; }
  if (b == 's') { fprintf(out, "5"); return; }
  if (b == 't') { fprintf(out, "7"); return; }
  if (b == 'd') { fprintf(out, "|>");     return; }
  if (b == 'c') { fprintf(out, "<");      return; }
  if (b == 'k') { fprintf(out, "|<");     return; }
  if (b == 'm') { fprintf(out, "/\\/\\"); return; }
  if (b == 'v') { fprintf(out, "\\/");    return; }
  if (b == 'w') { fprintf(out, "\\/\\/"); return; }
  if (b == 'h') { fprintf(out, "|-|");    return; }
  if (b == 'n') { fprintf(out, "|\\|");   return; }
  if (b == 'x') { fprintf(out, "><");     return; }
  if (b == 'u') { fprintf(out, "|_|");    return; }
  if (b == 'l') { fprintf(out, "|_");     return; }
  if (b == 'j') { fprintf(out, "_|");     return; }

fprintf(out, "%c", a);
}


void elite_char_print(char a)
{
elite_char_fprint(a, stdout);
}


void leetstr(char *string)
{
int i;

  for (i=0; string[i] != 0; i++)
  elite_char_print(string[i]);

}


void leetfile(char *namein, char *nameout)
{
int a;

najin(namein);
najout(nameout);

     loop
     {
     a = fgetc(naji_input);

     if (a == EOF)
     endloop;

     elite_char_fprint((char)a, naji_output);
     }

najinclose();
najoutclose();
}
