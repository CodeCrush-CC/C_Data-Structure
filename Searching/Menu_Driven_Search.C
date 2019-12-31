#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main()
{
	int i, n, x, arr[1000] ;
	int ch ;
	void Lsearch(int, int[], int) ;
	void Bsearch(int, int[], int) ;

	clrscr() ;

	printf("\nEnter size of list:\t") ;
	scanf("%d", &n) ;

	while(1)
	{
		printf("\n\nMenu:") ;
		printf("\n\n1.Linear Search") ;
		printf("\n2.Binary Search") ;
		printf("\n3.Exit") ;

		printf("\n\nEnter your choice:\t")  ;
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1:

			printf("\nEnter values into list:\n") ;
				for(i=1; i<=n; i++)
					scanf("%d", &arr[i]) ;

			printf("\nEnter element you want to search:\t") ;
			scanf("%d", &x) ;

			Lsearch(n, arr, x) ;

			break ;

			case 2:

			printf("\n* List should be sorted, Otherwise results are unpredictable *\n")  ;
			printf("\nEnter values to list:\n") ;
				for(i=1; i<=n ;i++)
					scanf("%d", &arr[i]) ;

			printf("\nEnter element you want to search:\t") ;
			scanf("%d", &x) ;

			Bsearch(n, arr, x);

			break ;

			case 3: exit(1) ;
			break ;

			default: printf("\nWrong choice!") ;
		}
	}
}

void Lsearch(int n, int arr[], int x)
{
	int i, pos = -1 ;

	for(i=1; i<=n; i++)
	{
		if(x == arr[i])
			pos = i ;
	}
	if(pos == -1)
		printf("\nElemnt not found!") ;
	else
		printf("\n\nElement: %d is present at position: %d", x, pos) ;
}

void Bsearch(int n, int arr[], int x)
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
