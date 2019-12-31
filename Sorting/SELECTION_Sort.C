			/*Write a program to perform Selection Sort.*/

#include<stdio.h>
#include<conio.h>

void main()
{
	int i, n, arr[1000] ;
	void Selection(int, int[]) ;
	clrscr() ;

	printf("\n* Selection Sort *\n") ;

	printf("\n\nEnter size of list:\t") ;
	scanf("%d", &n)  ;

	printf("\nEnter elements in the list:\n") ;
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]) ;

	Selection(n, arr) ;

	getch() ;
}

void Selection(int n,  int arr[])
{
	int i, j, temp, min =0 ;

	for(i=0; i<n; i++)
	{
		min = i ;

		for(j = i+1; j<n; j++)
		{
			if(arr[min] > arr[j])
				min = j ;
		}

		if(i!= min)
		{
			temp = arr[i] ;
			arr[i] = arr[min] ;
			arr[min] = temp ;
		}
	}

	printf("\nThe Sorted List is:\t") ;
		for(i=0; i<n; i++)
			printf("%d\t", arr[i]) ;
}
