#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define True 1


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

void yPrompt(){
   char input[1];
   input[0] = FIRST_MARK;
   do {
      printf("Tulis 'y' untuk kembali ke menu utama ...\n");
      scanf("%s", input);
   } while (input[0] != 'y');
}

void instruction() {
   system("clear");
   printf("<Tuliskan cara bermain>");
   printf("\n");
   yPrompt();
}

int initPlayers(){
   int player_num = 0;

   while (player_num != 1 & player_num != 2){
      system("clear");
      printf("===============\n");
      printf("  Tic Tac Toe  \n");
      printf("===============\n");
      printf("1. Single Player (bermain dengan komputer)\n");
      printf("2. Multi Player\n");
      printf("Pilih jenis permainan (1-2) : ");
      scanf("%d", &player_num);
   }

   return player_num;
}

int generateRandomNumber() {
   int upper = 9;
   int lower = 1;
   int num = (rand() % (upper - lower + 1)) + lower;
   return num;
}

int play() {
   char board[3][3];
   char input[3];
   int moveTo;
   int turn = 0, board_state;
   char player_mark;
   char first_player[32];
   char second_player[32];
   int player_num;
   
   player_num = initPlayers();

   printf("Masukanan nama player 1 = ");
   scanf("%s", first_player);
   if (player_num > 1) {
      printf("Masukanan nama player 2 = ");
      scanf("%s", second_player);
   } else {
      printf("Anda bermain dengan komputer\n");
      strncpy(second_player, "Computer", 32);
   }

   initBoard(board);

   while (True) {
      system("clear");
      drawBoard(board);

      board_state = state(board);
      
      if (board_state == 1) {
         printf("%s wins!!!!\n", first_player);
         yPrompt();
         return 0;
      } else if (board_state == 2) {
         printf("%s wins!!!!\n", second_player);
         yPrompt();
         return 0;
      } else if (board_state == -1) {
         printf("\nDraw!\n");
         yPrompt();
         return 0;
      }

      if ((turn % 2) == 0) {
         printf("\n(turn #%i) To which square would you (%s) like to move? ", turn + 1, first_player);
         fgets(input, 3, stdin);
         moveTo = atoi(input);   
      } else {
         if (player_num > 1) {
            printf("\n(turn #%i) To which square would you (%s) like to move? ", turn + 1, second_player);
            fgets(input, 3, stdin);
            moveTo = atoi(input);
         } else {
            moveTo = generateRandomNumber();
         }
      }

      player_mark = (turn % 2) ? SECOND_MARK : FIRST_MARK;
      if (mv(board, moveTo, player_mark))
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
