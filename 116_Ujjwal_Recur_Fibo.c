/*NAME:UJJWAL SHARMA
DATE: 20TH OF JUNE, 2021
PURPOSE:TO DISPLAY THE FIBONACCI SERIES USING RECURSION*/
#include<stdio.h>  //PREPROSESSIVE DIRECTIVE TO INCLUDE STANDARD INPUT OUTPUT HEADER FILE
void printFibonacci(int n){    //FUNCTION DECLARATION
    static int n1=0,n2=1,n3;   //DECLARING STATIC VARIABLE
    if(n>0){
         n3 = n1 + n2;
         n1 = n2;
         n2 = n3;
         printf("%d ",n3);
         printFibonacci(n-1);
    }
}
int main(){ //STARTING OF MAIN PROGRAM
    int n;      //DECLARATION OF VARIABLES
    printf("Enter the number of elements: \n");    //PRINT USER INPUT
    scanf("%d",&n);     //READ USER INPUT
    printf("Fibonacci Series: ");   //PRINT OUTPUT OF THE PROGRAM
    printf("%d %d ",0,1);   //PRINTING START TWO NUMBER OF THE SERIES
    printFibonacci(n-2);    //FUNCTION CALLING
  return 0;     //RETURN STATEMENT
 }