/*
Using the modulo division operator, write a program to determine if the given
number is divisible by 7 or not.
*/

#include <stdio.h>
void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    if (num % 7 == 0)
        printf("Divisible by 7");
    else
        printf("Not divisible by 7");
}

/*
Enter number: 21
Divisible by 7
*/