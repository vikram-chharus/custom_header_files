#include "Swap.h"
int partition(int array[],int base_index,int last_index)
{
	int pivot=array[last_index];//taking last element of the given array as pivot or center
	int swapHere=base_index;//to check where we have to swap the element and how many elements we have swaped 
	for(int i=base_index;i<last_index;i++)
	{
		if( array[i] < pivot)
		{
			swap(&array[swapHere++],&array[i]);
		}
	}
	swap(&array[swapHere],&array[last_index]);
	return swapHere;
}
void quickSort(int array[],int base_index,int last_index)
{
	if( base_index < last_index )
	{
		int elementPlacedAtRightIndex=partition(array,base_index,last_index);
		//sort the left sub array
		quickSort(array,base_index,elementPlacedAtRightIndex-1);
		//sort the right sub array
		quickSort(array,elementPlacedAtRightIndex+1,last_index);
	}
}
