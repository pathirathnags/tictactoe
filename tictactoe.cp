//tictactoe.cc – DO alter this file.  
//two players can play tictactoe by running this program and each taking turns 

#include <stdio.h>
#include "tictactoe.h"

void clearBoard (gameData_t *ptr) {
       for (int i = 0; i < ROWS; i++)
      {
          for (int j = 0; j < COLS; j++)
	  {
	      ptr->board[i][j] = ' ';
	      }
	    } 
}

  void getPlayerInfo (gameData_t *ptr) 
  {
      printf ("Player 1 enter your name: ");
      scanf ("%s", ptr->name1);
      printf ("Player 1 enter your age: ");
      scanf ("%d", &ptr->age1);
      printf ("\n");
      printf ("Player 2 enter your name: ");
      scanf ("%s", ptr->name2);
      printf ("Player 2 enter your age: ");
      scanf ("%d", &ptr->age2);
} 

void printPlayerInfo (gameData_t gameData) 
  {
    
printf ("Player 1 is %s age %d and will be Xs\n", gameData.name1,
	     gameData.age1);
    
printf ("Player 2 is %s age %d and will be Os\n", gameData.name2,
	     gameData.age2);
  
} 

void printBoard (gameData_t gameData) 
  {
    
printf ("    C1  C2  C3\n");
    
printf ("R1  %c | %c | %c \n", gameData.board[0][0],
	     gameData.board[0][1], gameData.board[0][2]);
    
printf ("   -----------\n");
    
printf ("R2  %c | %c | %c \n", gameData.board[1][0],
	     gameData.board[1][1], gameData.board[1][2]);
    
printf ("   -----------\n");
    
printf ("R3  %c | %c | %c \n", gameData.board[2][0],
	     gameData.board[2][1], gameData.board[2][2]);
  
} 

void printTurnHeader (gameData_t gameData, char turn) 
  {
    
if (turn == 'X')
      
      {
	
printf ("--------------------------------------------------\n");
	
printf ("---------- %s's Turn --------------------\n", gameData.name1);
	
printf ("---------- You are Xs --------------------\n");
	
printf ("--------------------------------------------------\n");
      
}
    
if (turn == 'O')
      
      {
	
printf ("--------------------------------------------------\n");
	
printf ("---------- %s's Turn --------------------\n", gameData.name2);
	
printf ("---------- You are Os --------------------\n");
	
printf ("--------------------------------------------------\n");
      
} }

void getMove (gameData_t *ptr, char turn) 
  {
      char move[5];
      int loop = 0;
      int x = 0;
      int y = 0;
    if (turn == 'X')
      {
          printf ("%s, please enter your move in the form RXCY: ", ptr -> name1);
          scanf ("%4s", move);
          while (loop == 0)
          {
              if (move[0] != 'R' && move[0] != 'r' || move[2] != 'C' && move[2] != 'c')
              {
                  printf ("Result must be in the form RxCy. Try again: ");
                  scanf ("%4s", move);
              }
              else if (move[1] != '1' && move[1] != '2' && move[1] != '3' || move[3] != '1' && move[3] != '2' && move[3] != '3')
              {
                  printf ("Row and column must be in the range 1 to 3. Try again: ");
                  scanf ("%4s", move);
              }
              else if (ptr -> board[move[1] - 49][move[3] - 49] != ' ')//(ptr -> board[x][y] != ' ')
              {
                  printf ("That space is taken. Try again: ");
                  scanf ("%4s", move);
              }
              else
              {
                  x = move[1] - 49;
                  y = move[3] - 49;
                  loop = 1;
                  ptr -> board[x][y] = turn;
              }
          }
          
      }
    
if (turn == 'O')
      
      {
          printf ("%s, please enter your move in the form RXCY: ", ptr->name2);
          scanf ("%4s", move);
          
          while (loop == 0)
          {
              if (move[0] != 'R' && move[0] != 'r' || move[2] != 'C' && move[2] != 'c')
              {
                  printf ("Result must be in the form RxCy. Try again: ");
                  scanf ("%4s", move);
              }
              else if (move[1] != '1' && move[1] != '2' && move[1] != '3' || move[3] != '1' && move[3] != '2' && move[3] != '3')
              {
                  printf ("Row and column must be in the range 1 to 3. Try again: ");
                  scanf ("%4s", move);
              }
              else if (ptr -> board[move[1] - 49][move[3] - 49] != ' ')//(ptr -> board[x][y] != ' ')
              {
                  printf ("That space is taken. Try again: ");
                  scanf ("%4s", move);
              }
              else
              {
                  x = move[1] - 49;
                  y = move[3] - 49;
                  loop = 1;
                  ptr -> board[x][y] = turn;
              }
          }
          
      }
}



