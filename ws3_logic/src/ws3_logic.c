/*
 ============================================================================
 Name        : ws3_logic.c
 Author      : Josh Cunningham
 Date	     : Sept 29th, 2013
 Description : sin Validator that checks if the sin is valid or not
 ============================================================================
 */

//Program that checks if the sin card is valid or not

#include <stdio.h>

int main(){
	long int sin=0;
	int even = 0, odd = 0;
	int num1 = 0, num3 = 0, num5 = 0, num7 = 0, num9 = 0;
	int num2 = 0, num4 = 0, num6 = 0, num8 = 0;
	int num8_1 = 0, num6_1 = 0, num4_1 = 0 , num2_1 = 0;
	int total = 0, total2 = 0;
	int retry = 0;
	int end_program = 0;
	long int max = 999999999; //maximum number and minimum number a sin card can have
	long int min = 111111111;

 printf("sin Validator\n=============\n");

 do{

 	printf("sin (0 to quit) :");
 	scanf("%ld", &sin);

 	num1 = sin / 100000000.0; //these steps separate sin digits
 	num2 = sin / 10000000.0;
 	num3 = sin / 1000000.0;
 	num4 = sin / 100000.0;
 	num5 = sin / 10000.0;
 	num6 = sin / 1000.0;
 	num7 = sin / 100.0;
 	num8 = sin / 10.0;

 	num1 = num1 % 10;
 	num2 = num2 % 10;
 	num3 = num3 % 10;
 	num4 = num4 % 10;
 	num5 = num5 % 10;
 	num6 = num6 % 10;
 	num7 = num7 % 10;
 	num8 = num8 % 10;
 	num9 = sin % 10;

 	num8 = num8 + num8; //calculations for checking validation
 	num6 = num6 + num6;
 	num4 = num4 + num4;
 	num2 = num2 + num2;

 	num8_1 = num8;
 	num6_1 = num6;
 	num4_1 = num4;
 	num2_1 = num2;

 	num8 = num8 % 10;
 	num8_1 = num8_1 / 10.0;
 	num6 = num6 % 10;
 	num6_1 = num6_1 / 10.0;
 	num4 = num4 % 10;
 	num4_1 = num4_1 / 10.0;
 	num2 = num2 % 10;
 	num2_1 = num2_1 / 10.0;

 	even = num8 + num8_1 + num6 + num6_1 + num4 + num4_1 + num2 + num2_1;

 	odd = num7 + num5 + num3 + num1;

 	total = even + odd;

 	total2 = total / 10.0;
 	total2 = (total2 + 1) * 10;
 	total = total2 - total;

 	if (sin == 0){

 	 printf("Have a Nice day\n"); //changes end_program's variable when user enters 0 so the loop ends
 	 end_program = 1;

 	} else if(sin > max || sin < min){

 	 printf("Invalid Number, Try Again\n"); //sin number entered is not correct
 	 // increments the retry value
 	 retry++;

 	} else if(total != num9){

 	 printf("This is not a valid sin.\n"); //sin is not valid

 	} else if(total == num9){

 	 printf("This is a valid sin.\n"); //valid sin

 	}
 } while (end_program != 1); //loop ends when user enters 0

 return 0;

}

