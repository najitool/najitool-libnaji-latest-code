#ifndef __LIBNAJI_H__NAJI__
#define __LIBNAJI_H__NAJI__

/* --------- */
/* libnaji.h */
/* --------- */

/* libnaji header file */

/* this  .h  file is a part */
/* of libnaji version 0.6.4 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/* Begin MP3 Code, Written By ARKAINO, formally known as YEHRCL */

#define TRUE 1
#define FALSE 0
#define BUFSIZE 2000
#define LITTLE_END(x) ( ((x & 0xff000000) >> 24) |   \
                         ((x & 0x00ff0000) >> 8)  |  \
                         ((x & 0x0000ff00) << 8)  |  \
                         ((x & 0x000000ff) << 24) )

/* this is for suppressing the last bit on each byte */
#define LITTLE_MESS(x) ( ((x & 0x0000007f) | ((x & 0x00000100) >> 1)) | \
			 (((x & 0x00007f00) | ((x & 0x00010000) >> 1)) >> 1) | \
			 (((x & 0x007f0000) | ((x & 0x01000000) >> 1)) >> 2) | \
			 ((x & 0x7f000000) >> 3) )

enum fileperms {READ_ONLY, READ_WRITE};


#define GET_MPEG(x) (x & 0x08)
#define GET_LAYER(x) (x & 0x06)
#define GET_PROT(x) (x & 0x01)
#define GET_BRATE(x) (x & 0xf0)
#define GET_FREQ(x) (x & 0x0c)
#define GET_PADD(x) (x & 0x02)

enum ids {
	MPEG1=0, PADDING, PROTECTED, LAYER3,
	BRATE32, BRATE40, BRATE48, BRATE56,
	BRATE64, BRATE80, BRATE96, BRATE112,
	BRATE128, BRATE160, BRATE192, BRATE224,
	BRATE256, BRATE320, FREQ44, FREQ48, FREQ32,
	BAD, BLANK
};

/* not all fields are needed, but we declare them for further use */
struct frame_header {
	enum ids id, layer, protected,
		bitrate, padding, frequency;
	int size;

};

/* for printing the user the file attributes, etc */
struct idtable {
	char string[16];
	unsigned int value;

};

extern struct idtable idindex[22];

struct id3v1 {
	char title[31], artist[31], album[31], 
		year[5], comment[30];
	int track;

};

struct id3v2 {
	char * title, *artist, *album, *year, *track, *comment;
	int size;

};

extern char genres [127][18];

enum id3version {ID3V1, ID3V2, BADVERSION};

struct fileinfo {
	FILE * fd;
	struct id3v1 tag;
	struct id3v2 tag2;
	struct frame_header header;
	enum id3version tagver;
};



/*
 * Calculates the frame size from buffer and stores the header data.
 * Returns the frame size in bytes, FALSE otherwise.
 * TODO: CRC support??
 */
int mp3header (char const * buffer, size_t count, struct frame_header * header);

/* 
 * Checks for ID3v1 data in fd and writes it to tag.
 * Returns FALSE in case an id3v1 tag isn't found, TRUE otherwise.
 */
int mp3id3v1 (FILE * fd, struct id3v1 * tag);

/* 
 * Checks for ID3v2 data in fd and writes it to tag.
 * Returns FALSE in case an id3v2 tag isn't found, TRUE otherwise.
 */
int mp3id3v2 (FILE * fd, struct id3v2 * tag);

/*
 * Looks for id3v1 in fd and updates it according to args.
 * Returns TRUE if succeeded, FALSE otherwise.
 */
int mp3editv1 (FILE * fd, char*const* args, int const numarg);

/*
 * Prints the name's mp3 file info.
 */
void mp3info (char *name);

/*
 * Splits name's file from start to end and writes that part to output.
 */
void mp3split (char const * name, char const * output,
	      unsigned int const start, unsigned int const end);

/* 
 * Updates the mp3 tag info of name's file.
 */
void mp3editag (char const * name, char* const* args, int const numarg);


