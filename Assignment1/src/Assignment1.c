/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Josh Cunningham
 Date        : September 24 2013
 Student ID  : 016874133
 Description : This program allows the user to play the game Rock, Paper, Scissors,
 Lizard, Spock. You can play alone against a computer or against a friend.

 I declare that the attached assignment is wholly my
 own work in accordance with Seneca Academic Policy.  No part of this
 assignment has been copied manually or electronically from any
 other source (including web sites) or distributed to other students.
 ============================================================================
 */

// includes the standard input output library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
        // declaring integer variables and setting their values to 0
        int playeramount = 0;
        int player1choice = 0, player2choice = 0;
        // declares integer variable named choice for choosing to quit or continue
        int choice;

        // declares double variables for storing the data for player 1 and player 2 wins
        double player1wins = 0, player2wins = 0;
        // declares integer variables for storing the amount of games played and games tied
        int tiegames = 0, gamesplayed = 0;
        // declares double variables for storing the win percentage
        double player1percent, player2percent;

        // displays the title of the game and asks how many people will be playing
        printf("\t\tWelcome to RPSLS!\n________________________________________________\n");
        printf("How many people will be playing?: ");
        scanf("%d", &playeramount);
    do{

    // if the player amount is equal to 1 then this condition runs
    if (playeramount == 1){
    	// asks the user to enter a number from 1 to 5 and stores it in the variable player1choice
    	printf("Player One's Turn!\n");
    	printf("1 - ROCK \n2 - PAPER \n3 - SCISSORS \n4 - LIZARD \n5 - SPOCK\n");
    	scanf("%d", &player1choice);

    	// logic for calculating a number from 1 to 5
    	srand (time(NULL));
    	player2choice = rand() %5+1;

    	// if statements for displaying what the computer picks
    	if (player2choice == 1){
    	printf("Computer Chose Rock\n");
    	}
    	if (player2choice == 2){
    	printf("Computer Chose Paper\n");
    	}
    	if (player2choice == 3){
    	printf("Computer Chose Scissors\n");
    	}
    	if (player2choice == 4){
    	printf("Computer Chose Lizard\n");
    	}
    	if (player2choice == 5){
    	printf("Computer Chose Spock\n");
    	}

    	}

    // if the user set the player amount to 2 at the beginning of the program then this else if runs
    else if (playeramount == 2){
    	// asks player 1 to enter their choice and stores it in the variable player1choice
        printf("Player One's Turn!\n");
        printf("1 - ROCK \n2 - PAPER \n3 - SCISSORS \n4 - LIZARD \n5 - SPOCK\n");
        scanf("%d", &player1choice);

        // asks player 2 to enter their choice and stores it in the variable player2choice
        printf("Player Two's Turn!\n");
        printf("1 - ROCK \n2 - PAPER \n3 - SCISSORS \n4 - LIZARD \n5 - SPOCK\n");
        scanf("%d", &player2choice);
    	}

    	// condition for when both players choose the same number
        if (player1choice == player2choice){
        // outputs that the game was tied
        printf("The Game is a Tie!\n");
        // increments the amount of games played and games tied by 1
        tiegames++;
        gamesplayed++;
        }
        // both the conditions for player 1 winning by choosing rock
        else if ((player1choice == 1 && player2choice == 3) || (player1choice == 1 && player2choice == 4)){
        // output that player 1 wins
        printf("Player One Wins!\n");
        // increments the amount of games played and player 1 wins
        player1wins++;
        gamesplayed++;
        }
        // both the conditions for player 1 winning by choosing paper
        else if ((player1choice == 2 && player2choice == 1) || (player1choice == 2 && player2choice == 5)){
        printf("Player One Wins!\n");
        // increments the amount of games
        player1wins++;
        gamesplayed++;
        }
        else if ((player1choice == 3 && player2choice == 2) || (player1choice == 3 && player2choice == 4)){
        printf("Player One Wins!\n");
        player1wins++;
        gamesplayed++;
        }
        else if ((player1choice == 4 && player2choice == 2) || (player1choice == 4 && player2choice == 5)){
        printf("Player One Wins!\n");
        player1wins++;
        gamesplayed++;
        }
        else if ((player1choice == 5 && player2choice == 1) || (player1choice == 5 && player2choice == 3)){
        printf("Player One Wins!\n");
        player1wins++;
        gamesplayed++;
        }
        // if none of the conditions of player 1 winning or the game being tied then player 2 wins
        else{
        // outputs that player 2 wins
        printf("Player Two Wins!\n");
        // increments the amount of games played and player 2 wins
        player2wins++;
        gamesplayed++;
        }

        // asks the user if they want to continue and stores it in the varaible choice
        printf("Do you wish to continue?\n");
        printf("0 - YES\n1 - NO\n");
        scanf("%d", &choice);

    // if the user chooses to exit then this condition will be true
    }while (choice == 0);

    	// calculations for getting player 1 and player 2 win percents
    	player1percent = (player1wins * 100) / gamesplayed;
    	player2percent = (player2wins * 100) / gamesplayed;

    	// prints all of the statistics
    	printf("\n\t\tGame Statistics\n________________________________________________\n");
    	printf("Number of Games Played: %d\n", gamesplayed);
    	printf("Player One Wins: %.lf\n", player1wins);
    	printf("Player Two Wins: %.lf\n", player2wins);
    	printf("Number of Games Tied: %d\n", tiegames);
    	printf("Player One Win Percentage: %.2lf\n", player1percent);
    	printf("Player Two Win Percentage: %.2lf", player2percent);

    return 0;
}
