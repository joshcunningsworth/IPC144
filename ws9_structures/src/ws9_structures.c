/*
 ============================================================================
 Name        : ws9_structures.c
 Author      : Josh Cunningham
 Description : Creating Structures
 ============================================================================
 */

//Still has ERRORS!

#include <stdio.h>
#include <stdlib.h>


struct Fraction{
	int denominator;
	int numerator;
};


void enter(struct Fraction* );
void simplify(struct Fraction*);
void display(const struct Fraction*);

void enter(struct Fraction* f){
	printf("Numerator:\t\n");
	scanf("%d", &numerator);
	printf("Denominator:\t\n");
	scanf("%d", &denominator);
}

void simplify(struct Fraction* f){
	int commondenom, remainder;
	int num;
	num = numerator;

		while (num != 0){
			remainder = dem % num;
			dem = num;
			num = remainder;
		}

		commondenom = dem;
}

void display(const struct Fraction* d){

}

int main(void){
	struct Fraction f;

	printf("Fraction Simplifier\n===================\n");

    enter(&f);
    simplify(&f);
    display(&f);
}
