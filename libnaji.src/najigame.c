/* ---------- */
/* najigame.c */
/* ---------- */

/* naji portable games */

/* this  .c  file is a part */
/* of libnaji version 0.6.3 */

/* libnaji is based on   */
/* the original najitool */

/* both najitool and libnaji */
/* are public domain and are */
/* made by the same author   */
/* please read license.txt   */

/* made by NECDET COKYAZICI  */

/* ttt made by SAMUEL CHANG  */


#include "libnaji.h"


unsigned long swap_ulong_var;
#define swap_ulong(a, b)  swap_ulong_var=a;   a=b;  b=swap_ulong_var;




/* global variables */
char ttt_next_turn = ' ';    /* 'h' for human and 'c' for computer */
char ttt_board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',};
char ttt_winner = ' ';
char tttbuf[1024];


void ttt(void)
{


        ttt_instructions();

        while (ttt_gameover() == ' ')
        {

           if (ttt_next_turn == 'h')
           {
           ttt_humanmove();
           ttt_displayboard();
           }

           else if (ttt_next_turn == 'c')
           {
           ttt_computermove();
           ttt_displayboard();
           }
        }

        ttt_displaywinner();

}


void ttt_instructions()
{

        printf("\n");
        printf("-----------------------------------------\n");
        printf("             Tic-Tac-Toe 1.0             \n\n");
        printf("       By Samuel Chang for najitool      \n\n");
        printf("    E-Mail/MSN: badp1ayer@hotmail.com    \n");
        printf("-----------------------------------------\n\n");

        printf("The aim of the game is to try to get 3 of your pieces \n");
        printf("in a row, be it horizontally, vertically or diagonally. \n");
        printf("Your pieces are represented by X and the computer's O. \n\n");

        printf("Make your move by entering a number from 0 to 8, \n");
        printf("corresponding to the desired board position. \n\n");

        printf("               0 | 1 | 2  \n");
        printf("               ---------- \n");
        printf("               3 | 4 | 5  \n");
        printf("               ---------- \n");
        printf("               6 | 7 | 8  \n\n");

        printf("Press q to quit at any time. \n\n");


        printf("Do you want to start first? [Y/N/Q] \n");


        printf(">>> ");



        safegets(tttbuf, 1000);


        if (tttbuf[0] == 'Y')
        tttbuf[0] = 'y';

        if (tttbuf[0] == 'N')
        tttbuf[0] = 'n';

        if (tttbuf[0] == 'Q')
        tttbuf[0] = 'q';


        while (strcmp(tttbuf, "y") &&
               strcmp(tttbuf, "n") &&
               strcmp(tttbuf, "q")
               )
               { 
                   printf("Enter either y, n or q. \n");
                   printf(">>> ");

                   safegets(tttbuf, 1000);

                   if (tttbuf[0] == 'Y')
                   tttbuf[0] = 'y';

                   if (tttbuf[0] == 'N')
                   tttbuf[0] = 'n';

                   if (tttbuf[0] == 'Q')
                   tttbuf[0] = 'q';

               }

        if (tttbuf[0] == 'y') ttt_next_turn = 'h';
        if (tttbuf[0] == 'n') ttt_next_turn = 'c';
        if (tttbuf[0] == 'q') exit(0);

        ttt_displayboard();

}



void ttt_displayboard(void)
{
        printf("               %c | %c | %c \n",   ttt_board[0], ttt_board[1], ttt_board[2]);
        printf("               ----------   \n");
        printf("               %c | %c | %c \n",   ttt_board[3], ttt_board[4], ttt_board[5]);
        printf("               ----------   \n");
        printf("               %c | %c | %c \n\n", ttt_board[6], ttt_board[7], ttt_board[8]);
}



void ttt_humanmove(void)
{
int square;

        /* Change next turn to computer */
        ttt_next_turn = 'c';


        printf("Your go. \n");
        printf(">>> ");
        safegets(tttbuf, 1000);
        if (!strcmp(tttbuf, "q")) exit(0);
        if (!strcmp(tttbuf, "Q")) exit(0);
        square = atoi(tttbuf);


        while (1)
        {

              /* check for buffer overflow */
              if (square == 0 ||
                  square == 1 ||
                  square == 2 ||
                  square == 3 ||
                  square == 4 ||
                  square == 5 ||
                  square == 6 ||
                  square == 7 ||
                  square == 8
                 )
                 {          
                     if (ttt_board[square] == ' ')
                     {
                     ttt_board[square] = 'X';
                     return;  /* Move has been made */
                     }
                 }
                 else
                 {
                 printf("Invalid selection. \n");
                 printf("Enter a number from 0 to 8. \n");

                 printf(">>> ");
                 safegets(tttbuf, 1000);
                 if (!strcmp(tttbuf, "q")) exit(0);
                 if (!strcmp(tttbuf, "Q")) exit(0);
                 square = atoi(tttbuf);
                 continue;
                 }


                 if (ttt_board[square] != ' ')
                 {
                 printf("Spot %i already taken by %c. \n", square, ttt_board[square]);
                 printf("Please choose an empty spot. \n");
                 printf("Enter a number from 0 to 8. \n");
                 printf(">>> ");
                 safegets(tttbuf, 1000);
                 if (!strcmp(tttbuf, "q")) exit(0);
                 if (!strcmp(tttbuf, "Q")) exit(0);
                 square = atoi(tttbuf);
                 }

        }



}



