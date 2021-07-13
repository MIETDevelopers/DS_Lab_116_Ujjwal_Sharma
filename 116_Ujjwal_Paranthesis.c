/*Author: Ujjwal Sharma
Date:20th of June,2021
Purpose: Program to check whether an expression is correctly perenthesis*/
#include <stdio.h>
#include <stdlib.h>
 
int top = -1;
char stack[50];
 
void push(char);
void pop();
void topus();
 
void main(){
	char arr[50];
	printf("Enter an expression: ");
	gets(arr);
	for(int i=0; arr[i]!='\0'; i++){
		if (arr[i]=='(')
			push(arr[i]);
		else if (arr[i] == ')')
			pop();
	}
	topus();
}
void push(char a){
	stack[top] = a;
	top++;
}
void pop(){
	if (top == -1){
		printf("Incorrectly parenthesized!\n");
		exit(0);
	}	
	else		
		top--;
}
void topus()
{
	if (top == -1)
		printf("Correctly parenthesized!");
	else
		printf("Incorrectly parenthesized!");
}