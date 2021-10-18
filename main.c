#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void welcome() {
   char input[3];
   system("clear");
   printf("========================================================\n");
   printf("\n");
   printf("   ##### # ####    #####  #   ####    ##### #### ####   \n");
   printf("     #   # #         #   ###  #         #   #  # ####   \n");
   printf("     #   # ####      #  #   # ####      #   #### ####   \n");
   printf("\n");
   printf("========================================================\n");

   printf("\n");
   printf("                      x | o | x \n");
   printf("                     -----------\n");
   printf("                        | x |   \n");
   printf("                     -----------\n");
   printf("                      o |   | x \n"); 
   printf("\n");

   printf("\n");
   printf("Permainan Game Console Tic Tac Toe\n");
   printf("dibuat oleh Hanina Nafisa Azka (<NIM Hanina>)\n");

   printf("\n");
   printf("\nTekan 'enter' untuk melanjutkan ...");
   fgets(input, 3, stdin);
}

void instruction() {
   char input[1]; 
   system("clear");
   printf("<Tuliskan cara bermain>");
   printf("\n");
   input[0] = 'x';
   do {
      printf("Tulis 'y' untuk melanjutkan ...\n");
      scanf("%s", input);
   } while (input[0] != 'y');
}

int play() {
   char board[3][3];
   char input[3];
   int moveTo;
   int turn = 0;
   char player;

   initBoard(board);

   while (1)
   {
      player = (turn % 2) ? 'o' : 'x';
      system("clear");
      drawBoard(board);

      if (state(board) == 1)
      {
         printf("\nWinner!\n");
         return 0;
      }

      if (state(board) == -1)
      {
         printf("\nDraw!\n");
         return 0;
      }

      printf("\n(turn #%i) To which square would you (player %c) like to move? ", turn+1, player);
      fgets(input, 3, stdin);
      moveTo = atoi(input);

      if (mv(board, moveTo, player))
         turn++;

      printf("\n");
   }

   return -1;
}

void menu_view() {
   system("clear");
   printf("===============\n");
   printf("  Tic Tac Toe  \n");
   printf("===============\n");
   printf("1. Instruksi\n");
   printf("2. Mainkan\n");
   printf("3. Keluar\n");
}

void menu() {
   int choice;
   char input[3];

   do {
      menu_view();
      printf("Masukkan pilihan (1-3) : ");
      scanf("%d", &choice);   
      switch (choice) {
         case 1:
            instruction();
            break;
         case 2:
            play();
            break;
         case 3:
            exit(0);
         default:
            continue;
      }
   } while (choice != 3);
}

int main(int argc, char* argv[]) {

   welcome();
   menu();

   return 0;
}
