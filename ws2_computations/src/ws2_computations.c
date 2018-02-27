/*
 ============================================================================
 Name        : ws2_computations.c
 Author      : Josh Cunningham
 Date		 : Sept 23, 2013
 Description : Workshop 2 - Computations
 ============================================================================
 */
#include <stdio.h>

int main(void) {

	// declaring variables and assigning their values
	int itemamount;
	double itemprice = 0.00;
	double totalprice = 0.00;
	double totalcost = 0.00;
	double purchaseprice = 0.00;
	double tax = 0.13;
	double totaltax = 0.00;
	double change = 0.00;

	double cashpaid = 0.00;
	int loonies = 0, cents = 0;

	// prompts the user to enter the amount of items they want to purchase
	printf("Enter the number of items: ");
	// scans the keybuffer for a integer variable to store in itemamount
	scanf("%d", &itemamount);

	// prompting the user for the item's price
	printf("Enter the unit price: ");
	// scanning the items price into the variable itemprice
	scanf("%lf", &itemprice);

	// calculating the purchase price of the items being bought
	purchaseprice = itemprice * itemamount;
	// printing the purchase price to the screen
	printf("Purchase price: %.2lf\n", purchaseprice);
	// calculating the total tax
	totaltax = tax * purchaseprice;
	printf("HST (13%) %.2lf\n", totaltax);

	totalprice = itemprice * itemamount;
	totalcost = totalprice + totaltax;

	printf("The total cost is: %.2lf\n", totalcost);

	// prompts the user for how much they will pay with
	printf("Cash tendered: ");
	scanf("%lf", &cashpaid);

	// checking if the user entered enough money to pay the total cost
	if (cashpaid >= totalcost){
		// formula for calculating the users change
		change = cashpaid - totalcost;

		printf("Your change is: %.2lf\n", change);
		loonies = change;
		printf("Change loonies %d\n", loonies);
		// calculating the amount of cents the user will recieve
		cents = (change - loonies) * 100 + 1;
		// printing the cents back to the screen
		printf("Change cents %d\n", cents);
	}

	else{
		printf("You didn't pay enough money");
	}

	return 0;
}
