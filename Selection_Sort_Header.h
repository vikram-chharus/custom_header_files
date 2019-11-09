#include "Swap.h"
void selectionSort(int array[],int base_index,int last_index)
{
	for(int i=base_index;i<=last_index;i++)
	{
		int smallestNumberIndex=i;
		for(int j=i+1;j<=last_index;j++)
		{
			if( array[j] < array[smallestNumberIndex] )
			{
				smallestNumberIndex=j;
			}
		}
		swap(&array[i],&array[smallestNumberIndex]);
	}
}
