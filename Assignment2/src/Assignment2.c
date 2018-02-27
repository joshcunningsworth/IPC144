/*
 ============================================================================
 Name        : Assignment2.c
 Author      : Josh Cunningham
 Date		 : November 6th, 2013
 Studnet ID  : 016874133
 Description : This program will create a weekly payroll report and calculate
 salary or hourly rate. It will display a report at the end with tax deductions
 and gross/net pay.

 I declare that the attached assignment is wholly my
 own work in accordance with Seneca Academic Policy.  No part of this
 assignment has been copied manually or electronically from any
 other source (including web sites) or distributed to other students.
 ============================================================================
 */

// including the standard header files and libraries
#include <stdio.h>
#include <stdlib.h>

// declaring a list of function prototypes
// function prototype for grosspayhourly which has 2 double variables in the parameters
double grosspayhourly(double rate, double numberofhours);
// function prototype for grosspaysalaried which has 1 double variable in the parameters
double grosspaysalaried(double annualsalary);
double longtermbenefits(double gross);
double employmentinsurance(double gross);
double canadapensionplan(double gross);
void taxes(double gross, double* ftaxpointer, double* ptaxpointer);
void outputSalaried(int id, double salary, double gross, double ltb, double ei,
		double cpp, double ptax, double ftax, int year, int month, int day);

void outputHourly(int id, double rate, double hours, double gross, double ltb, double ei,
        double cpp, double ptax, double ftax, int year, int month, int day);

// initializing the main function
int main(void){
	// declares id and choicerate as integer variables
	int id;
	// declares rate, numberofhours and annualsalary as double variables
	double rate = 0, numberofhours = 0;
	double annualsalary = 0, gross = 0;
	double ltb = 0, ei = 0, cpp = 0, ptax = 0, ftax = 0;
	int year = 0, month = 0, day = 0;
	char choice;
	char loop;

	// asking the user to enter the year month and day and storing them in the respective variable
	printf("Enter the Year: ");
	scanf("%d", &year);
	printf("Enter the Month: ");
	scanf("%d", &month);
	printf("Enter the Day: ");
	scanf("%d", &day);

	do {

	// print statements asking the user for their Employee Number
	printf("Enter Your 3 Digit Employee Number: ");
	// scanning the keybuffer and saving the data into the variable id
	scanf("%d", &id);

	printf("Press H - Hourly Rate\nPress S - Annual Salary");
	scanf(" %c", &choice);
	if (choice == 'H'){
		// prompts the user to enter the hourly rate and scans the keyboard buffer to store the value
		printf("Enter Your Hourly Rate: ");
		scanf("%lf", &rate);
		printf("Enter the Number of Hours Worked: ");
		scanf("%lf", &numberofhours);

		gross = grosspayhourly(rate, numberofhours);
	}
	// if the user enters S the annual salary will be asked for
	else if (choice == 'S'){
		printf("Enter your Annual Salary");
		scanf("%lf", &annualsalary);

		// calling the function grosspaysalaried and saving it in gross
		gross = grosspaysalaried(annualsalary);
	}

	// saving the returned values of the functions into their respective variables
	ltb = longtermbenefits(gross);
	ei = employmentinsurance(gross);
	cpp = canadapensionplan(gross);
	taxes(gross, &ftax, &ptax);

	// if the user selected the hourly rate method then this output function is run
	if (choice == 'H'){
		outputHourly(id, rate, numberofhours, gross, ltb, ei, cpp, ptax, ftax, year, month, day);
	}
	// if the user selected the annual salary then this output function is run
	else if (choice == 'S'){
		outputSalaried(id, annualsalary, gross, ltb, ei, cpp, ptax, ftax, year, month, day);
	}

	printf("Do you wish to run the program again?");
	printf("\nY - Yes\nN - No\n");
	scanf(" %c", &loop);

	} while (loop != 'N');

	// the main function has no return value and is set to zero
	return 0;
}

// calculates the gross hourly rate of the employee
double grosspayhourly(double rate, double numberofhours){
	double totalpayrate = 0;
	double hourlywage = 0;
	double overtime = 0;

	// if statement that checks to see if the employee worked more than 44 hours
	if (numberofhours > 44){
		overtime = (rate * 1.5) * (numberofhours - 44);
	}

	// calculations for the employees hourly wage and the employees total pay rate
	hourlywage = numberofhours * rate;
	totalpayrate = overtime + hourlywage;

	// returns the total hourly pay rate to the main function
	return totalpayrate;
}