void ttt_computermove(void)
{
const int BESTMOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
int i;


        /* Change next turn to human */
        ttt_next_turn = 'h';
        printf("Computer's go. \n");



        /* Step 1: Check and see if the computer can win */

        for (i=0; i<9; i++)
        {
                if (ttt_board[i] == ' ')
                {
                        ttt_board[i] = 'O';

                        if (ttt_gameover() == 'c')
                        return;  /* Move has been made */

                        else ttt_board[i] = ' ';

                }
        }



        /* Step 2: Check and see if the human can win */

        for (i=0; i<9; i++)
        {
                if (ttt_board[i] == ' ')
                {
                        ttt_board[i] = 'X';

                        if (ttt_gameover() == 'h')
                        {
                        ttt_board[i] = 'O';
                        return;  /* Move has been made */
                        }

                        else ttt_board[i] = ' ';
                }
        }


        /* Step 3: Make the best possible remaining move */

        for (i=0; i<9; i++)
        {
                if (ttt_board[BESTMOVES[i]] == ' ')
                {
                ttt_board[BESTMOVES[i]] = 'O';
                return;  /* Move has been made */
                }
        }

}



char ttt_gameover(void)
{
int i;
int blankCount = 8;

const int WIN_ROWS[8][3] =
{
  {0,1,2},
  {3,4,5},
  {6,7,8},
  {0,3,6},
  {1,4,7},
  {2,5,8},
  {0,4,8},
  {2,4,6}
};


        for (i=0; i<8; i++)
        {


                if ( (ttt_board[WIN_ROWS[i][0]] == 'X') &&
                     (ttt_board[WIN_ROWS[i][0]] == ttt_board[WIN_ROWS[i][1]]) &&
                     (ttt_board[WIN_ROWS[i][1]] == ttt_board[WIN_ROWS[i][2]]) )
                     {
                     /* winner is human */
                     ttt_winner = 'h';
                     return 'h';
                     }



                if ( (ttt_board[WIN_ROWS[i][0]] == 'O') &&
                     (ttt_board[WIN_ROWS[i][0]] == ttt_board[WIN_ROWS[i][1]]) &&
                     (ttt_board[WIN_ROWS[i][1]] == ttt_board[WIN_ROWS[i][2]]) )
                     {
                     /* winner is computer */
                     ttt_winner = 'c';
                     return 'c';
                     }

        }



        for (i=0; i<8; i++)
        {
        if (ttt_board[i] != ' ')
        blankCount--;
        }

        if (blankCount == 0 && ttt_winner == ' ')
        {
        /* game is a draw */
        ttt_winner = 'd';
        return 'd';
        }

        /* game is not over */
        ttt_winner = ' ';
        return ' ';

}



void ttt_displaywinner(void)
{

        if (ttt_winner == 'h')
        printf("You Win! Well done. \n");

        if (ttt_winner == 'c')
        printf("Sorry you lose... Try again! \n");

        if (ttt_winner == 'd')
        printf("It's a Draw... Try again! \n");

}




void mathgame(void)
{
unsigned long first_number=0;
unsigned long second_number=0;

int generate_operator=0;
char math_operator='+';

char str_answer[1024];
unsigned long answer=0;

char *end;

int points=0;


rndinit();

printf("\n\n\n         Welcome to MathGame\n\n");
printf("Get the answers right to score points.\n");
printf("Get the answers wrong to lose points.\n");
printf("Type q to quit the game.\n\n");
while (1)
{


generate_operator = rand() % 4;

if (generate_operator == 0)
{
math_operator = '+';

first_number = rand() % 1000;
second_number = rand() % 1000;

}

if (generate_operator == 1)
{
math_operator = '-';

first_number = rand() % 1000;
second_number = rand() % 1000;

 if (second_number > first_number)
 swap_ulong(second_number, first_number);
}


if (generate_operator == 2)
{
math_operator = '*';

first_number = rand() % 12;
second_number = rand() % 12;
}

if (generate_operator == 3)
{
math_operator = '/';

first_number = rand() % 10;
second_number = rand() % 10;

first_number++;
second_number++;
}



 printf("\nWhat is %lu %c %lu? ", first_number, math_operator, second_number);

 safegets(str_answer, 1000);

 if (!strcmp(str_answer, "q"))
 {
 printf("\n\nFinished MathGame with %i points.\n\n", points);
 exit(0);
 }

 answer = strtoul(str_answer, &end, 0);


 if (math_operator == '+')
 {

  if (answer == (first_number + second_number))
  {
  printf("Correct! %lu + %lu == %lu\n", first_number, second_number, answer);
  points++;
  printf("You have scored a point! Current points: %i\n", points);
  }
  else
  {
  points--;
  printf("Wrong answer! you have lost a point. Current points: %i\n", points);
  }

 }

 if (math_operator == '-')
 {

  if (answer == (first_number - second_number))
  {
  printf("Correct! %lu - %lu == %lu\n", first_number, second_number, answer);
  points++;
  printf("You have scored a point! Current points: %i\n", points);
  }
  else
  {
  points--;
  printf("Wrong answer! you have lost a point. Current points: %i\n", points);
  }

 }


 if (math_operator == '*')
 {

  if (answer == (first_number * second_number))
  {
  printf("Correct! %lu * %lu == %lu\n", first_number, second_number, answer);
  points++;
  printf("You have scored a point! Current points: %i\n", points);
  }
  else
  {
  points--;
  printf("Wrong answer! you have lost a point. Current points: %i\n", points);
  }

 }

 if (math_operator == '/')
 {

  if (answer == (first_number / second_number))
  {
  printf("Correct! %lu / %lu == %lu\n", first_number, second_number, answer);
  points++;
  printf("You have scored a point! Current points: %i\n", points);
  }
  else
  {
  points--;
  printf("Wrong answer! you have lost a point. Current points: %i\n", points);
  }

 }




}


}