int checkWin (gameData_t gameData, char turn) 
  {
      //1 is true
      //0 is false
     int win = 0;
     //top row
     if (gameData.board[0][0] == turn && gameData.board[0][1] == turn && gameData.board[0][2] == turn) win = 1;
     //middle row
     else if (gameData.board[1][0] == turn && gameData.board[1][1] == turn && gameData.board[1][2] == turn) win = 1;
     //bottom row
     else if (gameData.board[2][0] == turn && gameData.board[2][1] == turn && gameData.board[2][2] == turn) win = 1;
     //left col
     else if (gameData.board[0][0] == turn && gameData.board[1][0] == turn && gameData.board[2][0] == turn) win = 1;
     //middle col
     else if (gameData.board[0][1] == turn && gameData.board[1][1] == turn && gameData.board[2][1] == turn) win = 1;
     //right col
     else if (gameData.board[0][2] == turn && gameData.board[1][2] == turn && gameData.board[2][2] == turn) win = 1;
     //diagonal top left
     else if (gameData.board[0][0] == turn && gameData.board[1][1] == turn && gameData.board[2][2] == turn) win = 1;
     //diagonal top right
     else if (gameData.board[0][2] == turn && gameData.board[1][1] == turn && gameData.board[2][0] == turn) win = 1;
     return win;
  }
  
  
  int checkTie (gameData_t g) 
  {
     
      int flag = 0;
      int count = 0;
      //if (checkWin != 0)
      //{
      //0 is false
      //1 is true
      for (int i = 0; i < ROWS; i++)
      {
          for (int j = 0; j < COLS; j++)
          {
              if (g.board[i][j] != ' ')
              {
                  count++;
              }
              }
          }
          if (count == 9)
          {
              flag = 1;
          }
          else
          {
              flag = 0;
          }
          return flag;
      }

void runGame() {
  
  gameData_t gameData;
  
  int win = 0;
  int tie = 0;  
  char turn = 'X';
  
  //Set board to all spaces.
  clearBoard(&gameData);
  
  //Get both players name and age
  getPlayerInfo(&gameData);
  
  //Show the player info
  printf("\n");
  printPlayerInfo(gameData);
  printf("\n");
  
  while (!win && !tie) {
    int count = 0;
    
    printTurnHeader(gameData, turn); 
    printBoard(gameData);
    getMove(&gameData, turn);    
    
    //Check for win
    win = checkWin(gameData, turn);        
    if (win == 1) {
      printf("--------------------------------------------------\n");      
      if (turn == 'X') {        
        printf("---------- %s WINS! --------------------\n", gameData.name1);
      } else {        
        printf("---------- %s WINS! --------------------\n", gameData.name2);
      }
      printf("--------------------------------------------------\n");      
      printBoard(gameData);
      printf("\n");
    } else {
      tie = checkTie(gameData);        
      if (tie == 1) {
        printf("--------------------------------------------------\n");      
        printf("---------- TIE GAME! --------------------\n");
        printf("--------------------------------------------------\n");      
        printBoard(gameData);
      }
    }
    
    //Toggle turn so other player goes next.
    if (turn == 'X') turn = 'O';
    else turn = 'X';
  }
}