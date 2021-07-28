#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LADDER_FROM[8] = {2, 10, 27, 51, 61, 65, 71, 81};   //Ladders position down
int LADDER_TO[8]  = {37, 32, 46, 68, 79, 84, 91, 100};  //Ladders position top
int SNAKE_FROM[9] = {33, 41, 49, 56, 62, 87, 93, 95, 98};   //Snakes position top
int SNAKE_TO[9]   =   {6, 20, 9, 53, 5, 16, 73, 75, 64};    //Snakes position down
char player1[20];   
char player2[20];
int player1_score;
int player2_score;

//Sets player names
void setPlayerName(){
    printf("Enter Name of the first player : ");
    gets(player1);
    printf("Enter Name of the second player : ");
    gets(player2);
}

//Checks if the player gets any ladder or not
int checkLadder(int score){
    int i=0;
    for(i=0; i<8; i++){
        if(score == LADDER_FROM[i]){
            return i;
        }
    }
    return -1;
}

//Checks the player gets any snake or not
int checkSnake(int score){
    int i=0;
    for(i=0; i<9; i++){
        if(score == SNAKE_FROM[i]){
            return i;
        }
    }
    return -1;
}

//Gets input and handels the score and displays the output
void getFirstPlayerInput(){
    int scoretemp, previous_score, statusLadder, statusSnake;

    printf("Enter Score for %s ",player1);
    scanf("%d",&scoretemp);

    if(scoretemp >= 1 && scoretemp <= 6){

        previous_score = player1_score;
        player1_score = player1_score+scoretemp;
     
        statusLadder = checkLadder(player1_score);
        statusSnake = checkSnake(player1_score);
     
        if(statusLadder == -1 && statusSnake == -1){
            printf("%s Rolled a %d and moved from %d to %d\n",player1, scoretemp,previous_score, player1_score);
        }
     
        else{
            if(statusLadder >=0){
                player1_score = LADDER_TO[statusLadder];
                printf("%s Rolled a %d and moved from %d to %d, got a ladder and moved from %d position to %d position\n",player1, scoretemp, previous_score, LADDER_FROM[statusLadder], LADDER_FROM[statusLadder], LADDER_TO[statusLadder]);
            }
            else{
                player1_score = SNAKE_TO[statusSnake];
                printf("%s Rolled a %d and moved from %d to %d, got bitten by a snake and moved from %d position to  %d position\n",player1, scoretemp, previous_score, SNAKE_FROM[statusSnake], SNAKE_FROM[statusSnake], SNAKE_TO[statusSnake]);
            }
        }
    }
    else{
        printf("Wrong Input Score should be between 0-6\n");
        getFirstPlayerInput();
    }
    
}

//Gets input and handels the score and displays the output
void getSecondPlayerInput(){
    int scoretemp, previous_score, statusLadder, statusSnake;

    printf("Enter Score for %s ",player2);
    scanf("%d",&scoretemp);

    if(scoretemp >=1 && scoretemp <=6){
        previous_score = player2_score;
        player2_score = player2_score+scoretemp;

        statusLadder = checkLadder(player2_score);
        statusSnake = checkSnake(player2_score);

        if(statusLadder == -1 && statusSnake == -1){
            printf("%s Rolled a %d and moved from %d to %d\n",player2, scoretemp, previous_score, player2_score);
        }

        else{
            if(statusLadder >=0){
                player2_score = LADDER_TO[statusLadder];
                printf("%s Rolled a %d and moved from %d to %d, got a ladder and moved from %d position to  %d position\n",player2, scoretemp, previous_score, LADDER_FROM[statusLadder], LADDER_FROM[statusLadder], LADDER_TO[statusLadder]);
            }
            else{
                player2_score = SNAKE_TO[statusSnake];
                printf("%s Rolled a %d and moved from %d to %d, got bitten by a snake and moved from %d position to  %d position\n",player2, scoretemp, previous_score, SNAKE_FROM[statusSnake], SNAKE_FROM[statusSnake], SNAKE_TO[statusSnake]);
            }
        }
    }

    else{
        printf("Wrong Input Score should be between 0-6\n");
        getSecondPlayerInput();
    }
}

int main(){
    setPlayerName();
    printf("\n");
    while(1){
        getFirstPlayerInput();
        if(player1_score >= 100){
            printf("GAME OVER\n%s Wins!",player1);
            break;
        }
        printf("\n");

        getSecondPlayerInput();
        if(player2_score >= 100){
            printf("GAME OVER\n%s Wins!",player2);
            break;
        }
        printf("\n");
    }
}