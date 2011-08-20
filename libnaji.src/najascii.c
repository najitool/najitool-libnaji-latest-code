/* ---------- */
/* najascii.c */
/* ---------- */

    /* naji ASCII functions, such as very big text    */
   /* my ASCII Art Letter's written from scratch     */
  /* a reminder: this is all absolutely free and    */
 /* public domain, so have some fun.               */

/* if you want to contribute your own letters */
/* e-mail me: naji@users.sourceforge.net      */

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

/* todo:
make functions like

  int naji_ascii_number
 long naji_ascii_number
double naji_ascii_number

and naji_ascii_string
also make one that does turkish and arabic in ascii art
just use the naji_1 naji_2 naji_3

use >> to shift the bits
for naji_ascii_number, also do naji_ascii_hexi
*/

void naji_(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "           ");
if (a == 1) fprintf(stream, "           ");
if (a == 2) fprintf(stream, "           ");
if (a == 3) fprintf(stream, "           ");
if (a == 4) fprintf(stream, "           ");
if (a == 5) fprintf(stream, "           ");
}

void naji_a(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    ____    ");
if (a == 1) fprintf(stream, "   / __ \\   ");
if (a == 2) fprintf(stream, "  | |  | |  ");
if (a == 3) fprintf(stream, "  | |__| |  ");
if (a == 4) fprintf(stream, "  |  __  |  ");
if (a == 5) fprintf(stream, "  |_|  |_|  ");
}

void naji_b(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _____   ");
if (a == 1) fprintf(stream, "  |  _  |  ");
if (a == 2) fprintf(stream, "  | |_| /  ");
if (a == 3) fprintf(stream, "  |  _  \\  ");
if (a == 4) fprintf(stream, "  | |_| |  ");
if (a == 5) fprintf(stream, "  |_____|  ");
}

void naji_c(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _____   ");
if (a == 1) fprintf(stream, "  |  ___|  ");
if (a == 2) fprintf(stream, "  | |      ");
if (a == 3) fprintf(stream, "  | |      ");
if (a == 4) fprintf(stream, "  | |___   ");
if (a == 5) fprintf(stream, "  |_____|  ");
}

void naji_d(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ____     ");
if (a == 1) fprintf(stream, "  |     \\   ");
if (a == 2) fprintf(stream, "  | |~\\  |  ");
if (a == 3) fprintf(stream, "  | |  | |  ");
if (a == 4) fprintf(stream, "  | |_/  |  ");
if (a == 5) fprintf(stream, "  |_____/   ");
return;
}

void naji_e(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _____   ");
if (a == 1) fprintf(stream, "  |  ___|  ");
if (a == 2) fprintf(stream, "  | |___   ");
if (a == 3) fprintf(stream, "  |  ___|  ");
if (a == 4) fprintf(stream, "  | |___   ");
if (a == 5) fprintf(stream, "  |_____|  ");
}

void naji_f(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _____   ");
if (a == 1) fprintf(stream, "  |   __|  ");
if (a == 2) fprintf(stream, "  |  |__   ");
if (a == 3) fprintf(stream, "  |   __|  ");
if (a == 4) fprintf(stream, "  |  |     ");
if (a == 5) fprintf(stream, "  |__|     ");
}

void naji_g(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  /  __  \\  ");
if (a == 2) fprintf(stream, "  | |  |_|  ");
if (a == 3) fprintf(stream, "  | |  __   ");
if (a == 4) fprintf(stream, "  | |__\\ |  ");
if (a == 5) fprintf(stream, "  |_____/   ");
}

void naji_h(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _    _   ");
if (a == 1) fprintf(stream, "  | |  | |  ");
if (a == 2) fprintf(stream, "  | |__| |  ");
if (a == 3) fprintf(stream, "  |  __  |  ");
if (a == 4) fprintf(stream, "  | |  | |  ");
if (a == 5) fprintf(stream, "  |_|  |_|  ");
}

void naji_i(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     __     ");
if (a == 1) fprintf(stream, "    |  |    ");
if (a == 2) fprintf(stream, "    |  |    ");
if (a == 3) fprintf(stream, "    |  |    ");
if (a == 4) fprintf(stream, "    |  |    ");
if (a == 5) fprintf(stream, "    |__|    ");
}

