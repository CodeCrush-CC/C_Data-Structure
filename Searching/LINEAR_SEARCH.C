					/*Write a program to perform Linear Search*/

#include<stdio.h>
#include<conio.h>

void linear(int, int[], int) ;

void main()
{
	int i, n, x, arr[1000] ;
	clrscr() ;

	printf("\nEnter size of list:\t") ;
	scanf("%d", &n) ;

	printf("\nEnter values into list:\n") ;
		for(i=1; i<=n; i++)
			scanf("%d", &arr[i]) ;

	printf("\nEnter element you want to search:\t") ;
	scanf("%d", &x) ;

	linear(n, arr, x) ;

	getch() ;
}

void linear(int n, int arr[], int x)
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
