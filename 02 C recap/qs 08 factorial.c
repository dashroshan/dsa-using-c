/*
Write a function 'fact' that computes and returns the factorial of the number
passed as parameter
*/

#include <stdio.h>

int fact(int num);

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("%d! = %d", num, fact(num));
}

int fact(int num)
{
    int factorial = 1;
    while (num > 1)
    {
        factorial *= num;
        num--;
    }
    return factorial;
}

/*
Enter number: 5
5! = 120
*/