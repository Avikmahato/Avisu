#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void push(char);
void pop();
int pref(char, char);
int top = -1;
char stack[MAX];

int main()
{
    char eq[100];
    int i, k;

    printf("Enter An Infix Eqution:");
    gets(eq);

    for (i = 0; eq[i] != '\0'; i++)
    {
        if (eq[i] >= '0' && eq[i] <= '9')
        {
            printf("%c", eq[i]);
        }
        else if (eq[i] == '(')
        {
            push(eq[i]);
        }
        else if (eq[i] == ')')
        {
            for (k = top; stack[k] != '('; k--)
            {
                printf("%c", stack[k]);
                pop();
            }
            pop();
        }
        else if (top == -1)
        {
            switch (eq[i])
            {
            case '+':
                push(eq[i]);
                break;

            case '-':
                push(eq[i]);
                break;
            case '*':
                push(eq[i]);
                break;
            case '/':
                push(eq[i]);
                break;
            case '^':
                push(eq[i]);
                break;
            }
        }
        else
        {
            if (pref(eq[i], stack[top]) == 1)
            {
                push(eq[i]);
            }
            else
            {
                printf("%c", stack[top]);
                i--;
                pop();
            }
        }
    }
    for (i = top; i >= 0; i--)
        printf("%c", stack[i]);

    return 0;
}
void push(char x)
{
    stack[++top] = x;
}
void pop()
{
    top--;
}
int pref(char a, char b)
{
    if (a == '^' && (b == '+' || b == '*' || b == '/' || b == '-'))
        return 1;
    else if (a == '*' && (b == '-' || b == '/' || b == '+'))
        return 1;
    else if (a == '/' && (b == '+' || b == '-'))
        return 1;
    else if((a=='+'||a=='-'||a=='*'||a=='/'||a=='^')&&b=='(')
    return 1;
    else if (a == '+' && b == '-')
    return 1;
    else if(a==b)
    return 0;
    else
    return 0;
}