void naji_j(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "       __   ");
if (a == 1) fprintf(stream, "      |  |  ");
if (a == 2) fprintf(stream, "      |  |  ");
if (a == 3) fprintf(stream, "  ___ |  |  ");
if (a == 4) fprintf(stream, "  | |_|  |  ");
if (a == 5) fprintf(stream, "  \\______|  ");
}

void naji_k(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   __  ___  ");
if (a == 1) fprintf(stream, "  |  |/  /  "); 
if (a == 2) fprintf(stream, "  |    _/   ");
if (a == 3) fprintf(stream, "  |   /__   ");
if (a == 4) fprintf(stream, "  |   _  \\  ");
if (a == 5) fprintf(stream, "  |__| \\__\\ ");
}

void naji_l(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    __       ");
if (a == 1) fprintf(stream, "   |  |      ");
if (a == 2) fprintf(stream, "   |  |      ");
if (a == 3) fprintf(stream, "   |  |      ");
if (a == 4) fprintf(stream, "   |  |___   ");
if (a == 5) fprintf(stream, "   |______|  ");
}

void naji_m(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "  _      _  ");
if (a == 1) fprintf(stream, " | \\    / | ");
if (a == 2) fprintf(stream, " |  \\__/  | ");
if (a == 3) fprintf(stream, " |        | ");
if (a == 4) fprintf(stream, " |  /\\/\\  | ");
if (a == 5) fprintf(stream, " |_|    |_| ");
}

void naji_n(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _    _   ");
if (a == 1) fprintf(stream, "  | \\  | |  ");
if (a == 2) fprintf(stream, "  |  \\_| |  ");
if (a == 3) fprintf(stream, "  |      |  ");
if (a == 4) fprintf(stream, "  | |\\   |  ");
if (a == 5) fprintf(stream, "  |_| \\__|  ");
}

void naji_o(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |      |  ");
if (a == 2) fprintf(stream, "  | |~~| |  ");
if (a == 3) fprintf(stream, "  | |  | |  ");
if (a == 4) fprintf(stream, "  | |__| |  ");
if (a == 5) fprintf(stream, "  |______|  ");
}

void naji_p(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |      |  ");
if (a == 2) fprintf(stream, "  | |~~| |  ");
if (a == 3) fprintf(stream, "  | ~~~~ |  ");
if (a == 4) fprintf(stream, "  | |~~~~   ");
if (a == 5) fprintf(stream, "  |_|       ");
}

void naji_q(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |      |  ");
if (a == 2) fprintf(stream, "  | |~~| |  ");
if (a == 3) fprintf(stream, "  | | _| |  ");
if (a == 4) fprintf(stream, "  | |_\\ \\|  ");
if (a == 5) fprintf(stream, "  |____\\_\\  ");
}

void naji_r(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |      |  ");
if (a == 2) fprintf(stream, "  | |~~| |  ");
if (a == 3) fprintf(stream, "  | ~~~~ |  ");
if (a == 4) fprintf(stream, "  | |~\\ \\~  ");
if (a == 5) fprintf(stream, "  |_|  \\_\\  ");
}

void naji_s(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   /  __ \\  ");
if (a == 2) fprintf(stream, "   \\  \\ \\/  ");
if (a == 3) fprintf(stream, " /\\ \\  \\    ");
if (a == 4) fprintf(stream, " \\ \\_\\  \\   ");
if (a == 5) fprintf(stream, "  \\_____/   ");
}

void naji_t(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |_    _|  ");
if (a == 2) fprintf(stream, "    |  |    ");
if (a == 3) fprintf(stream, "    |  |    ");
if (a == 4) fprintf(stream, "    |  |    ");
if (a == 5) fprintf(stream, "    |__|    ");
}

void naji_u(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _    _   ");
if (a == 1) fprintf(stream, "  | |  | |  ");
if (a == 2) fprintf(stream, "  | |  | |  ");
if (a == 3) fprintf(stream, "  | |  | |  ");
if (a == 4) fprintf(stream, "  | |__| |  ");
if (a == 5) fprintf(stream, "  |______|  ");
}

