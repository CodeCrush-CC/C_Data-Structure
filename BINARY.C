#include<stdio.h>
#include<conio.h>

void binary(int, int[], int) ;

void main()
{
	int i, n, x, arr[1000] ;
	clrscr() ;

	printf("\n\n* Binary Search *\n\n") ;
	printf("\nEnter size of list:\t") ;
	scanf("%d", &n) ;

	printf("\n* List should be sorted, Otherwise results are unpredictable *\n")  ;
	printf("\nEnter values to list:\n") ;
		for(i=1; i<=n ;i++)
			scanf("%d", &arr[i]) ;

	printf("\nEnter element you want to search:\t") ;
	scanf("%d", &x) ;

	binary(n, arr, x);

	getch() ;
}
void binary(int n, int arr[], int x)
{
	int first, last, mid, pos = -1 ;

	first = 0 ;
	last = n ;  //cz array indices start from '1'

	while(first <= last && pos == -1)
	{
		mid  = (first + last) /2 ;

		if(x == arr[mid])
			pos = mid ;

		else if(x > arr[mid])
		first = mid + 1 ;

		else if(x < arr[mid])
		last = mid - 1 ;
	}

	if(pos == -1)
		printf("\nElement not found") ;
	else
		printf("\nElement %d is found at position: %d", x, pos) ;
}