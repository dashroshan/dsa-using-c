/*
An integer variable num contains 2 as its value. Print the contents of num after
a left shift operation.
*/

#include <stdio.h>
void main()
{
    int num = 2, by;
    printf("Left shift by: ");
    scanf("%d", &by);
    printf("After left shift by %d: %d", by, num << by);
}

/*
Left shift by: 10
After left shift by 10: 2048
*/