/*
Using for loop, write a program to generate the following pyramid structure:
              0
            1 0 1
          2 1 0 1 2
        3 2 1 0 1 2 3
      4 3 2 1 0 1 2 3 4
    5 4 3 2 1 0 1 2 3 4 5
  6 5 4 3 2 1 0 1 2 3 4 5 6
7 6 5 4 3 2 1 0 1 2 3 4 5 6 7
*/

#include <stdio.h>
#define NUM 7
void main()
{
    for (int line = 0; line <= NUM; line++)
    {
        for (int space = 1; space <= (NUM - line) * 2; space++)
            printf(" ");
        for (int num = line; num > 0; num--)
            printf("%d ", num);
        for (int num = 0; num <= line; num++)
            printf("%d ", num);
        printf("\n");
    }
}

/*
              0
            1 0 1
          2 1 0 1 2
        3 2 1 0 1 2 3
      4 3 2 1 0 1 2 3 4
    5 4 3 2 1 0 1 2 3 4 5
  6 5 4 3 2 1 0 1 2 3 4 5 6
7 6 5 4 3 2 1 0 1 2 3 4 5 6 7
*/