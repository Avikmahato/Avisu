#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct st
{
    int back,front;
    int cap;
    int *array;
};
struct st *CreateStack()
{
    struct st *stack;
    stack=malloc(sizeof(struct st));
    stack->back=-1;
    stack->front=-1;
    stack->cap=MAX;
    stack->array=malloc(sizeof(int));
    return stack;
}
void enqueue(struct st *stack,int x)
{
    if(stack->back==stack->cap-1)
        printf("The Queue Is Full\n");
    else if(stack->front==-1)
    {
        stack->front++;
        stack->array[++stack->back]=x;
    }
    else
    {
        stack->array[++stack->back]=x;
    }
}

void dequeue(struct st *stack)
{
    if(stack->front==-1 || stack->front>stack->back)
        printf("The Queue Is Empty\n");
    else
    {
        printf("The Deleted Element Is :%d\n",stack->array[stack->front]);
        stack->front++;
    }
}
void peek(struct st *stack)
{
    if(stack->back)
        printf("The Queue Is Empty\n");
    else
        printf("The Peek Element Is:%d\n",stack->array[stack->back]);
}
void display (struct st* stack)
{   int i;
    if(stack->back==-1 || stack->front>stack->back)
        printf("The Queue Is Empty\n");
    else
    {
        printf("The Elements Are:\n");
        for(i=stack->front; i<=stack->back; i++)
        {
            printf("\n|%d|\n",stack->array[i]);
        }
    }
}
int main()
{
    int ele,choose;
    struct st *stack;
    stack=CreateStack();
    while(8)
    {
        printf("*****Queue Operation*****\n\n");
        printf("_____________________\n");
        printf(":  1 For Enqueue    :\n");
        printf("---------------------\n");
        printf(":  2 For Dequeue    :\n");
        printf("---------------------\n");
        printf(":  3 For Peek       :\n");
        printf("---------------------\n");
        printf(":  4 For Display    :\n");
        printf("---------------------\n");
        printf(":  5 For Exit       :\n");
        printf("_____________________\n");
        printf("\nEnter An Option:\n");
        scanf("%d",&choose);

        switch(choose)
        {
        case 1:
            printf("Enter An Element:");
            scanf("%d",&ele);
            enqueue(stack,ele);
            break;

        case 2:
            dequeue(stack);
            break;

        case 3:
            peek(stack);
            break;

        case 4:
            display(stack);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Option\n");
        }
    }

    return 0;
}