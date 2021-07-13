/*Author: Ujjwal Sharma
Date: 22th of June,2021
Purpose: program to evaluate the expression*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_OPERATOR 20
#define MAX_OPERAND 20
int operator_top = -1;
int operand_top = -1;
int top_priority = 0;
float operand_stack[20];
char operator_stack[10];
void push_operator(char);
void push_operand(int);
char pop_operator();
float pop_operand();
void view_operator();
void view_operand();
int priority(char);
float result();
int main()
{
    int num;
    char exp[20],digit;
    printf("\nEnter the Expression :: ");
    scanf("%[^\n]s", &exp);
    printf("\nExpression = %s\n",exp);
    for (int i=0;exp[i] != '\0';i++)
    {
        digit = exp[i];
        if (isdigit(digit))
        {
            num = digit - 48;
            push_operand((float)num);
        }
        else
        {
            push_operator(digit);
        }
    }
    view_operand();
    view_operator();
    printf("\nResultant Expression :: %.2f\n", result());
}
void push_operand(int operand)
{
    if (operand_top == MAX_OPERAND - 1)
    {
        printf("\n STACK OVERFLOW.....!!!!!\n");
    }
    else
    {
        operand_top++;
        operand_stack[operand_top] = operand;
    }
}
void push_operator(char digit)
{
    int n1, n2, n3, priority_op;
    if (operator_top == MAX_OPERATOR - 1)
    {
        printf("\n STACK OVERFLOW.....!!!!!");
    }
    else if(operator_top == -1)
    {
        top_priority = priority(digit);
        operator_top++;
        operator_stack[operator_top] = digit;
    }
    else
    {
        priority_op = priority(digit);
        if(priority_op > top_priority)
        {
            operator_top++;
            operator_stack[operator_top] = digit;
        }
        else
        {
            char ch;
            ch = pop_operator();
            n1 = pop_operand();
            n2 = pop_operand();
            switch(ch)
            {
                case '+':
                    n3 = n1 + n2;
                    break;
                case '-':
                    n3 = n1 - n2;
                    break;
                case '*':
                    n3 = n1 * n2;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                default :
                    printf("\nINVALID OPERATOR...!!!");
                    exit(0);
                    break;
            }
            push_operand(n3);
            operator_top++;
            operator_stack[operator_top] = digit;
        }
    }
}
int priority(char digit)
{
    if(digit == '+' || digit == '-')
    {
        return 1;
    }
    else if(digit == '*' || digit == '/')
    {
        return 2;
    }
    return -1;
}
float pop_operand()
{
	float operand;
	if(operand_top == -1)
	{
		printf("\nTHERE IS NO OPERAND IN THE STACK...!!!\n");
		exit(0);
	}
	else
	{
		operand=operand_stack[operand_top];
		operand_top--;
	}
	return operand;
}
char pop_operator()
{
	char operator;
	if(operator_top == -1)
	{
		printf("\nTHERE IS NO OPERTOR IN THE STACK....!!!!!\n");
		exit(0);
	}
	else
	{
		operator=operator_stack[operator_top];
		operator_top--;
	}
	return operator;

}
void view_operand()
{
    if (operand_top == -1)
    {
        printf("\nNO OPERAND IN THE STACK...!!!\n");
    }
    else
    {
        printf("\nOPERAND IN STACK ARE :: \n");
        for (int i = operand_top; i > -1; i--)
        {
            printf("%.2f\t", operand_stack[i]);
        }
        printf("\n");
    }
}
void view_operator()
{
    if (operator_top == -1)
    {
        printf("\nNO OPERATOR IN THE STACK...!!!\n");
    }
    else
    {
        printf("\nOPERATOR IN STACK ARE :: \n");
        for (int i = operator_top; i > -1; i--)
        {
            printf("%c\t", operator_stack[i]);
        }
        printf("\n");
    }
}
float result()
{
    float n1,n2,n3;
    if (operand_top == -1)
    {
        printf("\nSTACK IS EMPTY...!!!\n");
        exit(0);
    }
    else
    {
        while(operator_top > -1)
        {
            char ch;
            ch = pop_operator();
            n1 = pop_operand();
            n2 = pop_operand();
            switch(ch)
            {
                case '+':
                    n3 = n1 + n2;
                    break;
                case '-':
                    n3 = n1 - n2;
                    break;
                case '*':
                    n3 = n1 * n2;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                default :
                    printf("\nINVALID OPERATOR...!!!");
                    exit(0);
                    break;
            }
            push_operand(n3);
        }operator_top++;
    }
    return operand_stack[0];
}