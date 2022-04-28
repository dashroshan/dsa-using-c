/*
You are required to convert the value of temperature from degree Celsius to
degree Fahrenheit. Apply the various problem solving techniques to arrive at the
desired solution to this problem. Also, write a C program for the problem and
test the program for three different set of values.
*/

#include <stdio.h>

double cToF(double c);
double fToC(double f);

void main()
{
    double temp;
    printf("Enter temperature in celsius: ");
    scanf("%lf", &temp);
    printf("%0.2lfC = %0.2lfF\n\nEnter temperature in fahrenheit: ", temp, cToF(temp));
    scanf("%lf", &temp);
    printf("%0.2lfF = %0.2lfC", temp, fToC(temp));
}

double cToF(double c)
{
    return (c * 9.0 / 5.0) + 32.0;
}

double fToC(double f)
{
    return (f - 32.0) * 5.0 / 9.0;
}

/*
Enter temperature in celsius: 32.5
32.50C = 90.50F

Enter temperature in fahrenheit: 204.2
204.20F = 95.67C
*/