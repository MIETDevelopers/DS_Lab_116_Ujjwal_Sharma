/*AUTHOR NAME :: UJJWAL SHARMA
DATE :: 5TH OF JULY 2021
PURPOSE :: C PROGRAM FOR OPERATIONS IN QUEUE*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
 
void insert();
void delete();
void display();
int queue_arr[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.INSERT ELEMENT IN QUEUE \n");
        printf("2.DELETE ELEMENT FROM QUEUE \n");
        printf("3.DISPLAY ELEMENTS OF QUEUE \n");
        printf("4.QUIT\n");
        printf("ENTER YOUR CHOICE :: ");
        scanf("%d", &choice);
        switch (choice)
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
                printf("WRONG CHOICE...!!!\n");
        }
    }
    return 0;
}
 
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("\nQUEUE OVERFLOW...!!!\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("\nINSERT ELEMENT IN QUEUE :: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_arr[rear] = add_item;
        
    }
}
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("\nQUEUE UNDERFLOW...!!!\n");
    }
    else
    {
        printf("ELEMENT DELETED FROM QUEUE IS :: %d\n", queue_arr[front]);
        front = front + 1;
    }
}
 
void display()
{
    int i;
    if (rear == - 1)
        printf("\nQUEUE IS EMPTY...!!!\n");
    else
    {
        printf("\nQUEUE IS :: \n");
        for (i = front; i <= rear; i++)
            printf("%d\t", queue_arr[i]);
    }
}