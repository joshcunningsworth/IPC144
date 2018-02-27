/*
 ============================================================================
 Name        : group_5.c
 Members     : Josh Cunningham, Sohaib Ali, Pylyp Khonin, Keon Cunningham
 Date        : September 30, 2013
 Description : function for library program. returns the transaction number
 the total books returned, the books borrowed and the total books
 on the account
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void display_totals(int num, int total_books, int books_borr, int total);

int main() {
	printf("Return Function!\n");

	display_totals(1,2,3,4);

	return 0;
}

void display_totals(int num, int total_books, int books_borr, int total){


		printf("Transaction Summary\n");
		printf("==================================\n");
		printf("Transaction #: %d\n", num);
		printf("Total books returned: %d\n", total_books);
		printf("Total books borrowed: %d\n", books_borr);
		printf("Total on account: %d\n", total);
		printf("==================================\n");
	}
