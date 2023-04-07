#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct que
{
    int cap;
    int front;
    int back;
    int *array;
};
struct que *queue;
struct que *CreateCqueue(int capa)
{
    queue = malloc(sizeof(struct que));
    queue->cap = capa;
    queue->back = queue->front = -1;
    queue->array = malloc(sizeof(int));
    return queue;
}
void enqueue(int x)
{
    if (queue->back == -1 && queue->front == -1)
    {
        queue->back = queue->front = 0;
        queue->array[queue->back] = x;
    }
    else if ((queue->back + 1)%MAX == queue->front)
    {
        printf("The Queue Is Full\n");
    }
    else
    {
        queue->back = (queue->back + 1) % MAX;
        queue->array[queue->back] = x;
    }
}
void dequeue()
{
    if (queue->front == -1 && queue->back == -1)
    {
        printf("The Queue Is Empty\n");
    }
    else if (queue->front == queue->back)
    {
        queue->front = queue->back = -1;
    }
    else
    {
        printf("The Deleted Element Is : %d", queue->array[queue->front]);
        queue->front = (queue->front + 1) % MAX;
    }
}
void peek()
{
    printf("The Peek Element Is : %d", queue->array[queue->back]);
}
void display()
{
    int i;
    i = queue->front;
    if (queue->front == -1 && queue->back == -1)
        printf("The Queue Is Empty\n");
    else
    {
        while (i != queue->back)
        {
            printf("\n%d\n", queue->array[i]);
            i = (i + 1) % MAX;
        }
        printf("\n%d", queue->array[i]);
    }
}

int main()
{
    int chs, ele;
    queue = CreateCqueue(MAX);
    while (9)
    {
        printf("\n\n**************Queue OPeration*****************\n\n");
        printf("\t1) For Enqueue\n");
        printf("\t______________");
        printf("\t2) For Dequeue\n");
        printf("\t3) For Peek   \n");
        printf("\t4) For Display\n");
        printf("\t5) For Exit\n");
        printf("\t______________");
        printf("Enter An  Option:");
        scanf("%d", &chs);

        switch (chs)
        {
        case 1:
            printf("Enter An Element :");
            scanf("%d", &ele);
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

        default:
            printf("Invalid Option\n");
        }
    }
    return 0;
}