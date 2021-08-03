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
void insert_random();
void delete_beginning();
void delete_last();
void delete_random();
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
                printf("\n1.INSERTION AT BEGINNING\n2.INSERATION AT LAST\n3.INSERTING AT SPECIFIC POSITION\n");
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
                    case 3:
                        insert_random();
                        break;
                    default:
                        printf("\nPLEASE ENTER A VALID CHOICE...!!!\n");
                        break;
                }
                break;
            case 2:
                printf("\n1.DELETE AT BEGINNING\n2.DELETE AT LAST\n3.DELETE AT SPECIFIC POSITION\n");
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
                    case 3:
                        delete_random();
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
    UJJWAL *ptr;
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
        ptr->next = head;
        head = ptr;
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
        ptr->next = NULL;
        if(head == NULL)
        {
            head = ptr;
            printf("\nNODE INSERTED...!!!\n");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            printf("\nNODE INSERTED...!!!\n");
        }
    }
}
void insert_random()
{
    int i, loc, item;
    UJJWAL *ptr, *temp;
    ptr = (UJJWAL * ) malloc(sizeof(UJJWAL));
    if (ptr == NULL)
    {
        printf("\nNO SPACE IN THE RAM...!!!\n");
    }
    else
    {
        printf("\nENTER A ELEMENT :: ");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nENTER A LOCATING AFTER WHICH YOU WANT TO INSERT A NUMBER :: ");
        scanf("\n%d",&loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nCAN'T INSERT THE NUMBER\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNODE INSERTED...!!!\n");
    }
}
void delete_beginning()
{
    UJJWAL *ptr;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY...!!!\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNODE DELETED FROM BEGINNING...!!!\n");
    }
    
}
void delete_last()
{
    UJJWAL *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY...!!!\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nONLY ONE NODE IN LIST IS DELETED...!!!\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nNODE IS DELETED FROM THE LAST...!!!\n");
        
    }
    
}
void delete_random()
{
    UJJWAL *ptr, *ptr1;
    int i, loc;
    printf("\nENTER A LOCATION AFTER WHICH YOU WANT TO PERFORM DELETION :: ");
    scanf("%d",&loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nCAN'T DELETE THE ELEMENT...!!!\n");
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDELETED NODE IS :: %d\n", loc+1);
}
void search()
{
    UJJWAL *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEMPTY LIST...!!!\n");
    }
    else
    {
        printf("\nENTER ITEM WHICH YOU WANT TO SEARCH :: ");
        scanf("%d",&item);
        while (ptr != NULL)
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
        if (flag == 1)
        {
            printf("\nITEM IS NOT FOUND...!!!\n");
        }
    }
    
}
void display()
{
    UJJWAL *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNO ELEMENTS WHICH TO BE PRINT...!!!\n");
    }
    else
    {
        printf("\nPRINTING VALUES...\n");
        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
        
    }
    
}