void naji_v(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _     _  ");
if (a == 1) fprintf(stream, "  | |   | | ");
if (a == 2) fprintf(stream, "  | |   | | ");
if (a == 3) fprintf(stream, "  \\ \\   / / ");
if (a == 4) fprintf(stream, "   \\ \\_/ /  ");
if (a == 5) fprintf(stream, "    \\___/   ");
}

void naji_w(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "  _      _  ");
if (a == 1) fprintf(stream, " | |    | | ");
if (a == 2) fprintf(stream, " | |    | | ");
if (a == 3) fprintf(stream, " | | /\\ | | ");
if (a == 4) fprintf(stream, " | \\/  \\/ | ");
if (a == 5) fprintf(stream, "  \\__/\\__/  ");
}

void naji_x(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   __   __  ");
if (a == 1) fprintf(stream, "   \\ \\_/ /  ");
if (a == 2) fprintf(stream, "    \\   /   ");
if (a == 3) fprintf(stream, "     | |    ");
if (a == 4) fprintf(stream, "    / _ \\   ");
if (a == 5) fprintf(stream, "   /_/ \\_\\  ");
}

void naji_y(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   __   __  ");
if (a == 1) fprintf(stream, "   \\ \\_/ /  ");
if (a == 2) fprintf(stream, "    \\   /   ");
if (a == 3) fprintf(stream, "     | |    ");
if (a == 4) fprintf(stream, "     | |    ");
if (a == 5) fprintf(stream, "     |_|    ");
}

void naji_z(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   |___  |  ");
if (a == 2) fprintf(stream, "      / /   ");
if (a == 3) fprintf(stream, "     / /    ");
if (a == 4) fprintf(stream, "    / /__   ");
if (a == 5) fprintf(stream, "   /_____|  ");
}

void naji_1(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    /~~|    ");
if (a == 1) fprintf(stream, "  /_   |    ");
if (a == 2) fprintf(stream, "    |  |    ");
if (a == 3) fprintf(stream, "    |  |    ");
if (a == 4) fprintf(stream, "   _|  |_   ");
if (a == 5) fprintf(stream, "  |______|  ");
}

void naji_2(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   _____    ");
if (a == 1) fprintf(stream, "  /     \\   ");
if (a == 2) fprintf(stream, " |_/~\\   \\  ");
if (a == 3) fprintf(stream, "     /  /   ");
if (a == 4) fprintf(stream, "   /  /___  ");
if (a == 5) fprintf(stream, "  |_______| ");
}

void naji_3(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |___   \\  ");
if (a == 2) fprintf(stream, "    __|  /  ");
if (a == 3) fprintf(stream, "   <__  <   ");
if (a == 4) fprintf(stream, "   ___|  \\  ");
if (a == 5) fprintf(stream, "  |______/  ");
}

void naji_4(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     /~~|   ");
if (a == 1) fprintf(stream, "    /   |   ");
if (a == 2) fprintf(stream, "   / /| |   ");
if (a == 3) fprintf(stream, "  / /_| |_  ");
if (a == 4) fprintf(stream, " /____   _| ");
if (a == 5) fprintf(stream, "      |_|   ");
}

void naji_5(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |  ____|  ");
if (a == 2) fprintf(stream, "  | |____   ");
if (a == 3) fprintf(stream, "  |____  |  ");
if (a == 4) fprintf(stream, "   ____| |  ");
if (a == 5) fprintf(stream, "  |______|  ");
}

void naji_6(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   / ____|  ");
if (a == 2) fprintf(stream, "  | |____   ");
if (a == 3) fprintf(stream, "  |  __  |  ");
if (a == 4) fprintf(stream, "  | |__| |  ");
if (a == 5) fprintf(stream, "   \\____/   ");
}

void naji_7(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ______   ");
if (a == 1) fprintf(stream, "  |___   |  ");
if (a == 2) fprintf(stream, "     /  /   ");
if (a == 3) fprintf(stream, "    /  /    ");
if (a == 4) fprintf(stream, "   /  /     ");
if (a == 5) fprintf(stream, "  /__/      ");
}

void naji_8(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   / ___ \\  ");
if (a == 2) fprintf(stream, "  | |__| |  ");
if (a == 3) fprintf(stream, "   > __ <   ");
if (a == 4) fprintf(stream, "  | |__| |  ");
if (a == 5) fprintf(stream, "   \\____/   ");
}

