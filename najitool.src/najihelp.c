/* ---------- */
/* najihelp.c */
/* ---------- */

/* najitool help */

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


struct najihelp {

char *cmd;
char *info;
char *usage;
char *example;

};


struct najihelp helpitems[NAJITOOL_MAX_COMMANDS] = {


{
"8bit256",
"makes a file with the character values 0 to 255 from\n"
"start to finish the number of times you specify.",
"<output file> <amount of times>",
"ten.bin 10"
},

{
"addim",
"makes a multipliction square at the size you specify.",
"<square size>",
"12"
},

{
"addline",
"add new line with the specified text at the specified line position.",
"<input text file> <output file> <text> <line position>",
"main.c hello.c 'printf(\"Hello World\");' 10"
},

{
"allbmp16",
"Generates every single .bmp file ever possible to exist at\n"
"16 width, 16 height, and 16 color.",
"",
""
},


{
"allfiles",
"generates every single file ever possible to exist\n"
"at a size you specify.",
"<size in bytes>",
"4"
},

{
"arab2eng",
"Arabic to English transliteration system. Makes English\n"
"letters out of Arabic letters. Download the transliteration\n"
"table from http://najitool.sf.net/ for details.",
"<input file> <output file>",
"arabi.txt eng.txt"
},

{
"asc2ebc",
"convert ASCII format files to EBCDIC format files.",
"<input file> <output file>",
"readme.txt readme.ebc"
},

{
"asctable",
"shows an ASCII table and the decimal, hexidecimal, and binary\n"
"values on each line of it from values 32 to 126.",
"",
""
},

{
"ay",
"shows the current month in Turkish.",
"",
""
},

{
"ayinkaci",
"shows the day of the current month.",
"",
""
},

{
"bigascif",
"makes a file with big ASCII art text out of the word or\n"
"sentence you specify.",
"<text> <output file>",
"hello hello.txt"
},

{
"bigascii",
"shows big ASCII art version of the word or sentence you\n"
"specify to the screen.",
"<text>",
"hello"
},

{
"bytsplit",
"splits the file you specify into the size of pieces you specify in bytes.\n"
"The output file is the original filename with numbered extensions e.g.\n"
"example.big.0, example.big.1, example.big.2...\n"
"You can use mjoin to join the files.",
"<input file> <size of pieces in bytes>",
"example.big 1457664"
},


{
"bin2c",
"makes a compilable C programming language source code file\n"
"out of any file with the contents of the file in an array.",
"<input file> <output c file> <array name>",
"mypic.bmp mypic.c my_pic_array"
},

{
"bin2hexi",
"dumps the file you specify in hexidecimal to a new file.",
"<input file> <output file>",
"DigiTvOS.bin  DigiTvOS.hex"
},


{
"bin2text",
"makes a copy of the file you specify with only the\n"
"text of the file skipping binary characters.",
"<input file> <output file>",
"file.bin file.txt"
},


{
"blanka",
"When a file is converted to blanka format, depending on the decimal value\n"
"of an ASCII char it makes that many spaces, e.g. 65 spaces for the letter A,\n"
"then it makes a newline to seperate the next char, which could be B, so it\n"
"makes 66 spaces, etc. Use unblanka to convert back to original, it can still\n"
"change the file back to its original form if the blanka format file is edited\n"
"without adding anymore spaces or newlines and only other characters.\n"
"Useful for hidden messages.",
"<input file> <output file>",
"myfile.txt secret.txt"
},



{
"bremline",
"makes a copy of a file removing lines\n"
"beginning with a certain word or sentence.",
"<text> <input file> <output file>",
"# prog.c  prog2.c"
},

{
"bugun",
"shows what the day is today in Turkish.",
"",
""
},

{
"calc",
"a calculator.",
"",
""
},

{
"cat_head",
"shows the number of first lines in the file you specify.",
"<input file> <number of first lines>",
"readme.txt 6"
},

{
"cat_tail",
"shows the number of last lines in the file you specify.",
"<input file> <number of last lines>",
"readme.txt 5"
},

{
"cat_text",
"Shows only the text of a file to screen skiping binary\n"
"characters. Accepts input from stdin (standard input).",
"\nnajitool cat_text <input file>",
"\nnajitool cat_text a.out"
},

{
"catrandl",
"shows a random line of a text file.",
"<line>",
"foodlist.txt"
},

{
"ccompare",
"compares two files and still continues when differences are encountered.",
"<input file 1> <input file 2>",
"a.out a.bin"
},

{
"cfind",
"search each line for text and echo it,\n"
"displays how many lines contained the text.",
"<input file> <text>",
"file.txt Hello"
},

{
"cfindi",
"search each line for text and echo it (case insensitive),\n"
"displays how many lines contained the text.",
"<input file> <text>",
"file.txt hello"
},

{
"charaftr",
"makes a copy of the file with the specified character after each byte.",
"<input file> <output file> <character>",
"data.txt newdata.txt \" \""
},

{
"charbefr",
"makes a copy of the file with the specified character before each byte.",
"<input file> <output file> <character>",
"data.txt newdata.txt x"
},

{
"charfile",
"makes a file containing a single character you specify the\n"
"amount of times you specify.",
"<output file> <size in bytes> <character>",
"aaa.txt 1000 a"
},


{
"charsort",
"Makes a copy of a file sorting all the characters in ascending binary order.",
"<input file> <output file>",
"example.bin sorted.bin"
},


{
"charwrap",
"wraps characters to the specified width.",
"<input file> <output file> <width to wrap>",
"a.out a.70 70"
},

{
"chchar",
"changes the specified character in a file to a new character.",
"<input file> <output file> <orginal char> <changed char>",
"readme.txt readmeo.txt 0 O"
},

{
"chchars",
"changes the specified characters in a file to new characters.",
"<input file> <outputfile> <old chars list> <new chars list>",
"readme.txt funny.txt \"abc\" \"@8<\""
},

{
"chstr",
"changes the specified string in a text file to a new string.",
"<input file> <output file> <original string> <changed string>",
"input.txt output.txt string new_string"
},

{
"coffset",
"shows the characters in a file from the offset (start and end)\n"
"you specify to the screen.",
"<input file> <start range> <end range>",
"a.out 30 213"
},

{
"compare",
"compares two files.",
"<input file 1> <input file 2>",
"hi.txt hello.txt"
},

{
"copyfile",
"copies a file.",
"<input file> <output file>",
"license.txt lbackup.txt"
},

{
"copyoffs",
"copies the characters in a file from the offset (start and end)\n"
"you specify to a new file.",
"<input file> <start range> <end range> <output file>",
"a.out 10 345 a.bin"
},

{
"copyself",
"copies the najitool program to a new name.",
"<output file>",
"naji2"
},

{
"cpfroml",
"Makes a copy of a text file copying only from the specified line number.\n"
"This is useful if you get an error importing a large MySQL .sql file and\n"
"it stops with and error giving you the line number the error occured, you\n"
"can use this to make a copy of the .sql file to continue from the error.",
"<from line number> <input file> <output file>",
"1032 database.sql dbconerr.sql"
},

{
"cptiline",
"Makes a copy of a text file copying only up to the specified line number.",
"<until line number> <input file> <output file>",
"10 readme.txt read10l.txt"
},

{
"credits",
"shows the names and details of najitool and\n"
"libnaji contributors and their original author.",
"",
""
},

{
"database",
"makes a text file with a list of people and their details.",
"",
""
},

{
"datetime",
"shows the current date and time.",
"",
""
},

{
"dayofmon",
"shows the day of the current month.",
"",
""
},

{
"dos2unix",
"converts DOS/Windows text files to UNIX format.",
"<input file> <output file>",
"hello.txt HELLO"
},

{
"downlist",
"Makes a HTML file from a text file with a list of files to download.",
"<input file> <output file>",
"download.txt download.htm"
},

{
"dumpoffs",
"shows the hexidecimal values of characters in a file\n"
"from the offset (start and end) you specify to the screen.",
"<input file> <start range> <end range>",
"a.out 30 213"
},

{
"e2ahtml",
"English to Arabic transliteration system. Makes Arabic\n"
"letters out of English letters. This version does that with\n"
"a plain text file to a HTML file. Download the transliteration\n"
"table from http://najitool.sf.net/ for details.",
"<input file> <output file>",
"enleters.txt arabic.htm"
},

{
"ebc2asc",
"convert EBCDIC format files to ASCII format files.",
"<input file> <output file>",
"readme.ebc readme.txt"
},

{
"eng2arab",
"English to Arabic transliteration system. Makes Arabic\n"
"letters out of English letters. Download the transliteration\n"
"table from http://najitool.sf.net/ for details.",
"<input file> <output file>",
"english.txt arabiyya.txt"
},

{
"engnum",
"a list of numbers in English words from 1 to 9999.",
"",
""
},

{
"eremline",
"makes a copy of a file removing lines\n"
"ending with a certain word or sentence.",
"<text> <input file> <output file>",
"\"*/\" prog2.c prog3.c"
},

{
"f2lower",
"makes a copy of a file with all the\n"
"capital letters turned into small letters.",
"<input file> <output file>",
"capitals.txt small.txt"
},

{
"f2upper",
"makes a copy of a file with all the\n"
"small letters turned into capital letters.",
"<input file> <output file>",
"small.txt big.txt"
},

{
"filbreed",
"breeds two files i.e. the first byte of the first file\n"
"then the first byte of the second file are added to the\n"
"new file and the following bytes one file after another.",
"<input file 1>  <input file 2> <output file>",
"in.txt in2.txt out.txt"
},

{
"file2bin",
"makes a file into a stream of 1 and 0 binary numbers.",
"<input file> <output file>",
"readme.txt binary.txt"
},

{
"file2dec",
"makes a file into a stream of decimal numbers.",
"<input file> <output file>",
"readme.txt decimal.txt"
},

{
"file2hex",
"makes a file into a stream of hexidecimal values.",
"<input file> <output file>",
"readme.txt hex.txt"
},

{
"filechop",
"splits a file into two new files at the offset you specify.",
"<offset> <input file> <output file 1> <output file 2>",
"2000000000 hello.vob hello1.vob hello2.vob"
},

{
"filejoin",
"joins two files into a new file.",
"<input file 1> <input file 2> <output file>",
"hello1.vob hello2.vob hello.vob"
},

{
"fillfile",
"changes every character in a file to the character you specify.",
"<output file> <character>",
"hello.txt x"
},

{
"find",
"search each line for text and echo it.",
"<input file> <text>",
"file.txt Hello"
},

{
"findi",
"search each line for text and echo it (case insensitive).",
"<input file> <text>",
"file.txt hello"
},

{
"flipcopy",
"\ncopies while flipping the bits of each byte, for example\n"
"11110000 becomes\n"
"00001111\n"
"and\n"
"01010101 becomes\n"
"10101010 etc",
"<input file> <output file>",
"hi.txt hifliped.txt"
},

{
"freverse",
"makes a reversed copy of the file, the start of\n"
"the file becomes the end of the file and vice versa.",
"<input file> <output file>",
"readme.txt emdear.txt"
},

{
"fswpcase",
"makes a copy of a file with the case of letters swapped, i.e.\n"
"if it's capital letters, they become small letters and vice versa.",
"<input file> <output file>",
"ReadMe.txt rEAD_mE.txt"
},

{
"ftothe",
"makes a copy of a file adding the text \" to the\"\n"
"after every character except the last character.",
"<input file> <output file>",
"readme.txt readtoda.txt"
},

{
"gbsplit",
"splits the file you specify into the size of pieces you specify in gigabytes.\n"
"The output file is the original filename with numbered extensions e.g.\n"
"example.big.0, example.big.1, example.big.2...\n"
"You can use mjoin to join the files.",
"<input file> <size of pieces in gb>",
"example.big 4"
},

{
"genhelp",
"generates the najitool help file.",
"",
""
},

{
"genlic",
"generates the najitool and libnaji license.",
"",
""
},

{
"getlinks",
"saves only the links in a HTML file to a text file.",
"<input file> <output file>",
"yo.htm yo_links.txt"
},

{
"gdivide",
"Calculates a list of division from start to end value.\n",
"<start number> <end number>",
"1 12"
},

{
"gigabyte",
"Calculates the number of bytes, kilobytes, and megabytes for the specified\n"
"gigabytes.",
"<gigabytes>",
"1"
},

{
"gminus",
"Calculates a list of subtractions from start to end value.\n",
"<start number> <end number>",
"1 12"
},

{
"gplus",
"Calculates a list of addition from start to end value.\n",
"<start number> <end number>",
"1 12"
},


{
"gtimes",
"Calculates a list of multiplication from start to end value.\n",
"<start number> <end number>",
"1 12"
},


{
"help",
"Help for najitool. Shows a list of najitool commands,\n"
"shows a list of help catagories, gives detailed\n"
"information on a particular najitool command.",
"\nnajitool help <catagory>\nnajitool help <command>",
"\nnajitool help commands\nnajitool help bin2c"
},

{
"hexicat",
"dumps the file you specify in hexidecimal to screen with the\n"
"displayable text characters on the right.",
"<input file>",
"a.out"
},

{
"hilist",
"Makes a HTML file from a text with a list of image names, showing\n"
"the images when the HTML file is opened in a web browser.",
"<input file> <output file>",
"pic_list.txt gallery.htm"
},

{
"hmaker",
"makes function prototypes of a .c and shows to the screen.",
"<input file>",
"mycode.c"
},

{
"hmakerf",
"makes a .h file with the function prototypes of a .c file.",
"<input file> <output file>",
"mycode.c mycode.h"
},

{
"howline",
"counts how many lines there are in a text file\n"
"and and displays the number to the screen.",
"<input text file>",
"lafterl.txt"
},

{
"html_db",
"makes a HTML file with a list of people and their details.",
"",
""
},

{
"html2txt",
"makes a text file out of a HTML file.",
"<input file> <output file>",
"homepage.htm homepage.txt"
},

{
"htmlfast",
"makes a HTML file out of a text file preserving the spaces.",
"<input file> <output file>",
"asciiart.txt asciiart.html"
},

{
"htmlhelp",
"generates the najitool help in HTML format.",
"",
""
},

{
"istrael",
"inserts string at every line at the specified position.",
"<text string> <position> <input file> <output file>",
"hello 0 todo.txt hitodo.txt"
},

{
"istreml",
"inserts string at every empty line.",
"<text string> <input file> <output file>",
"hello todo.txt hitodo.txt"
},

{
"kbsplit",
"splits the file you specify into the size of pieces you specify in kilobytes.\n"
"The output file is the original filename with numbered extensions e.g.\n"
"example.big.0, example.big.1, example.big.2...\n"
"You can use mjoin to join the files.",
"<input file> <size of pieces in kb>",
"example.big 98078"
},


{
"kitten",
"Shows the contents of a file to the screen.\n"
"Accepts input from stdin (standard input).",
"\nnajitool kitten <input file>",
"\nnajitool kitten readme.txt"
},

{
"lcharvar",
"shows every single combination variation of a sentence or word\n"
"starting from the left to the screen.",
"<text>",
"\"hello world\""
},


{
"lcvfiles",
"makes files with every single combination variation of the specified input file\n"
"starting from the beginning of the specified file. The outputed files will have\n"
"an lcv-number prefix in their filenames.",
"<input file>",
"charsort_ed_file.bin"
},


{
"leetfile",
"converts a normal text file into a \"hacker language\" text file.",
"<input file> <output file>",
"readme.txt w00t.txt"
},

{
"leetstr",
"shows a \"hacker language\" version of a sentence or word you give it.",
"<text>",
"\"hello how are you doing today?\""
},

{
"length",
"convert between the most popular length formats:\n"
"mm, cm, inches, meters, feet, yards, km, miles.",
"",
""
},

{
"lensortl",
"sort lines in a text file by length, longest first.",
"<input file> <output file>",
"file1.txt file2.txt"
},

{
"lensorts",
"sort lines in a text file by length, shortest first.",
"<input file> <output file>",
"file2.txt file3.txt"
},

{
"license",
"shows the najitool and libnaji license to the screen.",
"",
""
},

{
"linesnip",
"make a copy of a file with the amount of characters\n"
"you specify to be removed from the front of each line.",
"<amount of chars> <input file> <output file>",
"4 numbered.c filtered.c"
},

{
"lineback",
"displays lines in a text file backwards,\n"
"starting from the last line to the first line",
"<input text file>",
"dramatic.txt"
},

{
"listdigt",
"makes a text file with every possible combinations\n"
"of characters from 0 to 9 (numbers) one line after another at\n"
"the length you specify.",
"<length> <output file>",
"6 0-9_6.txt"
},

{
"listlowr",
"makes a text file with every possible combinations\n"
"of characters from a to z (small letters) one line after another at\n"
"the length you specify.",
"<length> <output file>",
"6 a-z_6.txt"
},


{
"listprnt",
"makes a text file with every possible combinations\n"
"of printable characters from ! to ~ (ASCII values 33 to 126) one line after another at\n"
"the length you specify.",
"<length> <output file>",
"6 all_6.txt"
},


{
"listuppr",
"makes a text file with every possible combinations\n"
"of characters from A to Z (capital letters) one line after another at\n"
"the length you specify.",
"<length> <output file>",
"6 A-Z_6.txt"
},

{
"longline",
"finds the longest line in a text file\n"
"and displays the number to the screen",
"<input text file>",
"lafterl.txt"
},

{
"makarray",
"makes a char *[] array out of a text file\n"
"with each item on a new line.",
"<input file> <output file> <array name>",
"zoolist.txt zoo.c zoo_animals"
},

{
"mathgame",
"a fun and educational math game.",
"",
""
},

{
"mbsplit",
"splits the file you specify into the size of pieces you specify in megabytes.\n"
"The output file is the original filename with numbered extensions e.g.\n"
"example.big.0, example.big.1, example.big.2...\n"
"You can use mjoin to join the files.",
"<input file> <size of pieces in mb>",
"example.big 4481"
},


{
"mergline",
"merges the lines of two files into a new file and lets you\n"
"specify text that comes at the beginning and end of each line.",
"<in file 1> <in file 2> <out file> <text start> <text end>",
"namlower.txt namupper.txt rename.sh \"mv -i \" \"\""
},


{
"mjoin",
"joins files split with bytsplit, kbsplit, mbsplit, or gbsplit.\n"
"specify the filename without the numbered extensions e.g.\n"
"if the files are example.big.0, example.big.1 example.big.2 then\n"
"you specify example.big as the original filename and they will be\n"
"joined automatically to the new output filename.",
"<original filename> <new output filename>",
"example.big joined_example.big"
},

{
"mkpatch",
"makes a patch file to be used with qpatch out of differences\n"
"between two files of the same size.",
"<input file 1> <input file 2> <output file>",
"cool.exe cool2.exe cool.nqp"
},

{
"month",
"shows the current month.",
"",
""
},

{
"mp3split",
"split CBR (Constant Bit Rate) MP3 file\n"
"from <start> to <end> in seconds range.",
"<start> <end> <input file> <output file>",
"1 100 test.mp3 test2.mp3"
},

{
"mp3taged",
"edit MP3 tag information, only ID3v1 tags supported in this version.",
"{<tag> <string>}..\n"
"\nTag (ID3v1 only supported):\n"
"\ttitle\t\t\t- specify song title\n"
"\tartist\t\t\t- specify artist\n"
"\talbum\t\t\t- specify album\n"
"\tyear\t\t\t- specify year\n"
"\tcomment\t\t\t- specify comment\n"
"\ttrack\t\t\t- specify track number\n",
"artist hello test.mp3"
},

{
"mp3tagnf",
"shows MP3 tag information.",
"<input file>",
"lecture.mp3"
},

{
"n2ch",
"converts new lines of UNIX and DOS/Windows text files to specified character.",
"<character> <input file> <output file>",
"\";\" dirlist.txt path.txt"
},

{
"n2str",
"converts new lines of UNIX and DOS/Windows text files to specified string.",
"<string> <input file> <output file>",
"\"-->\" dirlist.txt dirlead.txt"
},


{
"najcrypt",
"naji interactive encryption/decryption function.",
"",
""
},

{
"naji_bmp",
"generates lots of predefined .BMP file images.",
"",
""
},

{
"najirle",
"naji RLE (Run-Lengh Encoding) compression on a single file.\n"
"Works best with files with a lot of repeated characters, such as wave files.",
"<input file> <output file>",
"uncomped.wav uncomped.nar"
},

{
"najisum",
"naji checksum function.",
"<input file>",
"checksum.txt"
},

{
"numlines",
"add numbers to the beginning of every line.",
"<input file> <output file>",
"list.txt numlist.txt"
},

{
"onlalnum",
"makes a copy of a file copying only letters and numbers.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlalpha",
"makes a copy of a file copying only letters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlcntrl",
"makes a copy of a file copying only control characters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onldigit",
"makes a copy of a file copying only numbers.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlgraph",
"makes a copy of a file copying only visible\n"
"printing characters, spaces are not included.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onllower",
"makes a copy of a file copying only lower case letters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlprint",
"makes a copy of a file copying only printing\n"
"characters, which includes the space character.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlpunct",
"makes a copy of a file copying only punctuation.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlspace",
"makes a copy of a file copying only whitespace, that is,\n"
"carriage return, newline, form feed, tab, vertical tab, or space.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlupper",
"makes a copy of a file copying only upper case letters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlxdigt",
"makes a copy of a file copying only\n"
"hexadecimal digits, this includes 0-9 a-f A-F.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"onlycat",
"shows the contents of the file you specify\n"
"using only the characters you specify.",
"<input file> <text>",
"readme.txt \"abc\""
},

{
"onlychar",
"makes a copy of the file you specify using only\n"
"the characters you specify.",
"<input file> <output file> <characters>",
"readme.txt abc.txt \"abc\""
},

{
"patch",
"manually patch a file in an interactive text based interface.",
"<output file>",
"cool2.exe"
},

{
"printftx",
"makes a copy of a text file into a .c file as printf statements.",
"<input file> <output file>",
"shortdoc.txt shortdoc.c"
},

{
"putlines",
"makes a copy of the file you specify with text you specify for\n"
"the beginning and end of each line.",
"<input file> <output file> <start line text> <end line text>",
"input.txt output.txt \"hello\" \"world\""
},

{
"qcrypt",
"encrypts or decrypts a file to a new file, this does both\n"
"encryption and decryption.",
"<input file> <output file>",
"secret.txt what.txt"
},

{
"qpatch",
"\npatches a file from a patch file, it must be in format:\n"
"offset\n"
"value\n"
"offset\n"
"value\n"
"etc.\n"
"in plain ASCII numbers, offset being the place in the file you want\n"
"to patch and value being the new value (a value between 0-255).",
"<output file> <input patch file>",
"cool.exe cool.nqp"
},

{
"randkill",
"changes every character in a file to a random character\n"
"and then deletes it, this is good for secure deletion.",
"<file to delete>",
"secret.txt"
},

{
"rbcafter",
"makes a copy of the file with a random\n"
"binary character after each line.",
"<input file> <output file>",
"picture.raw newpic.raw"
},

{
"rbcbefor",
"makes a copy of the file with a random\n"
"binary character before each line.",
"<input file> <output file>",
"picture.raw newpic.raw"
},

{
"rcharvar",
"shows every single combination variation of a sentence or word\n"
"starting from the right to the screen.",
"<text>",
"\"hello world\""
},

{
"rcvfiles",
"makes files with every single combination variation of the specified input file\n"
"starting from the end of the specified file. The outputed files will have\n"
"an rcv-number prefix in their filenames.",
"<input file>",
"charsort_ed_file.bin"
},

{
"remline",
"makes a copy of a file removing lines\n"
"containing a certain word or sentence.",
"<text to remove> <input file> <output file>",
"\"badword\" bad.txt clean.txt"
},

{
"removel",
"remove the specified line and all its line contents.",
"<input text file> <output file> <line number>",
"todo.txt done.txt 10"
},

{
"repcat",
"repeats each character in a file the\n"
"number of times you specify to the screen.",
"<input file> <number of repeats>",
"hmm.txt 3"
},

{
"repcatpp",
"give it a start value and it repeats each character in a\n"
"file then repeats the next character in the file more amount\n"
"of times than the previous character to the screen.",
"<input file> <start number of repeats>",
"hmmmmmmm.txt 3"
},

{
"repchar",
"repeats each character in the file you specify the\n"
"number of times you specify to a new file.",
"<input file> <output file> <number of repeats>",
"hello.wav helloslow.wav 1"
},

{
"repcharp",
"give it a start value and it repeats each character in a\n"
"file then repeats the next character in the file more amount\n"
"of times than the previous character to a new file.",
"<input file> <output file> <start number of repeats>",
"hi.wav hislower.wav 1"
},

{
"replacel",
"replaces specified line contents with the specified text.",
"<input text file> <output file> <new line text> <line number>",
"version1.txt version2.txt \"version v2\" 10"
},

{
"revcat",
"shows a file reversed to the screen.",
"<input file>",
"reverse.txt"
},

{
"revlines",
"reverses every line the file you specify to a new file.",
"<input file> <output file>",
"input.txt output.txt"
},

{
"rmunihtm",
"deletes the files that unihtml generates.",
"",
""
},

{
"rndbsout",
"puts random characters from value 0 to 255 to the standard output\n"
"(usually the screen) at the size you specify.",
"<size>",
"100"
},


{
"rndffill",
"changes every character in a file to a random character.",
"<edit file>",
"todelete.txt"
},

{
"rndlines",
"randomizes/shuffles every line in a text file and displays it to the screen",
"<input text file>",
"tipofday.txt"
},

{
"rndtsout",
"puts random text characters to the standard output\n"
"(usually the screen) at the size you specify.",
"<size>",
"64"
},

{
"rndbfile",
"generates a file with random characters from value 0 to 255\n"
"at the size you specify.",
"<output file> <size>",
"random.bin 5435346"
},

{
"rndtfile",
"generates a file with random text characters at the size you specify.\n"
"Useful for generating secure random passwords.",
"<output file> <size>",
"random.txt 5435346"
},

{
"rrrchars",
"random range repeat characters.",
"<input file> <output file> <min number> <max number>",
"test.wav test2.wav 1 10"
},

{
"rstrach",
"makes a copy of a file with random text at\n"
"the size you specify after each character.",
"<size> <input file> <output file>",
"10 test.bin ra10test.bin"
},

{
"rstrbch",
"makes a copy of a file with random text at\n"
"the size you specify before each character.",
"<size> <input file> <output file>",
"10 test.bin rb10test.bin"
},

{
"rtcafter",
"makes a copy of the file with a random text character after each line.",
"<input file> <output file>",
"data.txt newdata.txt"
},

{
"rtcbefor",
"makes a copy of the file with a random text character before each line.",
"<input file> <output file>",
"data.txt newdata.txt"
},

{
"saat",
"shows the time.",
"",
""
},

{
"saatarih",
"shows the current date and time in Turkish.",
"",
""
},

{
"showline",
"shows the contents of a line you specify.",
"<input file> <line number>",
"readme.txt 3"
},

{
"skipcat",
"shows the contents of a file to the screen skipping\n"
"the characters you specify. Useful for seeing how\n"
"a file would look without certain characters",
"<input file> <characters to skip>",
"readme.txt \"#$&*\""
},

{
"skipchar",
"makes a copy of the file you specify skipping\n"
"the characters you specify.",
"<input file> <output file> <chars to skip>",
"readme.txt readme2.txt \"#$&*\""
},

{
"skipstr",
"makes a copy of a file skipping the specified string.",
"<input file> <output file> <text to skip>",
"input.txt output.txt \"badword\""
},

{
"skpalnum",
"makes a copy of a file skipping letters and numbers.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpalpha",
"makes a copy of a file skipping letters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpcntrl",
"makes a copy of a file skipping control characters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpdigit",
"makes a copy of a file skipping numbers.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpgraph",
"makes a copy of a file skipping visible\n"
"printing characters, spaces are not included.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skplower",
"makes a copy of a file skipping lower case letters.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpprint",
"makes a copy of a file skipping printing\n"
"characters, which includes the space character.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skppunct",
"makes a copy of a file skipping punctuation.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"skpspace",
"makes a copy of a file skipping whitespace, that is, carriage\n"
"return, newline, form feed, tab, vertical tab, or space.",
"<input file> <output file>",
"a.out filtered.bin"
},
 
{
"skpupper",
"makes a copy of a file skipping upper case letters.",
"<input file> <output file>",
"a.out filtered.bin"
},
 
{
"skpxdigt",
"makes a copy of a file skipping\n"
"hexadecimal digits, this includes 0-9 a-f A-F.",
"<input file> <output file>",
"a.out filtered.bin"
},

{
"sort",
"sorts a text file ordering each line according to ASCII value.",
"<input text file>",
"unsorted.txt > sorted.txt"
},

{
"sortlast",
"sorts a text file ordering each line according to ASCII value - backwards.",
"<input text file>",
"unsorted.txt > sorted.txt"
},

{
"sp2ce2sp",
"changes spaces to the specified character,\n"
"changes everything else to space character.",
"<character> <input file> <output file>",
"X todo.txt xoxo.txt"
},

{
"sp2re2sp",
"changes spaces to a random text character,\n"
"changes everything else to space character.",
"<input file> <output file>",
"todo.txt roro.txt"
},

{
"spyramid",
"Makes a pyramid out of the specified string (text).\n"
"That is to say, give it the text hello and it makes\n"
"something like:\n"
"n\n"
"ne\n"
"new\n"
"ne\n"
"n",
"<text>",
"hello"
},

{
"strachar",
"makes a copy of a file with the specified text after each character.",
"<text> <input file> <output file>",
"\" HELLO \" test.txt hitest.txt"
},

{
"strbchar",
"makes a copy of a file with the specified text before each character.",
"<text> <input file> <output file>",
"\" HELLO \" test.txt hitest.txt"
},

{
"strbline",
"puts a word or sentence on the beginning of every line.",
"<input file> <output file> <text>",
"hi.txt new_hi.txt \"hello start\""
},

{
"streline",
"puts a word or sentence on the end of every line.",
"<input file> <output file> <text>",
"hi.txt new_hi.txt \"hello end\""
},

{
"strfile",
"makes a file out of a string (word or sentence) and repeats the\n"
"string in the file that is made the number of times you specify.",
"<output file> <number of reps> <text>",
"what.txt 11 \"what is this?\""
},

{
"swapfeb",
"swaps every other byte of two files",
"<input file 1> <input file 2> <output file>",
"in.txt in2.txt out.txt"
},

{
"systemdt",
"shows the current date and time (asctime format).",
"",
""
},

{
"tabspace",
"converts tabs to spaces with the number of spaces for\n"
"a tab you specify.",
"<size of spaces> <input file> <output file>",
"4 hello.txt hi_notab.txt"
},

{
"telltime",
"shows the time.",
"",
""
},

{
"today",
"shows what day it is today.",
"",
""
},

{
"tothe",
"Adds the text \" to the\" after every character\n"
"except the last character and displays it to the screen.",
"<text>",
"NAJI"
},

{
"ttt",
"A fun Tic-Tac-Toe game with clever AI.\n"
"This game is also called Norts and Crosses in the UK.",
"",
""
},

{
"turnum",
"a list of numbers in Turkish words from 1 to 9999.",
"",
""
},

{
"txt2html",
"makes a HTML file out of a text file.",
"<input file> <output file>",
"readme.txt readme.htm"
},

{
"unihtml",
"generates HTML pages with every possible Unicode letter/symbol.",
"",
""
},

{
"unajirle",
"decompresses a file compressed with najirle.",
"<input file> <output file>",
"uncomped.nar uncomped.wav"
},

{
"unblanka",
"converts a blanka format file back to its original format.",
"<input file> <output file>",
"secret.txt myfile2.txt"
},

{
"unix2dos",
"converts UNIX text files to DOS/Windows format.",
"<input file> <output file>",
"BYE bye.txt"
},

{
"uudecode",
"UUDecode a UUEncoded file.",
"<input file> <output file>",
"hello.uue hello.exe"
},

{
"uuencode",
"UUEncode a binary file to be easily sent with e-mail\n"
"or posted on forums, etc.",
"<input file> <output file>",
"program.exe program.uue"
},


{
"vowelwrd",
"puts vowels inbetween every letter of a word except the first and last letter.\n",
"<word>",
"Flz"
},

{
"weakrypt",
"a weak file encryption function, the same function\n"
"does both encryption and decryption with a password.",
"<password> <input file> <output file>",
"helloworld1234567890abc secret.zip secret.nwk"
},

{
"wordline",
"puts words in sentences in a new line like a word list.",
"<input file> <output file>",
"license.txt licelist.txt"
},

{
"wordwrap",
"wraps text to new lines for files that have all the text on one line.",
"<input file> <output file>",
"readme.txt read.txt"
},

{
"wrdcount",
"counts the number of words in a text file and displays the number.",
"<text input file>",
"my_essay.txt"
},

{
"year",
"shows the current year.",
"",
""
},

{
"yil",
"shows the current year.",
"",
""
},

{
"zerokill",
"changes every character in a file to the hexidecimal value 00\n"
"and then deletes it, this is good for secure deletion.",
"<file to delete>",
"secret.txt"
}


};




