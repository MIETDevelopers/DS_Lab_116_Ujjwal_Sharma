#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 5
void priority_enqueue();
void priority_dequeue();
void display_priority();
int priority_queue[MAX_QUEUE];
void check(int);
int front = -1, rear = -1;
int main()
{
    int n, ch;
    while(1)
    {
        printf("\n1. ENQUEUE ELEMENT IN QUEUE\n");
        printf("\n2. DEQUEUE ELEMENT FROM QUEUE\n");
        printf("\n3. DISPLAY ELEMENTS OF QUEUE\n");
        printf("\n4. EXIT\n");
        printf("\nENTER YOUR CHOICE :: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nENTER VALUE TO BE INSERTED : ");
                scanf("%d",&n);
                priority_enqueue();
                break;
            case 2:
                printf("\nENTER VALUE TO BE DELETED : ");
                scanf("%d",&n);
                priority_dequeue();
                break;
            case 3:
                display_priority();
                break;
            case 4:
                exit(0);
            default:
                printf("\nINVALID CHOICE....!!!!");
        }
    }
}
void priority_enqueue(int data)
{
    if(rear >= MAX_QUEUE -1)
    {
        printf("\nQUEUE OVERFLOW...!!!");
        return;
    }
    else if((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        priority_queue[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}
void check(int data)
{
    int i, j;
    for(i = 0;i <= rear;i++)
    {
        if(data >= priority_queue[i])
        {
            for(j = rear + 1;j > i;j--)
            {
                priority_queue[j] = priority_queue[j - 1];
            }
            priority_queue[i] = data;
            return;
        }
    }
    priority_queue[i] = data;
}
void priority_dequeue(int data)
{
    int i;
    if((front == -1) && (rear == -1))
    {
        printf("\nQUEUE IS EMPTY...!!!");
    }
    for (i = 0; i <= rear; i++)
    {
        if (data == priority_queue[i])
        {
            for (i = 0; i < rear;i++)
            {
                priority_queue[i] = priority_queue[i + 1];
            }
        rear--;
        if (rear == -1)
        {
            front = -1;
        }
        }
    }
    printf("\n%d IS NOT FOUND IN QUEUE TO DELETE", data);
}
void display_priority()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQUEUE IS EMPTY...!!!");
    }
    for (; front <= rear; front++)
    {
        printf("%d",priority_queue[front]);
    }
    front = 0;
}