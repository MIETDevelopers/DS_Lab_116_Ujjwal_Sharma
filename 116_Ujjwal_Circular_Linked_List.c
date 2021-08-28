/**
**********************************************************************************************************************************************************************************************************************************
* @file:	116_Ujjwal_Circular_Linked_List.c
* @author:	UJJWAL SHARMA
* @date:	14-08-2021 21:21:46 Saturday
* @brief:	PROGRAM TO IMPLEMENTATION OF CIRCULAR LINKED LIST AND DEVELOP THE FUNCTION TO PERFORM INSERTION, DELETION, SEARCHING AND DISPLAY OPERATION
**********************************************************************************************************************************************************************************************************************************
**/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node UJJWAL;
UJJWAL *head = NULL;
void insert_beginning();
void insert_last();
void delete_beginning();
void delete_last();
void search();
void display();
void main()
{
    int choice, ch1, ch2;
    while (choice != 5)
    {
        printf("\n1. INSERTION OF NUMBER\n2. DELETION OF A NUMBER\n3. SEARCHING A NUMBER\n4. DISPLAYING NUMBER\n5. EXIT\n");
        printf("\nENTER YOUR CHOICE :: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\n1.INSERTION AT BEGINNING\n2.INSERATION AT LAST\n");
                printf("\nENTER YOUR CHOICE :: ");
                scanf("%d",&ch1);
                switch (ch1)
                {
                    case 1:
                        insert_beginning();
                        break;
                    case 2:
                        insert_last();
                        break;
                    default:
                        printf("\nPLEASE ENTER A VALID CHOICE...!!!\n");
                        break;
                }
                break;
            case 2:
                printf("\n1.DELETE AT BEGINNING\n2.DELETE AT LAST\n");
                printf("\nENTER YOUR CHOICE :: ");
                scanf("%d",&ch2);
                switch (ch2)
                {
                    case 1:
                        delete_beginning();
                        break;
                    case 2:
                        delete_last();
                        break;
                    default:
                        printf("\nPLEASE ENTER A VALID CHOICE...!!!\n");
                        break;
                }
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nEXITING...!!!\n");
                exit(0);
                break;
            default:
                printf("\nENTER A VALID CHOICE...!!!\n");
        }
    }
}
void insert_beginning()
{
    UJJWAL *ptr, *temp;
    int element;
    ptr = (UJJWAL *) malloc(sizeof(UJJWAL));
    if (ptr == NULL)
    {
        printf("\nNO SPACE IN THE RAM...!!!\n");
    }
    else
    {
        printf("\nENTER A VALUE :: ");
        scanf("%d", &element);
        ptr->data = element;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNODE INSERTED...!!!\n");
    }
    
}
void insert_last()
{
    UJJWAL *ptr,*temp;
    int element;
    ptr = (UJJWAL *) malloc(sizeof(UJJWAL));
    if(ptr == NULL)
    {
        printf("\nNO SPACE IN THE RAM...!!!\n");
    }
    else
    {
        printf("\nENTER A VALUE :: ");
        scanf("%d",&element);
        ptr->data = element;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
            printf("\nNODE INSERTED...!!!\n");
        }
        else
        {
            temp = head;
            while (temp -> next != head)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = head;
            printf("\nNODE INSERTED...!!!\n");
        }
    }
}
void delete_beginning()
{
    UJJWAL *ptr;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY...!!!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNODE IS SUCCESSFULLY DELETED...!!!\n");
    }
    else
    {
        ptr = head;
        while (ptr->next = head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNODE DELETED FROM BEGINNING...!!!\n");
    }
    
}
void delete_last()
{
    UJJWAL *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY...!!!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nONLY ONE NODE IN LIST IS DELETED...!!!\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nNODE IS DELETED FROM THE LAST...!!!\n");
        
    }
    
}
void search()
{
    UJJWAL *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEMPTY LIST...!!!\n");
    }
    else
    {
        printf("\nENTER ITEM WHICH YOU WANT TO SEARCH :: ");
        scanf("%d",&item);
        if (head->data == item)
        {
            printf("\nITEM FOUND AT LOCATION :: %d\n", i+1);
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("\nITEM FOUND AT LOCATION :: %d\n", i+1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;

                
            }
            
        }
        if (flag != 0)
        {
            printf("\nITEM IS NOT FOUND...!!!\n");
        }
    }
    
}
void display()
{
    UJJWAL *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nNO ELEMENTS WHICH TO BE PRINT...!!!\n");
    }
    else
    {
        printf("\nPRINTING VALUES...\n");
        while (ptr->next != head)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("\n%d\n", ptr->data);
    }
    
}