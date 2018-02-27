/*
 ============================================================================
 Name        : ws5_pointers.c
 Author      : Josh Cunningham
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//commondenom function - return greatest common denom of two numbers
int commondenom(int num, int dem);

int main(){

	// declaring numerator and denominator variables
	int numerator, denominator;
	int newnumer, newdenom;

	// printing the title of the program
	printf("Fraction Simplifier\n===================\n");

	printf("Numerator: \n");
	scanf("%d", &numerator);
	printf("Denominator: \n");
	scanf("%d", &denominator);

	newnumer = numerator / commondenom(numerator, denominator);
	newdenom = denominator / commondenom(numerator, denominator);

	// printing the results of the simplified fractions separated by a backslash
	printf("%d / %d = %d / %d", numerator, denominator, newnumer, newdenom);
}

int commondenom(int num, int dem){
	int commondenom, remainder;

	while (num != 0)
	{
		// calculating the remainder
		remainder = dem % num;
		// swapping the numerator into the denominator
		dem = num;
		// saving the remainder into the numerator
		num = remainder;
	}

	commondenom = dem;

	return commondenom;
}
