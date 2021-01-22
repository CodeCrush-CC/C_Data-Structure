			/*Write a program to perform Insertion Sort.*/

#include<stdio.h>
#include<conio.h>

void main()
{
	int i, n, arr[1000] ;
	void Insertion(int, int[]) ;
	clrscr() ;

	printf("\n* Insertion Sort *\n") ;

	printf("\n\nEnter size of list:\t") ;
	scanf("%d", &n)  ;

	printf("\nEnter elements in the list:\n") ;
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]) ;

	Insertion(n, arr) ;

	getch() ;
}

void Insertion(int n, int arr[])
{
	int i, j, temp ;

	for(i=1; i<n; i++)
	{
		temp = arr[i] ;

		j = i - 1 ;

		while(temp < arr[j] && (j>=0))
		{
			arr[j+1] = arr[j] ;
			j-- ;
		}
		arr[j+1] = temp ;
	}

	printf("\nThe Sorted List is:\t") ;
		for(i=0; i<n; i++)
			printf("%d\t", arr[i]) ;
}
