#include<stdio.h>
#include<stdlib.h>
#define size 50

int queue[size];
int rear=-1;
int front=-1;

void insert()
{
    int x;
    if(rear==size-1)
    printf("Queue overflow\n");
    else
    {
        if(front==-1)
        front=0;
        printf("Insert an element in queue: ");
        scanf("%d",&x);
        rear=rear+1;
        queue[rear] = x;
    }
}


void delete()
{

    if(front==-1 || front>rear)
    {
        printf("queue is underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from the queue is %d\n",queue[front]);
        front=front+1;
    }
}


void display()
{
    int i;
    if(front==-1)
    printf("Queue is empty\n");
    else
    {
        printf("Queue is: ");
        for(i=front;i<=rear;i++)
            printf("%d \t",queue[i]);
            printf("\n");
    }
}


void main()
{
    int ch;
    while(1)
    {
       printf("\n");
       printf("1:Insert an element\n");
       printf("2:Delete an element\n");
       printf("3:Display an element\n");
       printf("4:Exit \n");
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
        insert();
        break;

        case 2:
        delete();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(1);
        break;

        default:
        printf("Wrong choice\n");
       }
    }
}