void naji_9(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   / ___ \\  ");
if (a == 2) fprintf(stream, "  | |__| |  ");
if (a == 3) fprintf(stream, "   \\ __  |  ");
if (a == 4) fprintf(stream, "   ____| |  ");
if (a == 5) fprintf(stream, "   \\____/   ");
}

void naji_0(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    _____   ");
if (a == 1) fprintf(stream, "   / ___ \\  ");
if (a == 2) fprintf(stream, "  | |  | |  ");
if (a == 3) fprintf(stream, "  | |  | |  ");
if (a == 4) fprintf(stream, "  | |__| |  ");
if (a == 5) fprintf(stream, "   \\____/   ");
}

void naji_ascii_coma(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "            ");
if (a == 1) fprintf(stream, "            ");
if (a == 2) fprintf(stream, "            ");
if (a == 3) fprintf(stream, "     ___    ");
if (a == 4) fprintf(stream, "    |   |   ");
if (a == 5) fprintf(stream, "   /___/    ");
}

void naji_ascii_aposopen(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    ___     ");
if (a == 1) fprintf(stream, "   |   |    ");
if (a == 2) fprintf(stream, "    \\___\\   ");
if (a == 3) fprintf(stream, "            ");
if (a == 4) fprintf(stream, "            ");
if (a == 5) fprintf(stream, "            ");
}

void naji_ascii_aposclose(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     ___    ");
if (a == 1) fprintf(stream, "    |   |   ");
if (a == 2) fprintf(stream, "   /___/    ");
if (a == 3) fprintf(stream, "            ");
if (a == 4) fprintf(stream, "            ");
if (a == 5) fprintf(stream, "            ");
}

void naji_ascii_period(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "            ");
if (a == 1) fprintf(stream, "            ");
if (a == 2) fprintf(stream, "            ");
if (a == 3) fprintf(stream, "    ____    ");
if (a == 4) fprintf(stream, "   |    |   ");
if (a == 5) fprintf(stream, "   |____|   ");
}

void naji_ascii_colon(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    ____    ");
if (a == 1) fprintf(stream, "   |    |   ");
if (a == 2) fprintf(stream, "   |____|   ");
if (a == 3) fprintf(stream, "    ____    ");
if (a == 4) fprintf(stream, "   |    |   ");
if (a == 5) fprintf(stream, "   |____|   ");
}

void naji_ascii_semicolon(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     ___    ");
if (a == 1) fprintf(stream, "    |   |   ");
if (a == 2) fprintf(stream, "    |___|   ");
if (a == 3) fprintf(stream, "     ___    ");
if (a == 4) fprintf(stream, "    |   |   ");
if (a == 5) fprintf(stream, "   /___/    ");
}

void naji_ascii_lessthan(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     /~/    ");
if (a == 1) fprintf(stream, "    / /     ");
if (a == 2) fprintf(stream, "   / /      ");
if (a == 3) fprintf(stream, "   \\ \\      ");
if (a == 4) fprintf(stream, "    \\ \\     ");
if (a == 5) fprintf(stream, "     \\_\\    ");
}

void naji_ascii_morethan(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    \\~\\     ");
if (a == 1) fprintf(stream, "     \\ \\    ");
if (a == 2) fprintf(stream, "      \\ \\   ");
if (a == 3) fprintf(stream, "      / /   ");
if (a == 4) fprintf(stream, "     / /    ");
if (a == 5) fprintf(stream, "    /_/     ");
}
void naji_ascii_paranopen(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "     /~/    ");
if (a == 1) fprintf(stream, "    / /     ");
if (a == 2) fprintf(stream, "   | |      ");
if (a == 3) fprintf(stream, "   | |      ");
if (a == 4) fprintf(stream, "    \\ \\     ");
if (a == 5) fprintf(stream, "     \\_\\    ");
}

void naji_ascii_paranclose(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    \\~\\     ");
if (a == 1) fprintf(stream, "     \\ \\    ");
if (a == 2) fprintf(stream, "      | |   ");
if (a == 3) fprintf(stream, "      | |   ");
if (a == 4) fprintf(stream, "     / /    ");
if (a == 5) fprintf(stream, "    /_/     ");
}

