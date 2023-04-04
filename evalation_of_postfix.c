#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void push(char);
void pop();
char stack[100];
int top = -1, op;

int main()
{
    char a[100];
    int i;

    printf("Enter postfix epression:");
    gets(a);

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            push(a[i]);
        }
        else
        {
            switch (a[i])
            {

            case '+':
                op =(stack[top-1]-'0') + (stack[top]-'0');
                
                break;

            case '-':
                op =(stack[top-1]-'0') - (stack[top]-'0');
                
                break;

            case '*':
                op =(stack[top-1]-'0') * (stack[top]-'0');
                
                break;

            case '/':
                op =(stack[top-1]-'0') / (stack[top]-'0');
                
                break;

            case '^':
                op =pow((stack[top-1]-'0'),(stack[top]-'0'));
                
                break;
            }
            pop();
            pop();
            push(op+'0');
        }
    }

    printf("After Evaluation The Result Is : %d",(stack[top]-'0'));
    

    return 0;
}

void push(char s)
{
    top++;
    stack[top] = s;
}
void pop()
{
    top--;
}