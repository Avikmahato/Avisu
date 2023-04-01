#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct st
{
    int top;
    int capa;
    int *array;
};
struct st *createstack(int cap)
{
    struct st *stack;
    stack = malloc(sizeof(struct st));
    stack->top = -1;
    stack->capa = cap;
    stack->array = malloc(cap * sizeof(int));
    return stack;
}
void push(struct st *stack, int x)
{
    if (stack->top == MAX - 1) {
        printf("\n\n\nThe Stack Is Full\n\n");
        exit(0);
    }
    else
    {
        stack->top++;
        stack->array[stack->top] = x;
    }
}
void pop(struct st *stack)
{
    if (stack->top == -1) {
        printf("Stack Is Empty\n");
        exit(0);
    }
    else
    {
        printf("The Removal ELement Is : %d\n\n", stack->array[stack->top]);
        stack->top--;
    }
}
void peek(struct st *stack)
{
    if(stack->top==-1)
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        printf("The Peek Element Is : %d\n\n", stack->array[stack->top]);
    }
}

void traversal(struct st *stack)
{
    int i;
    printf("The Elements Are:\n\n");
    for (i = 0; i <= stack->top; i++)
    {
        printf("\n%d\n", stack->array[i]);
    }
}
int main()
{
    int ele, chs;
    struct st *stack;
    stack=createstack(MAX);
    while (9)
    {

        printf("****************Struct OPeration**************\n\n");
        printf("1 For push:\n");
        printf("2 For pop:\n");
        printf("3 For peek element:\n");
        printf("4 For display:\n");
        printf("5 For exit:\n");

        printf("\n\nEnter An Option:\n\n");
        scanf("%d", &chs);

        switch (chs)
        {
        case 1:
            printf("Enter An Element :");
            scanf("%d", &ele);
            push(stack, ele);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            peek(stack);
            break;

        case 4:
            traversal(stack);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Option\n\n");
        }
    }
    
    return 0;
}