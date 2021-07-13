#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], choice, val, i, topA=-1, topB=MAX;
void push_A();
void push_B();
void pop_A();
void pop_B();
void display_A();
void display_B();
void main()
{
    do
    {
        printf("\n!!!!!...............MENU...............!!!!!\n");
        printf("\n1. PUSH ELEMENT IN STACK A\n2. PUSH ELEMENT IN STACK B\n3. POP ELEMENT IN STACK A\n4. POP ELEMENT IN STACK B\n5. DISPLAY ELEMENT OF STACK A\n6. DISPLAY ELEMENT OF STACK B\n7. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push_A();
                break;
            case 2:
                push_B();
                break;
            case 3:
                pop_A();
                break;
            case 4:
                pop_B();
                break;
            case 5:
                display_A();
                break;
            case 6:
                display_B();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("\nPlease Enter a valid number....!!!!\n");
                break;
        }
    }while(1);
}
void push_A()
{
    if (topA == MAX-1)
    {
        printf("\nSTACK IS OVERFLOW...!!!\n");
    }
    else
    {
        printf("Enter element to be inserted in stack A: ");
        scanf("%d",&val);
        topA = topA+1;
        stack[topA] = val;
    }
}
void push_B()
{
    if (topB-1 == topA)
    {
        printf("\nSTACK IS OVERFLOW\n");
    }
    else
    {
        printf("Enter element to be inserted in stack B: ");
        scanf("%d",&val);
        topB = topB-1;
        stack[topB] = val;
    }
}
void pop_A()
{
    if (topA == -1)
    {
        printf("\nSTACK IS UNDERFLOW\n");
    }
    else
    {
        printf("Deleted element in stack A is : %d\n", stack[topA]);
        topA = topA-1;
        stack[topA] = val;
    }
}
void pop_B()
{
    if (topB == MAX)
    {
        printf("\nSTACK IS UNDERFLOW\n");
    }
    else
    {
        printf("Deleted element in stack B is : %d\n",stack[topB]);
        topB = topB+1;
        stack[topB] = val;
    }
}
void display_A()
{
    if (topA == -1)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    else
    {
        printf("\nStack Element in Stack A is : \n");
        for(i=topA;i>=0;i--)
            printf("%d\n", stack[i]);
    }
}
void display_B()
{
    if (topB == MAX)
    {
        printf("\nSTACK IS EMPTY\n");
    }
    else
    {
        printf("\nStack Element in Stack B is : \n");
        for(i=topB;i<MAX;i++)
            printf("%d\n", stack[i]);
    }
}