void najitool_help_commands(void)
{
int i;
int j;
int items = 0;
int len = 0;
int spaces = 0;
int lines = 0;

printf("\n   ");


        for(i=0; i<NAJITOOL_MAX_COMMANDS; i++)
        {


        len = strlen(najitool_valid_commands[i]);

	for (j=1; j<=8; j++)
	if (len == j) spaces = 8 - j;

        printf(najitool_valid_commands[i]);

        if (spaces > 0)
        for (j=0; j<spaces; j++)
        putchar(' ');

        for (j=0; j<3; j++)
        putchar(' ');


        items++;

            if (items == 7)
            {
            printf("\n\n   ");
            items = 0;

            lines++;
            }


            if (lines == 7)
            {
            nextpage();
            printf("   ");
            lines = 0;
            }

        }


}




void najitool_command_help(char *cmd)
{
int i;

  for (i=0; i<NAJITOOL_MAX_COMMANDS; i++)
  if (!strcmp(cmd, helpitems[i].cmd))
  {
  printf("\n\n");
  printf("COMMAND: %s\n\n",        helpitems[i].cmd);
  printf("DESCRIPTION:\n%s\n\n", helpitems[i].info);

  printf("USAGE:\nnajitool %s %s\n\n",
  helpitems[i].cmd, helpitems[i].usage);
 
  printf("EXAMPLE:\nnajitool %s %s\n\n",
  helpitems[i].cmd, helpitems[i].example);

  exit(0);
  }

}




