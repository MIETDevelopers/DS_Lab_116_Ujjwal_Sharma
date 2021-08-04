/**
**********************************************************************************************************************************************************************************************************************************
* @file:	116_Ujjwal_Stack_Linked_List.c
* @author:	UJJWAL SHARMA
* @date:	04-08-2021 19:22:29 Wednesday
* @brief:	PROGRAM TO IMPLEMENT THE STACK AND DEVELOP FUNCTION TO PERFORM PUSH, POP AND DISPLAY USING LINKED LIST
**********************************************************************************************************************************************************************************************************************************
**/
#include <stdio.h>  //PRE-PROCESSOR DIRECTIVE TO INCLUDE STANDARD INPUT OUTPUT FUNCTION HEADER FILE
#include <stdlib.h> //PRE-PROCESSOR DIRECTIVE TO INCLUDE STANDARD LIBRARY FUNCTION HEADER FILE
struct node     //CREATING STRUCTURE OF NODE DATA TYPE
{
    int data;           //DATA MEMBERS OF THE STRUCTURE DATA TYPE NODE
    struct node *next;
};
struct node *head;      //CREATING HEAD NODE
void push();        //FUNCTION PROTOTYPE
void pop();         //FUNCTION PROTOTYPE
void display();     //FUNCTION PROTOTYPE
void main()     //STARTING OF MAIN PROGRAM
{
    int ch;     //DECLARING VARIABLE 'ch' OF 'int' DATA TYPE
    while (ch != 4)     //WHILE LOOP
    {
        printf("\n1.PUSH THE NODE IN THE STACK\n2.POP THE NODE FROM THE STACK\n3.DISPLAY THE ELEMENTS OF THE STACK\n4.EXIT\n");
        printf("\nENTER YOUR CHOICE :: ");      //PRINT INPUT FROM USER
        scanf("%d", &ch);       //READ INPUT FROM USER
        switch (ch)     //SWITCH STATEMENT
        {
            case 1:     //CASE 1
                push();     //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 2:     //CASE 2
                pop();      //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 3:     //CASE 3
                display();  //FUNCTION CALLING
                break;      //BREAK STATEMENT
            case 4:     //CASE 4
                printf("\nEXITING...!!!\n");
                exit(0);    //EXIT WITHOUT TERMINATE THE PROGRAM
                break;      //BREAK STATEMENT
            default:    //DEFAULT STATEMENT
                printf("\nENTER A VALID CHOICE...!!!\n");
                break;      //BREAK STATEMENT
        }
    }   
}       //END OF MAIN PROGRAM
void push()     //FUNCTION DEFINITION
{
    struct node *ptr;       //CREATING NEW NODE 'ptr'
    int ele;    //DECLARING VARIABLE 'ele' OF 'int' DATA TYPE
    ptr = (struct node *) malloc(sizeof(struct node));  // MEMORY ALLOCATING OF NEW NODE 'ptr'
    if (ptr == NULL)    //CONDITION  OF CHECKING WHETHER THERE IS ANY ELEMENT IN THE STACK
    {
        printf("\nNO ELEMENT IN THE STACK...!!!\n");
    }
    else    //ELSE STATEMENT
    {
        printf("\nENTER THE VALUE :: ");
        scanf("%d", &ele);
        if (head == NULL)   
        {
            ptr->data = ele;    //MAKE THE 'ptr' POINTS TO 'ele' ASSIGNING 'data' VALUE
            ptr->next = NULL;   //ASSIGNING THE ADDRESS OF NEXT NODE TO 'NULL'
            head = ptr;         //MAKES THE NEW NODE AS HEAD NODE SO THAT HEAD WILL ALWAYS POINTS THE LAST INSERTED DATA
        }
        else
        {
            ptr->data = ele;    //MAKE THE 'ptr' POINTS TO 'ele' ASSIGNING 'data' VALUE
            ptr->next = head;   //ASSIGNING THE ADDRESS OF NEXT NODE TO 'head'
            head = ptr;         //MAKES THE NEW NODE AS HEAD NODE SO THAT HEAD WILL ALWAYS POINTS THE LAST INSERTED DATA
        }
        printf("\nNODE PUSHED...!!!\n");

    }
    
}
void pop()      //FUNCTION DEFINITION
{
    struct node *temp;  //CREATING NEW NODE 'temp' WHICH IS USED FREE THE HEAD NODE
    if (head == NULL)   //CONDITION FOR CHECKING WHETHER THERE IS ANY ELEMENT IN THE STACK
    {
        printf("\nNO ELEMENT IN THE STCAK\n");
    }
    else
    {
        printf("\nPOPPED ELEMENT IS :: %d\n", head->data);
        temp = head;    //BACKUP THE HEAD NODE
        head = head->next;  //MAKE THE HEAD NODE POINTS TO NEXT NODE LOGICALLY REMOVING THE NODE
        free(temp);     //FREE THE POPPED ELEMENT'S MEMORY TO AVOIDING MEMORY LEAK CONCEPT
        printf("\nNODE POPPED...!!!\n");
    }
    
}
void display()      //FUNCTION DEFINITION
{       //PRINT THE LINKED LIST
    struct node *temp;
    temp = head;        //BACK UP THE HEAD NODE 
    if (temp == NULL)   //CONDITION FOR CHECKING WHETHER THE LIST IS EMPTY
    {
        printf("\nSTACK IS EMPTY...!!!\n");
    }
    else
    {
        printf("\nPRINTING THE ELEMENTS...\n");
        while (temp != NULL)        //ITERATE THE LINKED LIST AND PRINT THE DATA
        {
            printf("\n%d\n",temp->data);
            temp = temp->next;
        }

    }
    
}