void naji_ascii_underscore(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "            ");
if (a == 1) fprintf(stream, "            ");
if (a == 2) fprintf(stream, "            ");
if (a == 3) fprintf(stream, "            ");
if (a == 4) fprintf(stream, " __________ ");
if (a == 5) fprintf(stream, "|__________|");
}

void naji_ascii_exclaimark(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "    ___     ");
if (a == 1) fprintf(stream, "   |   |    ");
if (a == 2) fprintf(stream, "   |   |    ");
if (a == 3) fprintf(stream, "   |___|    ");
if (a == 4) fprintf(stream, "    ___     ");
if (a == 5) fprintf(stream, "   |___|    ");
}

void naji_ascii_pipe(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   |~~~|    ");
if (a == 1) fprintf(stream, "   |   |    ");
if (a == 2) fprintf(stream, "   |   |    ");
if (a == 3) fprintf(stream, "   |   |    ");
if (a == 4) fprintf(stream, "   |   |    ");
if (a == 5) fprintf(stream, "   |___|    ");
}

void naji_ascii_numsign(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "   ##  ##   ");
if (a == 1) fprintf(stream, " ########## ");
if (a == 2) fprintf(stream, "   ##  ##   ");
if (a == 3) fprintf(stream, "   ##  ##   ");
if (a == 4) fprintf(stream, " ########## ");
if (a == 5) fprintf(stream, "   ##  ##   ");
}

void naji_ascii_fslash(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "      /~~/  ");
if (a == 1) fprintf(stream, "     /  /   ");
if (a == 2) fprintf(stream, "    /  /    ");
if (a == 3) fprintf(stream, "   /  /     ");
if (a == 4) fprintf(stream, "  /  /      ");
if (a == 5) fprintf(stream, " /__/       ");
}

void naji_ascii_bslash(int a, FILE *stream)
{
if (a == 0) fprintf(stream, "  \\~~\\      ");
if (a == 1) fprintf(stream, "   \\  \\     ");
if (a == 2) fprintf(stream, "    \\  \\    ");
if (a == 3) fprintf(stream, "     \\  \\   ");
if (a == 4) fprintf(stream, "      \\  \\  ");
if (a == 5) fprintf(stream, "       \\__\\ ");
}




