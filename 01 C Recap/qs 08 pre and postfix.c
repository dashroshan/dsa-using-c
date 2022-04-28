/*
Write a C program to demonstrate what impact does the postfix and prefix usage
of increment operator has on the value of an expression.
*/

#include <stdio.h>
void main()
{
    int num = 5;
    printf("Number is: %d\n", num);
    printf("Number++ : %d\n", num++);
    printf("Number is: %d\n", num);
    printf("++Number : %d\n", ++num);
    printf("Number is: %d\n", num);
    printf("\nPrefix increments and then gives it value.\nPostfix gives it value and then increments.");
}

/*
Number is: 5
Number++ : 5
Number is: 6
++Number : 7
Number is: 7

Prefix increments and then gives it value.
Postfix gives it value and then increments.
*/