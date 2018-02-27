/*
 ============================================================================
 Name        : ws6_libraryfunctions.c
 Author      : Josh Cunningham
 Description : This program throws a pair of dice until the sum of the two
 	 	 	   are equal to the sought value. It also error checks to see if
 	 	 	   the sought value is a correct number between 2 and 12.
 ============================================================================
 */

// includes the necessary libraries for the program to run
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// initializing integer variables called sought, found and gamesplayed
	int sought = 0, found = 0, gamesplayed;
	// initializing integer variables dice1, dice2, total and correctnum
	int dice1, dice2, total, correctnum;

	// prints the title of the game with a boarder underneath
	printf("Game of Dice\n============\n");

	// do loop with a while condition that is checking if the user entered a correct number
	do{
		// setting the correctnum to 0
		correctnum = 0;
		// prompts the user to enter the number they are looking for
		printf("Enter total sought : \n");
		// scans the keybuffer and stores it in the integer variable sought
		scanf("%d", &sought);

		// if statement to check if the number is invalid
		if (sought > 12 || sought < 2){
			// displays the error message to the user
			printf("** Invalid Input! Try Again! **\n");
			// increments correctnum so the loop will continue
			correctnum ++;
		}

	}while(correctnum != 0);

	// for loop for playing the game and throwing the dice which will end when found is equal to 1
	for(gamesplayed = 1; found != 1; gamesplayed++){

		// dice 1 random throws from 1-6
		dice1 = rand() %6;
		dice1++;

		// dice 2 random throws from 1-6
		dice2 = rand() %6;
		dice2++;

		// displays the result of the throw to the user
		printf("Result of throw %d : %d + %d\n", gamesplayed, dice1, dice2);
		// formula for calculating the total amount of the two dice thrown
		total = dice1 + dice2;

		// if statement that runs if the total amount is equal to what the user was looking for
		if (total == sought){
			// displays to the user their total was found and how many throws it took
			printf("You got your total in %d throws!\n", gamesplayed);
			// sets found equal to 1 which ends the for loop and game
			found = 1;
		}
	}
	return 0;
}
