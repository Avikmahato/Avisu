#include <stdio.h>

int stack[10];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}
void pop()
{
    top--;
}
int isvalue(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    else if(a=='['&&b==']')
    return 1;
    else if(a=='{' && b=='}')
    return 1;
    else 
    return 0;
}
int main()
{
    char par[100];
    int i;

    printf("Enter Parenthesis :");
    gets(par);

    for (i = 0; par[i] != '\0'; i++)
    {
        if(par[i]=='[' || par[i]=='{' || par[i]=='(')
        push(par[i]);
        else 
        {
            if(isvalue(stack[top],par[i])==1)
            pop();
        }
    }
    if(top==-1)
    printf("Parenthesis Are Balanced\n\n");
    else
    printf("Unbalanced\n");

    return 0;
}