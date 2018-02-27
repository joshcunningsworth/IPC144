/*
 ============================================================================
 Name        : popularnames.c
 Author      : Josh Cunningham
 Date        : December 5th, 2013
 Student ID  : 016874133
 Description : This program will take a name input from a user, then read through
 two files containing names, years, and births per 100,000. It will then display
 the info to the user with a text based graph.

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
void setYearTotals(struct NameRecord records[], int size, int yearRangeTotals[]);
void setNameYearTotals(char searchname[],struct NameRecord records[], int size, int nameTotal[]);
void getPerHundredThousand(int nameTotal[], int yearRangeTotals[], double perHundredThousand[]);
void printData(double perHundredThousand[], char searchname[]);
void graphPerHundredThousand(double perHundredThousand[]);
void clearkey();

int main(void) {
	FILE *female;
	FILE *male;
	double perHundredThousand[18] = {0.0};
	char again = '\0';
	char searchname [31];
	int size;
	struct NameRecord records[150000];
	int currSize = 0;
	int yearRangeTotals [17];
	int nameTotal[17];

	female = fopen("femalebabynames.csv", "r");
	male = fopen("malebabynames.csv", "r");

	printf("Welcome to the Name Popularity Checker\n");
	printf("======================================\n");

	do{
		// prompting the user to enter a name
		printf("Please enter a name: \n");
		scanf("%30[^\n]", searchname);

		// calling functions here
		allCaps(searchname);
		// printing the search name again in capitols
		printf("%s\n", searchname);
		size = getRawData(female, male, records, currSize);
		setYearTotals(records, size, yearRangeTotals);
		setNameYearTotals(searchname, records, size, nameTotal);
		getPerHundredThousand(nameTotal, yearRangeTotals, perHundredThousand);
		printData(perHundredThousand, searchname);
		graphPerHundredThousand(perHundredThousand);

		printf("Do you wish to check another name (Y/N)? \n");
		scanf(" %c", &again);

		clearkey();

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
			while(fscanf(female, "%d,%30[^,],%d", &records[currSize].year, records[currSize].searchname, &records[currSize].frequency) != EOF){
				currSize++;
			}
	}

		else{
			printf("ERROR: Could not open file!");
		}

	if(male){
			while(fscanf(male, "%d,%30[^,],%d", &records[currSize].year, records[currSize].searchname, &records[currSize].frequency) != EOF){
				currSize++;
			}
	}

		else{
			printf("ERROR: Could not open file!");
		}

	rewind(female);
	rewind(male);

	return currSize;
}

void setYearTotals(struct NameRecord records[], int size, int yearRangeTotals[]){
	int i = 0, num = 0;
	int year1 = 1921;
	int year2;

	for (year2 = 1925; year2 <= 2010; year2 = year2 + 5){

		for (i = 0; i != size; i++){

			if(records[i].year >= year1 && records[i].year <= year2){

				yearRangeTotals[num] += records[i].frequency;
			}
		}
		year1 += 5;
		num++;
	}
}

void setNameYearTotals(char searchname[], struct NameRecord records[], int size, int nameTotal[]){
	int i = 0, num = 0;
	int year1 = 1921;
	int year2 = 1925;

	for (year2 = 1925; year2 <= 2010; year2 = year2 + 5){

			for (i = 0; i != size; i++){

				if ((strcmp(searchname, records[i].searchname ) == 0) && records[i].year >= year1 && records[i].year <= year2){
						nameTotal[num] += records[i].frequency;
					}
				}
			year1 += 5;
			num++;
			}
		}

void getPerHundredThousand(int nameTotal[], int yearRangeTotals[], double perHundredThousand[]){
	int i = 0, size = 17;
	for (i = 0; i <= size; i++){
		perHundredThousand[i] = 100000 * (double)nameTotal[i] / (double)yearRangeTotals[i];
	}
}

void printData(double perHundredThousand[], char searchname[]){
	int i = 0;
	int year1 = 1921;
	int year2 = 1925;

	printf("\nNumbers of Babies named %s per 100,000 births\n", searchname);
	printf("===========================================================\n");

	for (year2 = 1925; year2 <= 2010; year2 = year2 + 5){
		printf("%d - %d: %.2lf\n", year1, year2, perHundredThousand[i]);
		i++;
		year1 += 5;
	}
}


void graphPerHundredThousand(double perhundredthousand[]){         //displays graph for the above function

	int place, end=0, end2=0, num=17, point=17, year1=2006, year2;
	double initiate=0;

	printf("\n\n                    Graph");
	printf("\n=============================================\n");

	for(place=0; end2 != 1; place++){

		if(perhundredthousand[place] != 0){

			initiate = perhundredthousand[place];

			end2=1;
		}
	}

	if(perhundredthousand[0] != 0){

		place=1;
	}

	//prepares numbers to be divided
	for(place--; place <= 17;place++){

		if(place == 17 || perhundredthousand[place+1] == 0){
		}

		else if(initiate > perhundredthousand[place+1]){

			initiate = perhundredthousand[place+1];
		}
	}

	//changes year
	for(year2=2010; year1 >= 1921; year2-=5){
		perhundredthousand[point] = perhundredthousand[point] / initiate;
		printf("%d - %d |", year1, year2);

		//displays graph
		for(end=-1; end != (int)perhundredthousand[num];end++){
			if(perhundredthousand[num] > 0 && perhundredthousand[num] > 1){
				printf("*");
			}

			if(perhundredthousand[num] == 1){
				printf("*");
				end++;
			}
		}
		printf("\n");
		num--;
		year1 -= 5;
		point--;
	}
	printf("\n\n");
}

void clearkey(){
	char choice = ' ';
	scanf("%c", &choice);
}
