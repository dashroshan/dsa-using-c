/*
Write a program in C to compute the area of a circle. Use the # define statement
to define pi as named constant.
*/

#include <stdio.h>
#define PI 3.1416

void main()
{
    double radius;
    printf("Enter radius: ");
    scanf("%lf", &radius);
    printf("Area: %0.2lf", 4.0 * PI * radius * radius);
}

/*
Enter radius: 5.23
Area: 343.73
*/