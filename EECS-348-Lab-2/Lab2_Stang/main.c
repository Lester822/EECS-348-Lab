#include <stdio.h>
#include "isEven.h"
#include "isOdd.h"

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    isEven(num);
    isOdd(num); // calls isOdd from isOdd.c/isOdd.h
    return 0;
}
