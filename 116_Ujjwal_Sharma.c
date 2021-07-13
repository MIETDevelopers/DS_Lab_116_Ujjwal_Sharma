/*AUTHOR NAME :: UJJWAL SHARMA
DATE :: 25TH OF MAY, 2021
PURPOSE :: TO STORE DATA IN STRUCTURE*/

#include<stdio.h>   //PRE-PROCESSIVE DIRECTIVE TO INCLUDE STANDARD INPUT OUTPUT FNCTION HEADER FILE
#include <stdlib.h> //PRE-PROCESSIVE DIRECTIVE TO INCLUDE STANDARD LIBRARY FUNCTIION HEADER FILE
struct Student  //DECLARING struct DATATYPE 
{
    char name[50];  //DECLARING VARIABLE name OF DATA TYPE char
    int rollno;     //DECLARING VARIABLE rollno OF DATA TYPE int
    float marks;    //DECLARING VARIABLE marks OF DATA TYPE float
};
int main()      //STARTING OF MAIN PROGRAM
{
    int i;
    struct Student d[10];
    printf("\n Enter name, roll no. and marks Below ::     ");
    for(i=0; i<3; i++)
    {
        printf("\nEnter %d record :: \n",i+1);
        scanf("%s",d[i].name);
        printf("\nEnter Name :: %s", d[i].name);
        scanf("%d",&d[i].rollno);
        printf("\nEnter RollNo. :: %d", d[i].rollno);
        scanf("%f",&d[i].marks);
        printf("\nEnter Marks :: %.2f\n", d[i].marks);
    }
    printf("\n\tName\t\tRollNo\t\tMarks\n");
    for(i=0; i<3; i++)
        printf("\t%s\t\t%d\t\t%.1f\n", d[i].name, d[i].rollno, d[i].marks);
    return 0;   
}