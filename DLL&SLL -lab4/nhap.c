#include <stdio.h>

void nhap(int *arr , int size )
{
	for(int i=0 ; i< size ; i++)
	{
		printf("Phần tử thứ %d: ", i + 1) ;
		scanf("%d", &arr[i]);
	}
}