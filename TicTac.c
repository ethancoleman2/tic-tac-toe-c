#include <stdio.h>

void print_board(char board[3][3]){
  int r, c;
  printf("\n");
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      if(c == 2){
        printf(" %c", board[r][c]);
      }
      else{
        printf(" %c |", board[r][c]);
      }
    }
    printf("\n");
    if(r != 2){
      printf("----------- \n");
    }
  }
  printf("\n");
}

void play_turns(char board[3][3], char turn){
  char input;
  int r, c;
  printf("Input number for %c:", turn);
  scanf("%c", &input);
  getchar();
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      if(input == board[r][c]){
        board[r][c] = turn;
        print_board(board);
        return;
      }
    }
  }
}

int check_draw(char board[3][3]){
  int r, c;
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){
      if(board[r][c] == 'X' || board[r][c] == 'O'){
        continue;
      }
      else{
        return 0;
      }
    }
  }
  printf("The game is a draw! \n");
  return 1;
}

int check_win(char board[3][3]){
  int r, c;

    if(board[0][0] == board[0][1] && board[0][0] == board[0][2]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[2][0] == board[2][1] && board[2][0] == board[2][2]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[0][1] == board[1][1] && board[0][1] == board[2][1]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[0][2] == board[1][2] && board[0][2] == board[2][2]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      printf("Player %c won! \n", board[0][0]);
      return 1;
    }
    else{
      return check_draw(board);
    }
  }

int main(){
  char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
  }, input, turn;
  int choice, loopcounter;

  print_board(board);

  turn = 'X';

  while(1 == 1){
    play_turns(board, turn);

    if(check_win(board) == 1){
      break;
    }

    if(turn == 'X'){
      turn = 'O';
    }
    else if(turn == 'O'){
      turn = 'X';
    }
  }
}