/* End MP3 Code, Written By ARKAINO, formally known as YEHRCL */




#define naji_tolower(a) if ( ( (a) >= 'A') && ( (a) <= 'Z') ) a += 32;
#define naji_toupper(a) if ( ( (a) >= 'a') && ( (a) <= 'z') ) a -= 32;

/* the random number initilizer macro */
/* using this before using the rndrange() */
/* macros is highly recommended because it */
/* makes rndrange produce a lot better */
/* random numbers, you only need to use */
/* it once.  */
#define rndinit() srand(time(NULL))

#define rndrange(start, end) ( rand() % ( (end) + (start) ) )


#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned long

#define UCHAR unsigned char
#define UINT unsigned int
#define ULONG unsigned long

#define SCHAR signed char
#define SINT signed int
#define SLONG signed long

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef signed char schar;
typedef signed int sint;
typedef signed long slong;

#define square_root(a) ((a) * (a))
#define naji_max(a,b) ( ( (a) > (b) ) ? (a):(b) )
#define naji_min(a,b) ( ( (a) < (b) ) ? (a):(b) )

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define newint(amount)  ( (int*) ( malloc(amount) ) )
#define newchar(amount) ( (char*) ( malloc(amount) ) ) 
#define newlong(amount) ( (long*) ( malloc(amount) ) )

#define exitnull(item) \
if ( ( (item) == NULL ) ) \
{\
fprintf(stderr, "\n\nNULL pointer error\n\n"); exit(8);\
}



#define loop while(1)
#define endloop break

/* my version of the FALSE, TRUE defines */
/* to avoid clashes with other libraries and programs */

#define NAJI_FALSE 0
#define NAJI_TRUE  1

extern FILE* naji_input;
extern FILE* naji_input2;
extern FILE* naji_output;
extern FILE* naji_output2;
extern FILE* naji_bmp_out;
extern FILE* naji_edit;


struct najiline {
  int  len;
  long pos;
};


char *addtolinebuf(char c, char *line_buf,
int cur_pos, int *cur_size, int block_size);

char * chstr_line(char *line, char *str, char *newstr);
char * s_ay();
char * s_ayinkaci();
char * s_bugun();
char * s_dayofmon();
char * s_month();
char * s_systemdt();
char * s_today();
char * s_year();
char * s_yil();
char * skipstr_line(char *line, char *str);

void bblensorts(FILE * sourcefile, FILE * destfile,
struct najiline *plines, struct najiline *plineend);

void bblensortl(FILE * sourcefile, FILE * destfile,
struct najiline *plines, struct najiline *plineend);

void writesorted(FILE *sourcefile, FILE *destfile, struct najiline *plines,
struct najiline *plineend, int lflong, char lastchar);

int readforsort(FILE * sourcefile, FILE * destfile,
struct najiline **pplines, struct najiline **pplineend, char *lastchar);


int find_line(const char *line, const char *str);
int findi_line(const char *line, const char *str);
int isequal(char *str, char *tempbuf, int len, int start_pos);
int naji_a2e(int a);
int naji_e2a(int a);
int naji_e2a_unicode(int a);
int randkill(char *name);
int rngtotal(int start, int end);
int swrdcoun(const char *string);
int wrdcount(char *namein);
int zerokill(char *name);
long najedsize(void);
long naji_filesize(FILE *file);
long najin2size(void);
long najinsize(void);
long najout2size(void);
long najoutsize(void);
uchar uc_rand_range(uchar start, uchar end);
uint ui_rand_range(uint start, uint end);
ulong ul_rand_range (ulong start, ulong end);
unsigned char ascii_to_ebcdic_char(const unsigned char a);
unsigned char ebcdic_to_ascii_char(const unsigned char a);
void _8bit256(char *nameout, unsigned long rep);
void _bigascii(char *string, FILE *stream);
void add_entry(char *entry);
void add_entry_html(char *entry);
void add_entry_html_email(char *entry);
void add_entry_html_link(char *entry);
void addim(int max_times);