void najitool_generate_help(void)
{
int i;



najout("HELP");



fprintf(naji_output, "\n\n");

fprintf(naji_output, "  =-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
fprintf(naji_output, "  najitool 0.8.4 Help Document\n");
fprintf(naji_output, "  =-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

fprintf(naji_output, "     http://najitool.sf.net/\n\n");

fprintf(naji_output, "   Written by NECDET COKYAZICI\n\n\n");


fprintf(naji_output, "-----------------------------------------------------------------------------");

fprintf(naji_output, "\n%i TOTAL NUMBER OF NAJITOOL COMMANDS:\n", NAJITOOL_MAX_COMMANDS);

fprintf(naji_output, "-----------------------------------------------------------------------------");


  for (i=0; i<NAJITOOL_MAX_COMMANDS; i++)
  {


  fprintf(naji_output, "\n\n");
  fprintf(naji_output, "COMMAND: %s\n\n",        helpitems[i].cmd);
  fprintf(naji_output, "DESCRIPTION:\n%s\n\n", helpitems[i].info);

  fprintf(naji_output, "USAGE:\nnajitool %s %s\n\n",
  helpitems[i].cmd, helpitems[i].usage);
 
  fprintf(naji_output, "EXAMPLE:\nnajitool %s %s\n\n",
  helpitems[i].cmd, helpitems[i].example);

  fprintf(naji_output, "-----------------------------------------------------------------------------");

  }



najoutclose();

unix2dos("HELP", "help.txt");

exit(0);
}




void najitool_generate_help_html(void)
{
int i;
int j;

najout("help.htm");



fprintf(naji_output, "<html>\n\n");


fprintf(naji_output, "<head> <title>najitool 0.8.4 Help Document</title> </head>\n\n");

fprintf(naji_output, "<body>\n\n");

fprintf(naji_output, "\n\n");

fprintf(naji_output, "<center>\n\n");

fprintf(naji_output, "<h2>najitool 0.8.4 Help Document</h2><p>\n\n");

fprintf(naji_output, "<a href=\"http://najitool.sf.net/\">http://najitool.sf.net/</a><p>\n\n");

fprintf(naji_output, "<b>Written by NECDET COKYAZICI</b><br><p>\n\n\n");


fprintf(naji_output, "</center>\n\n");


  fprintf(naji_output, "\n<hr>\n");

  fprintf(naji_output, "<b>%i TOTAL NUMBER OF NAJITOOL COMMANDS:</b><br>\n", NAJITOOL_MAX_COMMANDS);

  fprintf(naji_output, "\n<hr>\n");




  for (i=0; i<NAJITOOL_MAX_COMMANDS; i++)
  {





  fprintf(naji_output, "\n\n<p>");





  fprintf(naji_output, "<b>COMMAND:</b> %s\n\n<p>",        helpitems[i].cmd);




  fprintf(naji_output, "<b>DESCRIPTION:</b><br>\n");


  for (j=0; helpitems[i].info[j] != '\0'; j++)
  {
  
  if (helpitems[i].info[j] == '\n')
  fprintf(naji_output, "\n<br>");

  else if (helpitems[i].info[j] == '<')
  fprintf(naji_output, "&lt;");

  else if (helpitems[i].info[j] == '>')
  fprintf(naji_output, "&gt;");

  else fputc(helpitems[i].info[j], naji_output);
  }

  fprintf(naji_output, "\n\n<p>");




  fprintf(naji_output, "<b>USAGE:</b><br><i>\nnajitool");
  
  fprintf(naji_output, " %s ", helpitems[i].cmd);


  for (j=0; helpitems[i].usage[j] != '\0'; j++)
  {

  if (helpitems[i].usage[j] == '\n')
  fprintf(naji_output, "\n<br>");

  else if (helpitems[i].usage[j] == '<')
  fprintf(naji_output, "&lt;");

  else if (helpitems[i].usage[j] == '>')
  fprintf(naji_output, "&gt;");

  else fputc(helpitems[i].usage[j], naji_output);
  }

  fprintf(naji_output, "\n\n</i><p>");





  fprintf(naji_output, "<b>EXAMPLE:</b><br>\nnajitool");

  fprintf(naji_output, " %s ", helpitems[i].cmd);


  for (j=0; helpitems[i].example[j] != '\0'; j++)
  {

  if (helpitems[i].example[j] == '\n')
  fprintf(naji_output, "\n<br>");

  else if (helpitems[i].example[j] == '<')
  fprintf(naji_output, "&lt;");

  else if (helpitems[i].example[j] == '>')
  fprintf(naji_output, "&gt;");

  else fputc(helpitems[i].example[j], naji_output);
  }


  fprintf(naji_output, "\n\n<p>");




  fprintf(naji_output, "\n<hr>\n");

  }


fprintf(naji_output, "\n\n</body>\n\n");

fprintf(naji_output, "</html>\n\n");


najoutclose();


exit(0);
}