void naji_ascii(char *string, int i, int a, FILE *stream)
{
/* small and big letter is the same for now */
/* i might do different styles in later versions */

    if (string[i] == ' ') { naji_(a, stream); return; }
    if (string[i] == 'a') { naji_a(a, stream); return; }
    if (string[i] == 'b') { naji_b(a, stream); return; }
    if (string[i] == 'c') { naji_c(a, stream); return; }
    if (string[i] == 'd') { naji_d(a, stream); return; }
    if (string[i] == 'e') { naji_e(a, stream); return; }
    if (string[i] == 'f') { naji_f(a, stream); return; }
    if (string[i] == 'g') { naji_g(a, stream); return; }
    if (string[i] == 'h') { naji_h(a, stream); return; }
    if (string[i] == 'i') { naji_i(a, stream); return; }
    if (string[i] == 'j') { naji_j(a, stream); return; }
    if (string[i] == 'k') { naji_k(a, stream); return; }
    if (string[i] == 'l') { naji_l(a, stream); return; }
    if (string[i] == 'm') { naji_m(a, stream); return; }
    if (string[i] == 'n') { naji_n(a, stream); return; }
    if (string[i] == 'o') { naji_o(a, stream); return; }
    if (string[i] == 'p') { naji_p(a, stream); return; }
    if (string[i] == 'q') { naji_q(a, stream); return; }
    if (string[i] == 'r') { naji_r(a, stream); return; }
    if (string[i] == 's') { naji_s(a, stream); return; }
    if (string[i] == 't') { naji_t(a, stream); return; }
    if (string[i] == 'u') { naji_u(a, stream); return; }
    if (string[i] == 'v') { naji_v(a, stream); return; }
    if (string[i] == 'w') { naji_w(a, stream); return; }
    if (string[i] == 'x') { naji_x(a, stream); return; }
    if (string[i] == 'y') { naji_y(a, stream); return; }
    if (string[i] == 'z') { naji_z(a, stream); return; }

    if (string[i] == 'A') { naji_a(a, stream); return; }
    if (string[i] == 'B') { naji_b(a, stream); return; }
    if (string[i] == 'C') { naji_c(a, stream); return; }
    if (string[i] == 'D') { naji_d(a, stream); return; }
    if (string[i] == 'E') { naji_e(a, stream); return; }
    if (string[i] == 'F') { naji_f(a, stream); return; }
    if (string[i] == 'G') { naji_g(a, stream); return; }
    if (string[i] == 'H') { naji_h(a, stream); return; }
    if (string[i] == 'I') { naji_i(a, stream); return; }
    if (string[i] == 'J') { naji_j(a, stream); return; }
    if (string[i] == 'K') { naji_k(a, stream); return; }
    if (string[i] == 'L') { naji_l(a, stream); return; }
    if (string[i] == 'M') { naji_m(a, stream); return; }
    if (string[i] == 'N') { naji_n(a, stream); return; }
    if (string[i] == 'O') { naji_o(a, stream); return; }
    if (string[i] == 'P') { naji_p(a, stream); return; }
    if (string[i] == 'Q') { naji_q(a, stream); return; }
    if (string[i] == 'R') { naji_r(a, stream); return; }
    if (string[i] == 'S') { naji_s(a, stream); return; }
    if (string[i] == 'T') { naji_t(a, stream); return; }
    if (string[i] == 'U') { naji_u(a, stream); return; }
    if (string[i] == 'V') { naji_v(a, stream); return; }
    if (string[i] == 'W') { naji_w(a, stream); return; }
    if (string[i] == 'X') { naji_x(a, stream); return; }
    if (string[i] == 'Y') { naji_y(a, stream); return; }
    if (string[i] == 'Z') { naji_z(a, stream); return; }

    if (string[i] == '1') { naji_1(a, stream); return; }
    if (string[i] == '2') { naji_2(a, stream); return; }
    if (string[i] == '3') { naji_3(a, stream); return; }
    if (string[i] == '4') { naji_4(a, stream); return; }
    if (string[i] == '5') { naji_5(a, stream); return; }
    if (string[i] == '6') { naji_6(a, stream); return; }
    if (string[i] == '7') { naji_7(a, stream); return; }
    if (string[i] == '8') { naji_8(a, stream); return; }
    if (string[i] == '9') { naji_9(a, stream); return; }
    if (string[i] == '0') { naji_0(a, stream); return; }

    if (string[i] == ',')  { naji_ascii_coma(a, stream); return; }
    if (string[i] == '`')  { naji_ascii_aposopen(a, stream); return; }
    if (string[i] == '\'') { naji_ascii_aposclose(a, stream); return; }
    if (string[i] == '.')  { naji_ascii_period(a, stream); return; }
    if (string[i] == ':')  { naji_ascii_colon(a, stream); return; }
    if (string[i] == ';')  { naji_ascii_semicolon(a, stream); return; }
    if (string[i] == '<')  { naji_ascii_lessthan(a, stream); return; }
    if (string[i] == '>')  { naji_ascii_morethan(a, stream); return; }
    if (string[i] == '(')  { naji_ascii_paranopen(a, stream); return; }
    if (string[i] == ')')  { naji_ascii_paranclose(a, stream); return; }
    if (string[i] == '_')  { naji_ascii_underscore(a, stream); return; }
    if (string[i] == '!')  { naji_ascii_exclaimark(a, stream); return; }
    if (string[i] == '|')  { naji_ascii_pipe(a, stream); return; }
    if (string[i] == '#')  { naji_ascii_numsign(a, stream); return; }
    if (string[i] == '/')  { naji_ascii_fslash(a, stream); return; }
    if (string[i] == '\\') { naji_ascii_bslash(a, stream); return; }

}


void _bigascii(char *string, FILE *stream)
{
int a=0;
int i=0;
int l=0;


l = strlen(string);

    for (a=0; a<6; a++)
    {
        for (i=0; i<l; i++)
        naji_ascii(string, i, a, stream);

        fprintf(stream, "\n");
    }


return;
}

void bigascii(char *string)
{
_bigascii(string, stdout);
}

void bigascif(char *string, char *nameout)
{
najout(nameout);
_bigascii(string, naji_output);
najoutclose();
}

