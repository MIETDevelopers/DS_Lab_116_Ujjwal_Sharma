/**
**********************************************************************************************************************************************************************************************************************************
* @file:	LAB_ASSIGNMENT_2.c
* @author:	UJJWAL SHARMA
* @date:	2021-09-11 20:58:04 Saturday
* @brief:   A C PROGRAM TO COMPARE THE RUNNING TIMES (IN MILLISECONDS) OF BUBBLE SORT ANS MERGE SORT  FOR THE FOLLOWING ARRAY :: {1,3,42,2,41,66,66,33,98,0}.
**********************************************************************************************************************************************************************************************************************************
**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//USE FOR CLOCK FUNCTION.
#include<unistd.h>//USE FOR SLEEP FUNCTION.

int max = 10;//SPECIFYING THE MAXIMUM SIZE.
int Array0[10] = {1,3,42,2,41,66,66,33,98,0};//PRE-DEFINED ARRAY WHICH IS TO BE SORTED.
clock_t t; //CLOCK PER SECOND.


void printArray();      //FUNCTION DECLARATION
void BubbleSort();      //FUNCTION DECLARATION 
void MergeSort();       //FUNCTION DECLARATION
void merge();

//STARTING OF MAIN PROGRAM
int main()
{
    int choice;
    do{         //DO-WHILE FUNCTION
        printf("\nARRAY TO BE SORTED :: {1,3,42,2,41,66,66,33,98,0}");
        printf("\n---\n1. BUBBLE SORT\n2. MERGE SORT\n3. EXIT");
        printf("\nENTER YOUR CHOICE :: ");
        scanf("%d", &choice);
        switch(choice)      //SWITCH STATEMENT
        {
            case 1:
                t = clock();    //CLOCK FUNCTION FROM "time.h" LIBRARY
                BubbleSort(Array0,max);     //FUNCTION CALLING
                printf("\nTHE SORTED ARRAY IS :: ");
                printArray(Array0, max);        //FUNCTION CAALLING
                sleep(1);       //SLEEP FUNCTION FROM "unistd.h" LIBRARY
                t = clock() - t;
                double BubbleSortTime = ((double)t)/CLOCKS_PER_SEC; //IN SECONDS
                printf("\nTIME TAKEN BY BUBBLE SORT :: %f ms\n", BubbleSortTime*1000);
                fflush(stdin);
                break;
            case 2:
                t = clock();
                MergeSort(Array0, 0, ( max- 1));        //FUNCTION CALLING
                printf("THE SORTED ARRAY IS :: ");
                printArray(Array0 , max);       //FUNCTION CALLING
                sleep(1);       //SLEEP FUNCTION FROM "unistd.h" LIBRARY
                t = clock() - t;
                double MergeSortTime = ((double)t) / CLOCKS_PER_SEC;
                printf("\nTIME TAKEN FOR MERGE SORT :: %f ms\n", MergeSortTime*1000);
                fflush(stdin);
                break;
            case 3:
                exit(0);        //EXIT FUNCTION
                break;
        }
    }while(choice!=3);      //WHILE FUNCTION
    return 0;
}

void BubbleSort(int a[], int size)      //FUNCTION DEFINITION
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void merge(int a[], int left, int m, int right)     //FUNCTION DEFINITION
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    int L[n1], R[n2];//CREATE TEMPORARY ARRAY

    //COPYING DATA FROM TEMP L[] and R[].
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    //MERGE THE TEMP ARRAYS BACK INTO a[left..right].
    i = 0;    // INITIAL INDEX OF  FIRST SUBARRAY.
    j = 0;    // INITIAL INDEX OF  SECOND SUBARRAY.
    k = left; // INITIAL INDEX OF  MERGED SUBARRAY.
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
        else
            {
                a[k] = R[j];
                j++;
            }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
        //COPY THE REMAINING ELEMENT L[], IF THERE ARE ANY.
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
        //COPY THE REMAINING ELEMENT OF  R[], IF THERE ARE ANY.
    }
}

void MergeSort(int a[], int left, int right)        //FUNCTION DEFINITION
{
    //LEFT IS FOR LEFT INDEX AND RIGHT IS FOR RIGHT INDEX OF THE SUB-ARRAY OF a TO BE SORTED.
    if (left < right)
    {
        int m = left + (right - left) / 2;
        //SAME AS (left+right)/2,BUT AVOIDS OVERFLOW FOR LARGE LEFT AND HALVES.

        MergeSort(a, left, m);
        MergeSort(a, m + 1, right);
        merge(a, left, m, right);
        //SORT FIRST AND SECOND HALVES 
    }
}

void printArray(int *arr, int size)     //FUNCTION DEFINITION
{
    for (int i = 0; i < size; i++)
    {
        //THIS LOOP WILL ITERATE THROUGH THE WHOLE ARRAY AND WILL PRINT EACH ELEMENT.
        printf(" %d,", arr[i]);
    }
    printf("\n");
}



//MERGE SORT IS CONSIDERED TO BE ONE OF THE FASTEST SORTINF ALGORITHMS, IT IS A BIT MORE COMPLEX THAN BUBBLE SORT BUT IT IS MORE EFFICIENT.
//THE IDEA OF MERDE SORT IS TO DIVIDE THE DATA-SET INTO SMALLER DATA-SETS, SORT THOSE SMALLER DATA-SETS AND THEN JOIN THEM (MERGE THEM ) TOGETHER.