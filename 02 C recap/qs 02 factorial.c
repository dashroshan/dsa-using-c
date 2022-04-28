/*
Write a C program to find the factorial of a number using while loop
*/

#include <stdio.h>
void main()
{
    int num, factorial = 1;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("%d! = ", num);
    while (num > 1)
    {
        factorial *= num;
        num--;
    }
    printf("%d", factorial);
}

/*
Enter number: 5
5! = 120
*/