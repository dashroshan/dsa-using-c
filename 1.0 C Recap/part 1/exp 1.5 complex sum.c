/*
Write a program to accept two complex numbers and find their sum
*/

#include <stdio.h>

typedef struct complex
{
    double real;
    double imginary;
} Complex;

Complex add(Complex c1, Complex c2);

void main()
{
    Complex c1, c2, sum;
    printf("Enter 2 complex numbers as: a+bi c+di: ");
    scanf("%lf+%lfi %lf+%lfi", &c1.real, &c1.imginary, &c2.real, &c2.imginary);
    sum = add(c1, c2);
    printf("Sum: %0.1lf+%0.1lfi", sum.real, sum.imginary);
}

Complex add(Complex c1, Complex c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imginary = c1.imginary + c2.imginary;
    return sum;
}

/*
Enter 2 complex numbers as: a+bi c+di: 2.4+3.2i 6.3+2.5i
Sum: 8.7+5.7i
*/