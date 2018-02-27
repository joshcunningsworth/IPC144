/*
 ============================================================================
 Name        : ws8_strings.c
 Author      : Josh Cunningham
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int wordcount(char[]);

int main(void) {

	char str[64];

	printf("Word Counter\n============\n");
	printf("Text to be analyzed : \n");
	scanf("%63[^\n]", str);

	printf("Word count\t    : %d\n", wordcount(str));
	return 0;
}

int wordcount(char str[]){
	int words = 0, i = 0;

	if (str[0] != ' '){
		words++;
	}

	for (i = 0; str[i] != '\0'; i++){

		if(str[i] == ' ' && str[i-1] != ' '){
			words++;
		}

	}

	return words;
}
