#include <stdio.h>
#include <stdlib.h>

int grid[9];
void board(){
     system("cls");
     printf(" \t\tTic Tac Toe\t\t");                             //Game board
     printf("\n ----------------------------------------\n");
     printf("\n\n");
     printf("\t\t  %c | %c  | %c  \n", grid[0], grid[1], grid[2]);
     printf("\t\t----+----+----\n");
     printf("\t\t  %c | %c  | %c  \n", grid[3], grid[4], grid[5]);
     printf("\t\t----+----+---\n");
     printf("\t\t  %c | %c  | %c  \n", grid[6], grid[7], grid[8]);

}

void pvc();
void pvp();

int main() {

     int index, sign,symbol,player,x,first_sign,second_sign;
     int winner = 0, count = 0;
     FILE *file;                     //Open a file to write X and O move
     file= fopen("status.txt","w");

     for (int i = 0; i < 9; i++){
        grid[i] = ' ';
     }


     printf("\n\n\n\n\n\n\t\t\tReady to play");
     sleep(2);

     system("cls");
     printf(" \t\tTic Tac Toe\t\t");
     printf("\n ----------------------------------------\n");
     printf("\nInstructions\n");
     printf("---------------\n");
     printf("1.Enter no 1 to play with another player\n");   //choose game mode
     printf("2.Enter no 2 to play with computer\n");
     printf("\nEnter your choice:");
     scanf("%d",&x);

     printf("\nChoose X or O\n");
     printf("---------------\n");
     printf("1.Enter no 1 if you like to choose X\n");      //Player 1 choose X or O
     printf("2.Enter no 2 if you like to choose O\n");
     printf("\nEnter your choice:");
     scanf("%d",&symbol);

     if(symbol==1){       //check what is the symbol that player 1 choosed from X and O
        first_sign='X';
        second_sign='O';
     }
     else if(symbol==2){
        first_sign='O';
        second_sign='X';
     }else{
       printf("Invalid selection!");
       system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'Invalid selection!\')))\"");
       exit(1);
     }


if(x==1||x==2){
  if(x==1){
            fprintf(file, "X and O moves-Player vs Player\n");
            fprintf(file,"--------------------\n");
  }else{
            fprintf(file, "X and O moves-Player vs Computer\n");
            fprintf(file,"--------------------\n");
  }

  while (count < 9) {

        board();
        if(x==2){                        //Player vs computer game mode
          printf("\nGame mode:Player vs Computer");
          printf("\nPlayer:%c\n",first_sign);
          printf("Computer:%c\n",second_sign);
          if (count % 2 == 0) {
            sign = first_sign;
            player = 1;
            printf("\n\nEnter your index(1-9): ");  //Player input a index
            scanf("%d", &index);

          } else {
            sign = second_sign;
            player = 2;
            int in=rand();
            index = (rand())% 10+1;      //Computer input a index randomly
            printf("\n\nEnter computer's index:%d\n",index);
            sleep(1);
         }

       }else{
          printf("\nGame mode:Player vs Player");      //Player vs Player game mode
          printf("\nPlayer 1:%c\n",first_sign);
          printf("Player 2:%c\n",second_sign);
          if (count % 2 == 0) {
            sign = first_sign;
            player = 1;
            printf("\n\nEnter player 1 index(1-9): ");  //Player 1 input a index
            scanf("%d", &index);
          }else{
            sign = second_sign;
            player = 2;
            printf("\n\nEnter player 2 index(1-9): ");  //Player 2 input a index
            scanf("%d", &index);
          }

       }

          if(index < 1 || index > 9) {
            printf("Allowed index is 1 to 9!!\n"); //Check the indexes that has in range of 1-9
            sleep(2);
            continue;
         }

          if (grid[index - 1] == 'X' || grid[index - 1] == 'O') { //Check the indexes that already taken
            printf("Position Already Taken!!\n");
            sleep(2);
            continue;
          }

       if(x==1){
          if(player==1){
            fprintf(file, "Player1-%c moved to %d\n",first_sign,index);  //Write moves of Player vs Player game mode
          }else{
            fprintf(file, "Player2-%c moved to %d\n",second_sign,index);
          }

       }else{
          if(player==1){
            fprintf(file, "Player-%c moved to %d\n",first_sign,index);   //Write moves of Player vs Computer game mode
          }else{
            fprintf(file, "Computer-%c moved to %d\n",second_sign,index);
          }
       }

          grid[index - 1] = sign;
          count++;


       if(x==2){
          if ((grid[0] == sign && grid[1] == sign && grid[2] == sign) || //Check Rows
            (grid[3] == sign && grid[4] == sign && grid[5] ==  sign)||
            (grid[6] == sign && grid[7] == sign && grid[8] ==  sign)) {

                pvc(player,file);
          }

          if((grid[0] == sign && grid[3] == sign && grid[6] == sign) ||  //Check column
            (grid[1] == sign && grid[4] == sign && grid[7] ==  sign) ||
            (grid[2] == sign && grid[5] == sign && grid[8] ==  sign)) {

                pvc(player,file);
          }

          if((grid[0] == sign && grid[4] == sign && grid[8] == sign) ||  //Check diagonal
            (grid[2] == sign && grid[4] == sign && grid[6] ==  sign)){

                pvc(player,file);
          }
       }

      if(x==1){
          if ((grid[0] == sign && grid[1] == sign && grid[2] == sign) ||  //Check Rows
            (grid[3] == sign && grid[4] == sign && grid[5] ==  sign)||
            (grid[6] == sign && grid[7] == sign && grid[8] ==  sign)) {

                pvp(player,file);
          }

          if((grid[0] == sign && grid[3] == sign && grid[6] == sign)||    //Check column
            (grid[1] == sign && grid[4] == sign && grid[7] ==  sign) ||
            (grid[2] == sign && grid[5] == sign && grid[8] ==  sign)) {

                pvp(player,file);
          }

          if((grid[0] == sign && grid[4] == sign && grid[8] == sign) ||   //Check diagonal
            (grid[2] == sign && grid[4] == sign && grid[6] ==  sign)){

                pvp(player,file);
          }
      }

  }

}else{

  printf("\nInstruction does not exist!Try again later..");
  system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'Instruction does not exist!Try again later..\')))\"");

  exit(1);
}

    system("cls");
    printf("\033[0;31m");
    printf("\n\n\n\n\n\n\t\t\tMatch is draw!\n\n");   //Show if match is draw
    system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'Match is draw\')))\"");
    fprintf(file, "\nResult:Match is draw");

    fclose(file);
    return 0;

}

