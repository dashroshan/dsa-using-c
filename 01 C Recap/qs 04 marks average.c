/*
Using the fundamental C data types, write a program to read the marks obtained
by a student in three different subjects and then compute and display their
average.
*/

#include <stdio.h>
void main()
{
    double sub1Marks, sub2Marks, sub3Marks;
    printf("Enter marks: ");
    scanf("%lf %lf %lf", &sub1Marks, &sub2Marks, &sub3Marks);
    printf("Average: %0.1lf", (sub1Marks + sub2Marks + sub3Marks) / 3.0);
}

/*
Enter marks: 94.5 96 93
Average: 94.5
*/