#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int x);
void dequeue();
void peek();
void display();
int queue[MAX];
int back = -1, front = -1;

int main()
{
    int ele, chs;
    while (9)
    {
        printf("********Queue OPeration*********\n\n");
        printf("1 For Enqueue\n");
        printf("2 For Dequeue\n");
        printf("3 For Peek\n");
        printf("4 For Display\n");
        printf("5 For Exit\n");
        printf("Enter An Option\n");
        scanf("%d", &chs);

        switch (chs)
        {
        case 1:
            printf("Enter Aan Element:");
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
            exit(0);

        default:
            printf("invalid Option\n");
        }
    }

    return 0;
}
void enqueue(int x)
{
    if(front==-1 && back==-1)
    {
        front=back=0;
        queue[back]=x;
    }
    else if((back+1)%MAX==front)
    {
        printf("The Queue Is full\n");    
    }
    else 
    {
        back=(back+1)%MAX;
        queue[back]=x;
    }
}
void dequeue()
{
    if(back==-1 && front==-1)
    {
        printf("The Queue Is Empty\n");
    }
    else if(back==front)
    {
        front=back=-1;
    }
    else
    {
        printf("The Deleleted Element Is : %d",queue[front]);
        front=(front+1)%MAX;
    }
}
void peek()
{
    printf("The Peek Elements is : %d\n",queue[back]);
}
void display()
{
    int i;
    i=front;
    if(back==-1 && front==-1)
    {
        printf("The Queue Is Empty\n");
    }
    else 
    {
        while(i!=back)
        {
            printf("\n%d\n",queue[i]);
            i=(i+1)%MAX;
        }
        printf("\n%d\n",queue[i]);
    }
}