/*
 ============================================================================
 Name        : array_practice.c
 Author      : Josh Cunningham
 Description : testing arrays
 ============================================================================
 */

#include <stdio.h>
int bar(double barcode[], int size, double maxbar, double minbar, int validate){
	validate = 1;
	//starts by checking if the barcode is zero
	if(barcode[size] == 0){
        validate = 2;
	}

	//if the barcode isn't zero it checks if it's within the range (max and min)
	else if(barcode[size] > maxbar || barcode[size] < minbar){
        validate = 0;
    }

	//if the barcode passes the two checks before this than it will set validate to 1
    else{
    	validate = 1;
    }

    return validate;
}

double calc(double barcode[], double price[], int quantity[], int count){
	int size = 0;
	double total = 0;
	double value[100];

    printf("            \n           Games in Stock\n           ==============\n");
    printf("Barcode     Price   Quantity    Value\n");
    printf("--------------------------------------\n");

    for(int loop = 0; loop != count; loop++){
        value[size] = price[size] * quantity[size];
        printf("%10.lf   %.2lf", barcode[size], price[size]);
        printf("      %d         %.2lf\n", quantity[size], value[size]);
        size++;
    }
    printf("                                ------\n");
    size = 0;

    for(int loop = 0; loop != count; loop++){
        total = total + value[size];
        size++;
    }
return total;
}

int main (void){
	int quantity[100];
	int size = 0, validate = 0, count = 0;
	double price[100], barcode[100];
	double maxbar = 9999999999, minbar = 1000000000, total_value = 0;

    printf("VideoGame Store Inventory\n=========================\n");
    do{
    	printf("Barcode   :  ");
    	scanf("%lf", &barcode[size]);

        validate = bar(barcode, size, maxbar, minbar, validate);

        if(validate == 0){
            printf("Invalid barcode, please enter a barcode with 10 digits\n");
        }
        else if(validate == 1){
            printf("Price     :  ");
            scanf("%lf", &price[size]);
            printf("Quantity  :  ");
            scanf("%d", &quantity[size]);
            size++;
            count++;
        }
    }while(validate != 2);

    total_value = calc(barcode, price, quantity, count);

    printf("Total value goods in stock        %.2lf", total_value);
    return 0;
}
