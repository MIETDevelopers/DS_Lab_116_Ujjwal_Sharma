#include <stdio.h>
int main()
{  int num;
    int i,  keynum, found = 0;
    scanf("%d", &num);
    printf("Enter the number of elements =%d\n", num);
    int array[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
        printf("Enter the elements one by one = %d\n", array[i]);
    }
    scanf("%d", &keynum);
    printf("Enter the element to be searched = %d\n", keynum);
    for (i = 0; i < num ; i++)
    {
        if (keynum == array[i] )
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
        printf("Element is present in the array at index = %d",i);
    else
        printf("ELEMENT IS NOT PRESENT IN AN ARRAY");
    return 0;
}