#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stack[SIZE], top = -1;
void push();
void pop();
void display();
void main()
{
	int choice;
	while(1){
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice =\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nPlease Enter a Valid Choice...!!!");
		}
	}
}
void push()
{
    int val;
	if(top == SIZE-1)
    {
		printf("\nSTACK IS OVERFLOW...!!!\nINSERTION IS NOT POSSIBLE...!!!");
    }
	else
	{
	    printf("Enter value to be inserted =\n");
	    scanf("%d",&val);
		top = top+1;
	    stack[top] = val;
	}
}
void pop()
{
	if(top == -1)
		printf("\nSTACK IS UNDERFLOW...!!!\nDELETION IS NOT POSSIBLE...!!!");
	else{
		printf("\nDeleted Element is = %d", stack[top]);
		top = top-1;
	}
}
void display()
{
	if(top == -1)
	{
		printf("\nSTACK IS EMPTY...!!!\n");
	}
	else
	{
    int i;
	printf("\nStack Element are = \n");
    for(i=top;i>=0;--i)
        printf("%d\n", stack[i]);
	}
}
