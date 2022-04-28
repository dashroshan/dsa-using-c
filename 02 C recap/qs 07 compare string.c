/*
Write a program to compare two strings and find out if they are same or not
*/

#include <stdio.h>
#define MAX_CHARS 200

int compare(char *s1, char *s2);

void main()
{
    char s1[MAX_CHARS], s2[MAX_CHARS];
    printf("Enter string 1: ");
    scanf("%[^\n]%*c", s1);
    printf("Enter string 2: ");
    scanf("%[^\n]%*c", s2);
    if (!compare(s1, s2))
        printf("The strings are the same");
    else
        printf("The string are not the same");
}

int compare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    if (*s1 != '\0' || *s2 != '\0')
        return *s1 - *s2;
    return 0;
}

/*
Enter string 1: I am Roshan Dash
Enter string 2: I am Roshan Dash
The strings are the same
*/