/*
Using for loop, write a program to generate the following pyramid structure:
        9
      9 8 7
    9 8 7 6 5
  9 8 7 6 5 4 3
9 8 7 6 5 4 3 2 1
*/

#include <stdio.h>
#define NUM 9
void main()
{
    for (int line = 1; line <= (NUM + 1) / 2; line++)
    {
        for (int space = 1; space <= ((NUM + 1) / 2 - line) * 2; space++)
            printf(" ");
        for (int n = 0; n < 2 * line - 1; n++)
            printf("%d ", NUM - n);
        printf("\n");
    }
}

/*
        9
      9 8 7
    9 8 7 6 5
  9 8 7 6 5 4 3
9 8 7 6 5 4 3 2 1
*/