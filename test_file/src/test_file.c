#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

int rock = 1;
int paper = 2;
int scissors = 3;
int lizard = 4;
int spock = 5;

int num_games = 0;

int player1_move = 0;
int player1_score = 0;

int player2_move = 0;
int player2_score = 0;

int tie_game = 0;

int player_decision = 0;

int p1_percent = 0;
int p2_percent = 0;

printf("ROCK PAPER SCISSORS LIZARD SPOCK\n");
printf("___________________________________\n");


printf("1 Rock\n");
printf("2 Paper\n");
printf("3 Scissors\n");
printf("4 Lizard\n");
printf("5 SpocK\n");

printf("Player 1, please enter move\n");
scanf("%d" , &player1_move);
printf("Player 2, please enter move");
scanf("%d", &player2_move);

{if ((player1_move == rock && player2_move == scissors) || (player1_move == rock && player2_move == lizard))
printf("Player 1 wins");
player1_score++;
if ((player1_move == rock && player2_move == paper) || (player1_move == rock && player2_move == spock))
printf("Player 2 wins");
player2_score++;
if  (player1_move == rock && player2_move == rock)
printf("It's a tie!");
tie_game++;

if ((player1_move == paper && player2_move == rock) || (player1_move == paper && player2_move == spock))
printf("Player 1 wins");
player1_score++;
if ((player1_move == paper && player2_move == lizard) || (player1_move == paper && player2_move == scissors))
printf("Player 2 wins");
player2_score++;
if (player1_move == paper && player2_move == paper)
printf("It's a tie!");
tie_game++;

if ((player1_move == scissors && player2_move == paper) || (player1_move == scissors && player2_move == lizard))
printf("Player 1 wins");
player1_score++;
if ((player1_move == scissors && player2_move == spock) || (player1_move == scissors && player2_move == rock))
printf("Player 2 wins");
player2_score++;
if (player1_move == scissors && player2_move == scissors)
printf("It's a tie!");
tie_game++;

if ((player1_move == spock && player2_move == scissors) || (player1_move == spock && player2_move == rock))
printf("Player 1 wins");
player1_score++;
if ((player1_move == spock && player2_move == lizard) || (player1_move == spock && player2_move == scissors))
printf("Player 2 wins");
player2_score++;
if (player1_move == spock && player2_move == spock)
printf("It's a tie");
tie_game++;

if ((player1_move == lizard && player2_move == spock) || (player1_move == lizard && player2_move == paper))
printf("Player 1 wins\n");
player1_score++;
if ((player1_move == lizard && player2_move == scissors) || (player1_move == lizard && player2_move == rock))
printf("Player 2 wins\n");
player2_score++;
if (player1_move == lizard && player2_move == lizard)
printf("It's a tie\n");
tie_game++;

printf("Would you like play again? 1 = yes 2 = no\n");
scanf("%d", &player_decision);
num_games = num_games++;
}while (player_decision == 1);

printf("Games Statistics\n");
printf("Number of games played: %d\n", num_games);
printf("Number of games won by Player 1: %d\n", player1_score);
printf("Number of games won by Player 2: %d\n", player2_score);
printf("Number of games Tied: %d\n", tie_game);
printf("Player 1 win Percentage: %d percent\n", p1_percent);
p1_percent = player1_score/num_games * 100;
printf("Player 2 win Percentage: %d\n", p2_percent);
p2_percent = player2_score/num_games * 100;
return 0;

}
