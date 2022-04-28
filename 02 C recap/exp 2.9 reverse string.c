/*
Write a program to print the reverse of a string
*/

#include <stdio.h>
#include <string.h>
#define MAX_CHARS 200

void reverse(char *s);

void main()
{
    char string[MAX_CHARS];
    printf("Enter string: ");
    scanf("%[^\n]", string);
    reverse(string);
    printf("Reversed string: %s", string);
}

void reverse(char *s)
{
    int len = strlen(s);
    char temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

/*
Enter string: I am Roshan Dash
Reversed string: hsaD nahsoR ma I
*/