void pvc(int player,FILE *file){   //Player vs Computer
        board();
        sleep(1);
        system("cls");
        if (player==1) {        //show if winner is player
            printf("\033[0;32m");
            printf("\n\n\n\n\n\n\t\t\tYou are the winner.Well done!\n\n");
            system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'You are the winner!well done\')))\"");
            fprintf(file, "\nResult:Player is the winner");
        }

        else{    //show if winner is computer
            printf("\033[0;31m");
            printf("\n\n\n\n\n\n\t\t\tohh.Computer is the winner.You lost!\n\n");
            system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'ohh!Computer is the winner!You lost\')))\"");
            fprintf(file, "\nResult:Computer is the winner");
        }
        exit(1);

  }

void pvp(int player,FILE *file){  //Player vs Player
        board();
        sleep(1);
        system("cls");
        if (player==1) {        //show if winner is player 1
            printf("\033[0;32m");
            printf("\n\n\n\n\n\n\t\t\tPlayer no 1 is win!\n\n");
            system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'player no 1 is win\')))\"");
            fprintf(file, "\nResult:Player no 1 is win");
        }

        else{    //show if winner is player 2
            printf("\033[0;33m");
            printf("\n\n\n\n\n\n\t\t\tPlayer no 2 is win\n\n");
            system("mshta \"javascript:code(close((V=(v=new ActiveXObject(\'SAPI.SpVoice\')).GetVoices()).count&&v.Speak(\'player no 2 is win\')))\"");
            fprintf(file, "\nResult:Player no 2 is win");
        }
        exit(1);

  }

