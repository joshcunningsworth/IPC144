/*
 ============================================================================
 Name        : Assignment3.c
 Author      : Josh Cunningham
 Date        : December 5th, 2013
 Student ID  : 016874133
 Copyright   : I declare that the attached assignment is wholly my
 own work in accordance with Seneca Academic Policy.  No part of this
 assignment has been copied manually or electronically from any
 other source (including web sites) or distributed to other students.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 150000

struct NameRecord{
	char searchname[31];
	int year;
	int frequency;
};

void allCaps(char searchname[]);
int getRawData(FILE *female, FILE *male, struct NameRecord records[], int currSize);
void setYearTotals(struct NameRecord records[], int size, int yearRangeTotals);
void setNameYearTotals(char searchname[],struct NameRecord records[], int size, int nameTotal[]);
void getPerHundredThousand(int nameTotal[], int yearRangeTotal[], double perHundredThousand[]);
void printData(double perHundredThousand[]);
void graphPerHundredThousand(double perHundredThousand[]);

int main(void) {
	FILE *female;
	FILE *male;
	//double pht[18] = {0.0};
	char again;
	char searchname [31];
	int currSize = 0;
	int size;
	int nameTotal[18];
	int yearRangeTotals [18];
	struct NameRecord records[LIMIT];

	female = fopen("femalebabynames.csv", "r");
	male = fopen("malebabynames.csv", "r");

	printf("Welcome to the Name Popularity Checker\n");
	printf("======================================\n");

	do{
		printf("Please enter a name: \n");
		scanf("%30[^\n]", searchname);
		allCaps(searchname);
		size = getRawData(female, male, records, currSize);
		setYearTotals(records, size, yearRangeTotals);
		nameYearTotals(searchname, records, size, nameTotal);

		printf("Do you wish to check another name (Y/N)? ");
		scanf("%c", &again);

	}while(again != 'N' || again != 'n');

	return 0;
}

void allCaps(char searchname[]){
	int i = 0;
	for(i = 0; searchname[i] != '\0'; i++){
		searchname[i] = toupper(searchname[i]);
	}
}

int getRawData(FILE *female, FILE *male, struct NameRecord records[], int currSize){

	if(female){
		for(currSize = 0; fscanf(female, "%int,%30[^,],%int", &records[currSize].year, records[currSize].searchname, records[currSize].frequency) != EOF ; currSize++){

		}
	}

	else{
		printf("ERROR: Could not open file!");
	}

	if(male){
		for(currSize = 0; fscanf(male, "%int,%30[^,],%int", &records[currSize].year, records[currSize].searchname, records[currSize].frequency) != EOF ; currSize++){

		}
	}

	else{
		printf("ERROR: Could not open file!");
	}

	return currSize;
}

void setYearTotals(struct NameRecord records[], int size, int yearRangeTotals){
	//int i = 0;
}

void setNameYearTotals(char searchname[],struct NameRecord records[], int size, int nameTotal[]){
}

void getPerHundredThousand(int nameTotal[], int yearRangeTotal[], double perHundredThousand[]){

	int i = 0, curr = 0;
	double smallest = perHundredThousand[0];

	printf("\t\tGraph\n");
	printf("=========================================\n");

	for(i = 0; i < 17; i ++){

		if (perHundredThousand[i] > perHundredThousand [i + 1]) {
			smallest = perHundredThousand[i + 1];
		}

	}

	if (smallest == 0){
		smallest = 1;
	}

	for (i = 17; i >= 0; i--){
		curr = (perHundredThousand[i] / smallest);

		curr = (curr % 1 > 0) ? curr : curr + 1;
	}

}

void printData(double perHundredThousand[]){
}

void graphPerHundredThousand(double perHundredThousand[]){
}