/* WARNING: be very careful with this */
/* function, it makes a lot of files  */

/* you give it the size in bytes of every  */
/* possible byte combination that you want */

void allfiles(unsigned long int size);
void allfiles_genfile(char *filename, short file_contents[], unsigned long int filesize);
void allfiles_genfilename(short a, short b, short filecontents[], unsigned long int filesize);
void allfiles_main(short a, short b, short *buffer, unsigned long int size);



void allbmp16(void);
void allbmp16_genfile(char *filename, short file_contents[], unsigned long int filesize);
void allbmp16_genfilename(short a, short b, short filecontents[], unsigned long int filesize);
void allbmp16_main(short a, short b, short *buffer, unsigned long int size);




void arab2eng(char *namein, char *nameout);
void asc2ebc(char *namein, char *nameout);
void asctable(void);
void ay();
void ayinkaci();
void bigascif(char *string, char *nameout);
void bigascii(char *string);
void bin2c(char *namein, char *nameout, char *array_name);
void bin2hexi(char *namein, char *nameout);
void bin2text(char *namein, char *nameout);
void blanka(char *namein, char *nameout);
void bmpout(char *nameout);
void bmpoutclose(void);
void bremline(char *str, char *namein, char *nameout);
void bugun();
void bytsplit(char *namein, unsigned long peice_size);
void cat_head(char *namein, int n_lines);
void cat_tail(char *namein, int n_lines);
void cat_text(char *namein);
void cat_text_faster(char *namein);
void cat_text_faster_stdin(void);
void cat_text_fastest(char *namein);
void cat_text_fastest_stdin(void);
void cat_text_stdin(void);
void catrandl(char *namein);
void ccompare(char *namein, char *namein2);
void cfind(char *namein, char *str);
void cfindi(char *namein, char *str);
void charaftr(char *namein, char *nameout, char ch);
void charbefr(char *namein, char *nameout, char ch);
void charfile(char *nameout, unsigned long int size, int c);
void charwrap(int w, char *namein, char *nameout);
void charsort(char *namein, char *nameout);
void chchar(char *namein, char *nameout, char original, char changed);
void chchars(char *namein, char *nameout, char *original_chars, char *changed_chars);
void check_ps(void);
void chstr(char *namein, char *nameout, char *str, char *newstr);
void cm_to_feet(void);
void cm_to_inches(void);
void cm_to_km(void);
void cm_to_meters(void);
void cm_to_miles(void);
void cm_to_mm(void);
void cm_to_yards(void);
void coffset(char *namein, long startpos, long endpos);
void compare(char *namein, char *namein2);
void compfile(char *namein, char *namein2, int cont_on_diff);
void copyfile(char *namein, char *nameout);
void copyoffs(char *namein, long startpos, long endpos, char *nameout);
void copyrep(unsigned long int howmany);
void cpfroml(unsigned long line, char *namein, char *nameout);
void cptiline(unsigned long line, char *namein, char *nameout);
void datetime(void);
void dayofmon();
void dos2unix(char *namein, char *nameout);
void downlist(char *namein, char *nameout);
void dumpoffs(char *namein, long startpos, long endpos);
void e2ahtml(char *namein, char *nameout);
void ebc2asc(char *namein, char *nameout);
void elite_char_fprint(char a, FILE *out);
void elite_char_print(char a);
void endnaji(int error_level);
void eng2arab(char *namein, char *nameout);
void engnum(void);
void eremline(char *str, char *namein, char *nameout);
void errtext(void);
void f2lower(char *namein, char *nameout);
void f2upper(char *namein, char *nameout);
void feet_to_cm(void);
void feet_to_inches(void);
void feet_to_km(void);
void feet_to_meters(void);
void feet_to_miles(void);
void feet_to_mm(void);
void feet_to_yards(void);
void filbreed(char *namein, char *namein2, char *nameout);
void file2bin(char *namein, char *nameout);
void file2dec(char *namein, char *nameout);
void file2hex(char *namein, char *nameout);
void filechop(long copytil, char *namein, char *nameout, char *nameout2);
void filejoin(char *namein, char *namein2, char *nameout);
void fillfile(char *named, char c);
void find_basis(char *namein, char *str, int sensitive, int show_matches);
void find(char *namein, char *str);
void findi(char *namein, char *str);
void flipcopy(char *namein, char *nameout);
void fprint_16_bit_bin(FILE *out, int num);
void fprint_8_bit_bin(FILE *out, char num);
void freverse(char *namein, char *nameout);
void fswpcase(char *namein, char *nameout);
void ftothe(char *namein, char *nameout);
void gbsplit(char *namein, unsigned long peice_size);
void getlinks(char *namein, char *nameout);
void get_password(void);
void get_strength(void);
void get_datetime();
void gdivide(float start, float end);
void gigabyte(unsigned long i);
void gminus(int start, int end);
void gplus(int start, int end);
void gtimes(int start, int end);
void hexaddim();
void hexicat(char *namein);
void hexierr(void);
void hilist(char *namein, char *nameout);
void hmaker(char *namein);
void hmakerf(char *namein, char *nameout);
void html2txt(char *namein, char *nameout);
void htmlfast(char *namein, char *nameout);
void inches_to_cm(void);
void inches_to_feet(void);
void inches_to_km(void);
void inches_to_meters(void);
void inches_to_miles(void);
void inches_to_mm(void);
void inches_to_yards(void);
void kbsplit(char *namein, unsigned long peice_size);
void kiterr(void);
void kitten(char *namein);
void kitten_stdin(void);
void km_to_cm(void);
void km_to_feet(void);
void km_to_inches(void);
void km_to_meters(void);
void km_to_miles(void);
void km_to_mm(void);
void km_to_yards(void);
void lcharvar(char *str);
void lcvfiles(char *namein);
void leetfile(char *namein, char *nameout);
void leetstr(char *string);
void length(void);
void lensort_basis(char whichone, char *namein, char *nameout);
void lensortl(char *namein, char *nameout);
void lensorts(char *namein, char *nameout);
void linesnip(int bytes, char *namein, char *nameout);
void listdigt(unsigned int size, char *nameout);
void listlowr(unsigned int size, char *nameout);
void listprnt(unsigned int size, char *nameout);
void listuppr(unsigned int size, char *nameout);
void makarray(char *namein, char *nameout, char *namevar);
void mathgame(void);
void mbsplit(char *namein, unsigned long peice_size);
void mergline(char *namein, char *namein2, char *nameout, char *beforeline, char *afterline);
void meters_to_cm(void);
void meters_to_feet(void);
void meters_to_inches(void);
void meters_to_km(void);
void meters_to_miles(void);
void meters_to_mm(void);
void meters_to_yards(void);
void miles_to_cm(void);
void miles_to_feet(void);
void miles_to_inches(void);
void miles_to_km(void);
void miles_to_meters(void);
void miles_to_mm(void);
void miles_to_yards(void);
void mjoin(char *namein_original_filename, char *nameout_joined_output_file);
void mkpatch(char *original, char *patched, char *patchfile);
void mm_to_cm(void);
void mm_to_feet(void);
void mm_to_inches(void);
void mm_to_km(void);
void mm_to_meters(void);
void mm_to_miles(void);
void mm_to_yards(void);
void month();
void n2ch(char ch, char *namein, char *nameout);
void n2str(char *str, char *namein, char *nameout);
void najcrypt(void);
void najed(char *named);
void najedclose(void);
void naji_(int a, FILE *stream);
void naji_0(int a, FILE *stream);
void naji_1(int a, FILE *stream);
void naji_2(int a, FILE *stream);
void naji_3(int a, FILE *stream);
void naji_4(int a, FILE *stream);
void naji_5(int a, FILE *stream);
void naji_6(int a, FILE *stream);
void naji_7(int a, FILE *stream);
void naji_8(int a, FILE *stream);
void naji_9(int a, FILE *stream);
void naji_a(int a, FILE *stream);
void naji_addim(unsigned long start, unsigned long end, unsigned long addby);
void naji_ascii(char *string, int i, int a, FILE *stream);
void naji_ascii_aposclose(int a, FILE *stream);
void naji_ascii_aposopen(int a, FILE *stream);
void naji_ascii_bslash(int a, FILE *stream);
void naji_ascii_colon(int a, FILE *stream);
void naji_ascii_coma(int a, FILE *stream);
void naji_ascii_exclaimark(int a, FILE *stream);
void naji_ascii_fslash(int a, FILE *stream);
void naji_ascii_lessthan(int a, FILE *stream);
void naji_ascii_morethan(int a, FILE *stream);
void naji_ascii_numsign(int a, FILE *stream);
void naji_ascii_paranclose(int a, FILE *stream);
void naji_ascii_paranopen(int a, FILE *stream);
void naji_ascii_period(int a, FILE *stream);
void naji_ascii_pipe(int a, FILE *stream);
void naji_ascii_semicolon(int a, FILE *stream);
void naji_ascii_underscore(int a, FILE *stream);
void naji_b(int a, FILE *stream);
void naji_bmp(void);
void naji_bmpheader(void);
void naji_c(int a, FILE *stream);
void naji_calc(void);
void naji_credits(void);
void naji_d(int a, FILE *stream);
void naji_database(void);
void naji_dec(void);
void naji_del_gen_unicode_html_pages(void);
void naji_e(int a, FILE *stream);
void naji_enc(void);
void naji_f(int a, FILE *stream);
void naji_g(int a, FILE *stream);
void naji_gen_unicode_html_pages(void);
void naji_genlic();
void naji_h(int a, FILE *stream);
void naji_hexaddim(unsigned long start, unsigned long end, unsigned long addby);
void naji_html_database(void);
void naji_i(int a, FILE *stream);
void naji_j(int a, FILE *stream);
void naji_k(int a, FILE *stream);
void naji_l(int a, FILE *stream);
void naji_license(void);
void naji_m(int a, FILE *stream);
void naji_n(int a, FILE *stream);
void naji_o(int a, FILE *stream);
void naji_p(int a, FILE *stream);
void naji_q(int a, FILE *stream);
void naji_r(int a, FILE *stream);
void naji_s(int a, FILE *stream);
void naji_t(int a, FILE *stream);
void naji_u(int a, FILE *stream);
void naji_unicode_html_end(void);
void naji_unicode_html_header(int n);
void naji_v(int a, FILE *stream);
void naji_w(int a, FILE *stream);
void naji_x(int a, FILE *stream);
void naji_y(int a, FILE *stream);
void naji_z(int a, FILE *stream);
void najin(char *namein);
void najin2(char *namein2);
void najin2close(void);
void najinclose(void);
void najirle(char *namein, char *nameout);
void najisum(char *namein);
void najout(char *nameout);
void najout2(char *nameout2);
void najout2close(void);
void najoutclose(void);
void nextpage(void);
void numlines(char *namein, char *nameout);
void onlalnum(char *namein, char *nameout);
void onlalpha(char *namein, char *nameout);
void onlcntrl(char *namein, char *nameout);
void onldigit(char *namein, char *nameout);
void onlgraph(char *namein, char *nameout);
void onllower(char *namein, char *nameout);
void onlprint(char *namein, char *nameout);
void onlpunct(char *namein, char *nameout);
void onlspace(char *namein, char *nameout);
void onlupper(char *namein, char *nameout);
void onlxdigt(char *namein, char *nameout);
void onlycat(char *namein, char *toshow);
void onlychar(char *namein, char *nameout, char *toshow);
void patch(char *named);
void printftx(char *namein, char *nameout);
void putlines(char *namein, char *nameout, char *beforeline, char *afterline);
void qcrypt(char *namein, char *nameout);
void qpatch(char *named, char *patch_file);
void rand_init(void);
void rcharvar(char *str);
void rcvfiles(char *namein);
void rbcafter(char *namein, char *nameout);
void rbcbefor(char *namein, char *nameout);
void remline(char *str, char *namein, char *nameout);
void repcat(char *namein, unsigned int repeat);
void repcatpp(char *namein, unsigned int start);
void repchar(char *namein, char *nameout, unsigned int repeat);
void repcharp(char *namein, char *nameout, unsigned int start);
void reperr(unsigned int repeat);
void revcat(char *namein);
void revlines(char *namein, char *nameout);
void rndbfile(char *nameout, unsigned long int size);
void rndbsout(unsigned long int size);
void rndffill(char *named);
void rndtfile(char *nameout, unsigned long int size);
void rndtsout(unsigned long int size);
void rngtotal_test();
void rrrchars(char *namein, char *nameout, int start, int end);
void rstrach(int len, char *namein, char *nameout);
void rstrbch(int len, char *namein, char *nameout);
void rtcafter(char *namein, char *nameout);
void rtcbefor(char *namein, char *nameout);
void saat();
void saatarih(void);
void safegets(char *buf, int size);
void sflpcase(char *str);
void show_16_bit_bin(int num);
void show_8_bit_bin(char num);
void showline(char *namein, unsigned long line);
void skipcat(char *namein, char *toskip);
void skipchar(char *namein, char *nameout, char *toskip);
void skiperr(char *toskip);
void skipstr(char *namein, char *nameout, char *str);
void skpalnum(char *namein, char *nameout);
void skpalpha(char *namein, char *nameout);
void skpcntrl(char *namein, char *nameout);
void skpdigit(char *namein, char *nameout);
void skpgraph(char *namein, char *nameout);
void skplower(char *namein, char *nameout);
void skpprint(char *namein, char *nameout);
void skppunct(char *namein, char *nameout); 
void skpspace(char *namein, char *nameout);
void skpupper(char *namein, char *nameout);
void skpxdigt(char *namein, char *nameout);
void sortfirst(char *namein, char *nameout);
void sortlast(char *namein, char *nameout);
void sortlenl(char *namein, char *nameout);
void sreverse(char *str);
void sstrfile(unsigned long int strictsize, char *string);
void stolower(char *str);
void stoupper(char *str);
void str_move_left(char * s, int n);
void strachar(char *str, char *namein, char *nameout);
void strbchar(char *str, char *namein, char *nameout);
void strbline(char *namein, char *nameout, char *str);
void streline(char *namein, char *nameout, char *str);
void strfile(char *nameout, unsigned long int howmany, char *string);
void swapfeb(char *namein, char *namein2, char *nameout);
void systemdt();
void tabspace(int spaces, char *namein, char *nameout);
void telltime();
void today();
void tolowers(char *str);
void tolowersn(char *str, int n);
void touppers(char *str);
void touppersn(char *str, int n);
void tothe(char *str);
void ttt(void);
void ttt_computermove(void);
void ttt_displayboard(void);
void ttt_displaywinner(void);
char ttt_gameover(void);
void ttt_humanmove(void);
void ttt_instructions(void);
void turnum(void);
void txt2html(char *namein, char *nameout);
void unajirle(char *namein, char *nameout);
void unblanka(char *namein, char *nameout);
void unix2dos(char *namein, char *nameout);
void uudecode(char *namein, char *nameout);
void uuencode(char *namein, char *nameout);
void vowelwrd(char *str);
void weakrypt(const char *password, char *namein, char *nameout);
void wipe_pwd(void);
void wordline(char *namein, char *nameout);
void wordlist(short a, short b, unsigned int size, char *nameout);
void wordwrap(char *namein, char *nameout);
void yards_to_cm(void);
void yards_to_feet(void);
void yards_to_inches(void);
void yards_to_km(void);
void yards_to_meters(void);
void yards_to_miles(void);
void yards_to_mm(void);
void year();
void yil();


#endif /* __LIBNAJI_H__NAJI__ */
