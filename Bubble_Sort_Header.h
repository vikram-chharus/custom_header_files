#include "Swap.h"
void bubbleSort(int array[],int base_index,int last_index)
{
	for(int i=base_index;i<=last_index;i++)
	{
		for(int j=i+1;j<=last_index;j++)
		{
			if(array[i] > array[j] )
			{
				swap(&array[i],&array[j]);
			}
		}
	}
}
