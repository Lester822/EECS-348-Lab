#include <stdio.h>
#include "isOdd.h"

int isOdd(int num) {
	// Prints to the user that the number is odd, if the passed int is odd.
	if (num % 2 == 1) {  // Checks if the remainder after dividing by 2 is 1

		printf("%d is odd.\n", num);  // outputs to user

	}
	return 0;  // return for function
}
