/*
Write a program to find the largest among three numbers
*/

#include <stdio.h>
void main()
{
    int TOTAL = 3, largest, num;
    printf("Enter %d numbers: ", TOTAL);
    for (int i = 1; i <= TOTAL; i++)
    {
        scanf("%d", &num);
        if (i == 1)
            largest = num;
        else if (num > largest)
            largest = num;
    }
    printf("Largest among the %d numbers: %d", TOTAL, largest);
}

/*
Enter 3 numbers: 3 6 4
Largest among the 3 numbers: 6
*/