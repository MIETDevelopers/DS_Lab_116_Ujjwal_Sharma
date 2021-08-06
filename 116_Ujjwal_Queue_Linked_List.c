/**
**********************************************************************************************************************************************************************************************************************************
* @file:	116_Ujjwal_Queue_Linked_List.c
* @author:	UJJWAL SHARMA
* @date:	06-08-2021 17:19:03 Friday
* @brief:	PROGRAM FOR IMPLEMENTATION OF QUEUE AND DEVELOP FUNCTIONS TO PERFORM ENQUEUE, DEQUEUE AND DISPLAY OPERATIONS USING LIKED LIST
**********************************************************************************************************************************************************************************************************************************
**/
#include <stdio.h>      //PRE-PROCESSOR DIRECTIVE TO INCLUDE STANDARD INPUT OUTPUT FUNCTION HEADER FILE
#include <stdlib.h>     //PRE-PROCESSOR DIRECTIVE TO INCLUDE STANDARD LIBRARY FUNCTION HEADER FILE
struct node     //CREATING STRUCTURE OF NODE DATA TYPE
{
    int data;               //DATA MEMBERS OF THE STRUCTURE DATA TYPE NODE
    struct node *next;
};
struct node *f = NULL;      //CREATING FRONT NODE
struct node *r = NULL;      //CREATING REAR NODE
void enqueue();     //FUNCTION PROTOTYPE
void dequeue();     //FUNCTION PROTOTYPE
void display();     //FUNCTION PROTOTYPE
void main()
{       //STARTING OF MAIN FUNCTION
    int ch;     //DECLARING VARIABLE 'ch' OF 'int' DATA TYPE
    while (ch != 4)     //WHILE LOOP
    {
        printf("\n1.ENQUEUE ELEMENT IN THE QUEUE\n2.DEQUEUE ELEMENT FROM THE QUEUE\n3.DISPLAY ELEMENT IN THE QUEUE\n4.EXIT\n");
        printf("\nENTER YOUR CHOICE :: ");      //PRINT USER INPUT
        scanf("%d", &ch);                       //READ USER INPUT
        switch (ch)     //SWITCH STATEMENT
        {
            case 1:     //CASE 1
                enqueue();      //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 2:     //CASE 2
                dequeue();      //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 3:     //CASE 3
                display();      //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 4:     //CASE 4
                exit(0);        //EXIT FUNCTION WHICH EXIT SUCCESSFULLY WITHOUT TERMINATING THE PROGRAM
                break;      //BREAK STATEMENT
            default:        //DEFAULT STATEMENT
                printf("\nPLEASE ENTER A VALID CHOICE...!!!\n");
                break;      //BREAK STATEMENT
        }
    }
}
void enqueue()      //FUNCTION DEFINITION
{
    struct node *ptr;   //CREATING NEW NODE 'ptr'
    int item;       //DECLARING VARIABLE 'item' OF 'int' DATA TYPE
    ptr = (struct node *) malloc(sizeof(struct node));      //MEMORY ALLOCATING OF NEW NODE 'ptr'
    if (ptr == NULL)    //CONDITION OF CHECKING WHETHER THERE IS ANY ELEMENT IN THE QUEUE
    {
        printf("\nNO SPACE IN THE QUEUE...!!!\n");
    }
    else        //ELSE STATEMENT
    {
        printf("\nENTER THE VALUE :: ");
        scanf("%d", &item);
        ptr->data = item;
        if (f == NULL)      //SPECIAL CASE THAT QUEUE WAS EMPTY
        {
            f = r = ptr;    //INITIALIZE BOTH FRONT AND REAR
            f->next = r->next = NULL;       //INITIALIZE BOTH FRONT AND REAR
        }
        else
        {
            r->next = ptr;
            r = ptr;                //UPDATE REAR/TRAVERSE REAR
            r->next = NULL;     //ASSIGNING THE ADDRESS OF REAR POINTS TO 'NULL'
        }
        printf("\nENQUEUE FUNCTION IS SUCCESSFUL...!!!\n");
    }
    
}
void dequeue()      //FUNCTION DEFINITION
{
    struct node *ptr;       //CREATING NEW NODE 'ptr'
    if (f == NULL)      //CONDITION FOR CHECKING WHETHER THERE IS ANY ELEMENT IN THE QUEUE
    {
        printf("\nQUEUE IS EMPTY...!!!\n");
    }
    else
    {
        ptr = f;        //BACKUP THE FRONT NODE
        f = f->next;    //MAKE THE FRONT NODE POINTS TO THE NEXT NODE LOGICALLY REMOVING THE NODE
        printf("\nDELETED ELEMENT IS :: %d\n", ptr->data);
        free(ptr);      //FREE THE MEMORY OF DEQUEUED ELEMENT TO AVOIDING THE MEMORY LEAK CONCEPT
    }

}
void display()      //FUNCTION DEFINITION
{       //PRINTING THE LINKED LIST
    struct node *ptr;   //CREATING A NEW NODE 'ptr'
    ptr = f;        //BACKUP THE FRONT NODE/TRAVERSE THE LIST
    if (f == NULL)      //CONDITION FOR CHECKING WHETHER THERE IS ANY ELEMENT IN THE QUEUE
    {
        printf("\nQUEUE IS EMPTY...!!!\n");
    }
    else
    {       //ITERATING THE LINKED LIST AND PRINT THE DATA
        printf("\nPRINTING VALUES...\n");
        while (ptr != NULL)     //WHILE LOOP
        {
            printf("\n%d\n",ptr->data);     //ITERATING THE LINKED LIST AND PRINT THE DATA
            ptr = ptr->next;
        }
        
    }
    
}
