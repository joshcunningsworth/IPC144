/*
 ============================================================================
 Name        : ws4_functions.c
 Author      : Josh Cunningham
 Description : Program calculates future value from principal and annual rate
 ============================================================================
 */

#include <stdio.h>

int main (){

	double principal = 0;
	double annualrate = 0;
	double annualrate2 = 0;
	int no_years = 0;
	double futureval = 0;
	int counter = 0;
	int quit = 0;

	printf("\nInvestment Calculator\n=======================\n");

	printf("Principal    :  ");
	scanf("%lf", &principal);

	printf("Annual Rate  :  ");
	scanf("%lf", &annualrate);

	printf("No of Years  :  ");
	scanf("%d", &no_years);

	annualrate = annualrate + 1;
	annualrate2 = annualrate;

	counter = no_years;

	do{

		if(counter != 1){

			annualrate = annualrate * annualrate2;
			counter = counter - 1;

		} else{

			futureval = principal * annualrate;
			printf("\nThe future value is $%.2lf\n\n", futureval);
			quit = 1;

		}

	} while(quit != 1);

	return 0;
}
