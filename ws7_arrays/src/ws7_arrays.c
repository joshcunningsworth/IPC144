/*
 ============================================================================
 Name        : ws7_arrays.c
 Author      : Josh Cunningham
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

double calculator(int barcode[], double price[], int quantity[], double *p);

int main(void) {
	int barcode[MAX];
	int quantity[MAX];
	double price[MAX];
	double value[MAX];
	double total;
	int i = 0, quit = 0;
	double *p;
	int barcodesize = 0;

	p = value;

	printf("Grocery Store Inventory\n=======================\n");

	for (i = 0; quit != 1; i++){
		printf("Enter a 10 digit Barcode: \n");
		scanf("%d", &barcode[i]);
		barcodesize++;

		if (barcode[i] == 0){
			quit = 1;
		}

		if (barcode[i] > 0){
		printf("Enter the Price of the Item: \n");
		scanf("%lf", &price[i]);

		printf("Enter the Quantity of the Item: \n");
		scanf("%d", &quantity[i]);
		}
	}

	total = calculator(barcode, price, quantity, p);

	printf("\t\tGood in Stock\n\t\t=============\n");
	printf("Barcode\t\tPrice\tQuantity\tValue\n");
	printf("---------------------------------------------\n");
	quit = 0;
	for(i = 0; quit != 1; i++){
		if (barcode[i] == barcodesize){
			quit = 1;
		}

		printf("%d\t\t%.2lf\t%d\t%.2lf", barcode[i], price[i], quantity[i], value[i]);
	}
	return 0;
}

double calculator(int barcode[], double price[], int quantity[], double *p){
	double total = 0;
	int i = 0;
	int quit = 0;

	for(i = 0; quit != 1; i++){
		if (barcode[i] == 0){
			quit = 1;
		}
		else {
			*(p + i) = price[i] * quantity[i];
			total = total + *(p + i);
		}
	}

	return total;
}
