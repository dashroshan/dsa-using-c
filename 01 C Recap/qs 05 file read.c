/*
Write a C program to create and open a file named employee.dat
*/

#include <stdio.h>
void main()
{
    FILE *fp;
    fp = fopen("employee.dat", "w");
    fclose(fp);
}