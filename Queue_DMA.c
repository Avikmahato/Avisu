#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct que
{
    int cap;
    int *array;
    int back;
    int front;
};
struct que *queue;
struct que *Createqueue()
{
    queue=malloc(sizeof(struct que));
    queue->back=-1;
    queue->front=-1;
    queue->cap=MAX;
    queue->array=malloc(queue->cap*sizeof(int));
    return queue;
}
void enqueue(int x)
{
    if(queue->back==queue->cap-1)
    printf("The Queue Is Full\n");
    else if(queue->front==-1)
    {
        queue->front++;
        queue->array[++queue->back]=x;
    }
    else
    {
        queue->array[++queue->back]=x;
    }
}
void dequeue()
{
    if(queue->front==-1 || queue->back<queue->front)
    printf("The Queue Is Empty\n");
    else
    {
        printf("The Deleted Elements Is : %d \n",queue->array[queue->front]);
        queue->front++;
    }
}
void peek()
{
    if(queue->back==-1)
    {
        printf("The Queue Is Empty\n");
    }
    else
    {
        printf("The Peek Element Is : %d",queue->array[queue->back]);
    }
}
void display()
{
    int i;
    if(queue->back==-1 || queue->front>queue->back)
    printf("The Queue Is Empty\n");
    else
    {
        printf("'The Elements Are:\n");
        for(i=queue->front;i<=queue->back;i++)
        {
            printf("\n%d\n",queue->array[i]);
        }
    }
}


int main()
{
    struct que *avik;
    avik=Createqueue();
    int chs,ele;
    while(9)
    {
        printf("*******Queue Operation********\n\n");
        printf("  _______________\n");
        printf(" | 1 For Enqueue |:\n");
        printf(" |---------------|\n");
        printf(" | 2 For Dequeue:|\n");
        printf(" |---------------|\n");
        printf(" | 3 For Peek   :|\n");
        printf(" |---------------|\n");
        printf(" | 4 For Display:|\n");
        printf(" |---------------|\n");
        printf(" | 5 For Exit   :|\n");
        printf(" |_______________|\n");
        printf("\nEnter An Option:");
        scanf("%d",&chs);

        switch(chs)
        {
            case 1:
            printf("Enter An Element:");
            scanf("%d",&ele);
            enqueue(ele);
            break;

            case 2:
            dequeue();
             break;

             case 3:
             peek();
             break;

             case 4:
             display();
             break;

             case 5:
             free(queue);
             free(queue->array);
             exit(0);

             default :
             printf("Invalid Ooption\n\n");
        }
    }

    return 0;
}