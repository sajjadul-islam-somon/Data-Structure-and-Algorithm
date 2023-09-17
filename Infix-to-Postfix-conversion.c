//Code to convert a infix data to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_OF_INFIX 100

int precedence(char op)
{ // precedence checking
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixtopostfix(char *infix)
{
    int i, j, top = -1;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX_SIZE_OF_INFIX];
    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
        { // space ignore
            continue;
        }
        if (isalnum(infix[i]))
        { // if character is operand
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        { // opening bracket
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        { // closing bracket
            while (top > -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if (isOperator(infix[i]))
        { // if character is operator
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        while (top > -1)
        { // remaining item in stack
            postfix[j++] = stack[top--];
        }
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[MAX_SIZE_OF_INFIX] = "a+b-c*d";
    char *postfix = infixtopostfix(infix);
    printf("%s", postfix);
}
