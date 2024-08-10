#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int top = -1;
char s[30][30]; // Fix the declaration of the stack array

bool isoperand(char tkn)
{
    if ((tkn == '(') || (tkn == ')') || (tkn == '^') || (tkn == '*') || (tkn == '/') || (tkn == '%') || (tkn == '+') || (tkn == '-'))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isfull()
{
    if (top == 29)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char str[30])
{
    if (isfull())
    {
        printf("\nStack Full. Can't Push \n");
    }
    else
    {
        strcpy(s[++top], str);
    }
}

void pop(char str[30])
{
    if (isempty())
    {
        printf("\nStack Empty\n");
    }
    else
    {
        strcpy(str, s[top--]);
    }
}

void postinfx(char post[30])
{
    char s1[30], s2[30], s3[30], temp[30], inf[30];
    int i;
    strrev(post);
    for (i = 0; post[i] != '\0'; i++)
    {
        s1[0] = post[i];
        s1[1] = '\0';
        if (isoperand(post[i]) == true)
            push(s1);
        else
        {
            pop(s2);
            pop(s3);
            strcpy(inf, ")");
            strcat(inf, s3);
            strcat(inf, s1);
            strcat(inf, s2);
            strcat(inf, "(");
            push(inf);

        }
    }
 
    strrev(inf);
    printf("\nThe infix expression is: ");
    printf("\n%s", inf);
}

int main()
{
    char c[30];
    printf("Enter The Expression : \n");
    scanf("%s", c);
    postinfx(c);

    return 0;
}
