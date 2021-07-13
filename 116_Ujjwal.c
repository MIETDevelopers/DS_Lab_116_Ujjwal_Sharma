#include <stdio.h> 
int search(int *a);
int insert(int*arr2);
int delelement(int*arr3);
int main()  
{
    int arr1[50]; 
    int ch,b,c;
    printf("Select any option from below\n");
	printf("1. Search an element from the Array\n");
    printf("2. Insert an element in an Array\n");
    printf("3.Delete an element from the Array\n");
	printf("\nEnter your choice : \n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		printf("\nYou choose to Search an element from the Array\n");
    		search(arr1);
    		break;
		case 2:
			printf("\nYou choose to Insert an element from the Array\n");	
			insert(arr1);
			break;
		case 3:
			printf("\nYou choose to Delete an element from the Array\n");
			delelement(arr1);
			break;	
		default :
			printf("\nPlease Enter a Valid Number....!!!!\n");
		return 0;	
	}
}
	int search(int a[])
	{
		int size,i,ele,found;
		printf("\nEnter the size of the array : ");
		scanf("%d",&size);
		for(i=0;i<size;i++)
		{
			printf("\nEnter %d elements : ");
			scanf("%d",&a[i]);
		}
		printf("\nElements of Array are : ");
		for(i=0;i<size;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\nEnter the element that you want to search : ");
		scanf("%d",&ele);
		
		for(i=0;i<size;i++)
		{
			if(a[i]==ele)
			{
				found=1;
				break;		
			}
		}
			if(found==1)
			{
				printf("\n%d is found at %d position in the array",ele,i+1);
			}
			else
			printf("\n%d is not found in the array",ele);	
			return 0;
	}
	
	int insert(int arr2[])
	{
		int n,s,j;
		printf("\nEnter the size of the Array :" );
		scanf("%d",&s);
			for(j=0;j<s;j++)
		{
			scanf("%d",&arr2[j]);
		}
		printf("\nArray before insertion of element : ");
			for(j=0;j<s;j++)
		{
			printf("%d ",arr2[j]);
		}
		printf("\nEnter the number that you want to insert in the Array at the End : ");
		scanf("%d",&n);
		s=s+1;
		arr2[s-1]=n;
		printf("\nArray after insertion of %d is : ",n);
		for(j=0;j<s;j++)
		{
			printf("%d ",arr2[j]);
		}
	}
	
	int delelement(int arr3[])
	{
		int position, c, n;

   scanf("%d", &n);
   printf("\nEnter number of elements in array = %d\n", n);


   for (c = 0; c < n; c++)
   {
      scanf("%d", &arr3[c]);
      printf("\nEnter %d elements = %d\n", n, arr3[c]);
   }

   scanf("%d", &position);
   printf("\nEnter the location where you wish to delete element = %d\n", position);


 
   if (position >= n+1)
      printf("\nDeletion not possible.\n");
   else
   {
      for (c = position - 1; c < n - 1; c++)
         arr3[c] = arr3[c+1];

      printf("\nResultant array:\n");

      for (c = 0; c < n - 1; c++)
         printf("%d\n", arr3[c]);
   }

   return 0;
}