// calculates the employees gross annual salary
double grosspaysalaried(double annualsalary){
	annualsalary = annualsalary / 52;

	// return the annual salary to the main function
	return annualsalary;
}

// calculates the employee's long term benefits
double longtermbenefits(double gross){
	// creates a local double variable called ltb
	int ltb;
	ltb = gross;
	ltb = ltb / 100;
	ltb = ltb * 2;

	// if the long term benefit is greater than 100 then it will cap it at 100
	if (ltb > 100){
		ltb = 100;
	}

	// returns ltb to the main function
	return ltb;
}

// function to calculate the employment insurance
double employmentinsurance(double gross){
	// creates a local variable called ei
	double ei = 0;
	ei = gross * 0.014;

	if(ei >11.80){
	ei = 11.80;
	}

	// returns the employment insurance to the main
	return ei;
}

double canadapensionplan(double gross){
	double cpp = 0;

	//
	if (gross >= 700){
		cpp = 700 * 0.016;
	}
	else{
		cpp = gross * 0.016;
	}
	return cpp;
}

void taxes(double gross, double* ftaxpointer, double* ptaxpointer){
	double annual = 0;
	double ftax;
	ftax = gross * 52;

	// if statement for checking how much the tax is
	if (ftax >= 20000){
		annual = ftax / 20000;
	}
	if (annual <= 1 && annual >= 0){
		ftax = ftax * 0.16;
	}
	else if (annual <= 2 && annual > 1){
		ftax = ftax - 20000;
		ftax = ftax * 0.23;
		ftax = ftax + (20000 * 0.16);
	}
	else if (annual > 2){
		ftax = ftax - 40000;
		ftax = ftax * 0.29;
		ftax = ftax + (20000 * 0.23) + (20000 * 0.16);
	}

	*ftaxpointer = ftax;
	*ptaxpointer = ftax * 0.47;

}

// output annual salary function
void outputSalaried(int id, double salary, double gross, double ltb, double ei,
		double cpp, double ptax, double ftax, int year, int month, int day){

	// declaring local variables deduction and netpay
	double deductions, netpay;

	// converting the taxes into weekly payments
	ftax = ftax / 52;
	ptax = ptax / 52;

	// calculation for the deduction
	deductions = ltb + ei + cpp + ftax + ptax;
	netpay = gross - deductions;
	printf("Yourname Payroll Systems\n102 Orfus Road, Downsview ON\n");
	printf("Employee Number: %d\t\tFor Week Ending: %d, %d, %d", id, year, month, day);
	printf("Salary Paid: %.2lf\n", salary);
	printf("GROSS PAY: \t\t%.2lf\n", gross);
	printf("DEDUCTIONS: \nLong Term Benefits: \t\t%.2lf\n", ltb);
	printf("Employment Insurance: \t\t%.2lf\n", ei);
	printf("Canada Pension Plan: \t\t%.2lf\n", cpp);
	printf("Provincial Tax: \t\t%.2lf\n", ptax);
	printf("Federal Tax: \t\t%.2lf\n", ftax);
	printf("\nTOTAL DEDUCTIONS: \t\t%.2lf\n", deductions);
	printf("\nNET PAY: \t\t%.2lf\n", netpay);

}

// output hourly rate function
void outputHourly(int id, double rate, double hours, double gross, double ltb, double ei,
       double cpp, double ptax, double ftax, int year, int month, int day){

	// declaring local variables deduction and netpay
	double deductions, netpay;

	// calculating the taxes into weekly payments
	ftax /= 52;
	ptax /= 52;

	// calculation for deduction
	deductions = ltb + ei + cpp + ftax + ptax;
	netpay = gross - deductions;
	// print statements in the prompt format
	printf("Yourname Payroll Systems\n102 Orfus Road, Downsview ON\n");
	printf("Employee Number: %d\t\tFor Week Ending: %d, %d, %d\n", id, year, month, day);
	printf("Hourly Rate: %.2lf\t\tHours Worked: %.2lf\n", rate, hours);
	printf("GROSS PAY: \t\t\t%.2lf\n", gross);
	printf("DEDUCTIONS: \nLong Term Benefits: \t\t%.2lf\n", ltb);
	printf("Employment Insurance: \t\t%.2lf\n", ei);
	printf("Canada Pension Plan: \t\t%.2lf\n", cpp);
	printf("Provincial Tax: \t\t%.2lf\n", ptax);
	printf("Federal Tax: \t\t\t%.2lf\n", ftax);
	printf("\nTOTAL DEDUCTIONS: \t\t%.2lf\n", deductions);
	printf("\nNET PAY: \t\t\t%.2lf\n", netpay);
}



