#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct infix
{
    int top;
    char *array;
    int cap;
};
struct infix *stack;

struct infix *InfixTo(int capa)
{
    stack=malloc(sizeof(struct infix));
    stack->top=-1;
    stack->cap=capa;
    stack->array=malloc(stack->cap*sizeof(char));
    return stack;
}
void push(char s)
{
    stack->array[++stack->top]=s;
}
void pop()
{
    stack->top--;
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
int main()
{
    char eq[100];
    int i,j;
    stack=InfixTo(MAX);

    printf("Enter An Infix Equation:");
    gets(eq);

    for(i=0;eq[i]!='\0';i++)
    {
        if(eq[i]>='0'&&eq[i]<='9')
        {
            printf("%c",eq[i]);
        }
        else if(eq[i]=='(')
        {
            push(eq[i]);
        }
        else if(eq[i]==')')
        {
            for(j=stack->top;stack->array[stack->top]!='(';j--)
            {
                printf("%c",stack->array[stack->top]);
                pop();
            }
            pop();
        }
        else if(stack->top==-1)
        {
            switch(eq[i])
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
            if(pref(eq[i],stack->array[stack->top])==1)
            {
                push(eq[i]);
            }
            else
            {
                printf("%c",stack->array[stack->top]);
                pop();
                i--;
            }
        }
    }
    for(i=stack->top;i>=0;i--)
    {
        printf("%c",stack->array[stack->top]);
        //pop();
    }

    free(stack);
    free(stack->array);

    return 0;
}