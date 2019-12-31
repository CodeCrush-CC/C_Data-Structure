			/*Write a program to perform Bubble Sort.*/

#include<stdio.h>
#include<conio.h>

void main()
{
	int i, n, arr[1000] ;
	void Bubble(int, int[]) ;
	clrscr() ;

	printf("\n* Bubble Sort *\n") ;

	printf("\n\nEnter size of list:\t") ;
	scanf("%d", &n)  ;

	printf("\nEnter elements in the list:\n") ;
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]) ;

	Bubble(n, arr) ;

	getch() ;
}

void Bubble(int n, int arr[])
{
	int i, j, temp ;

	for(i=0; i< n-1; i++)
	{
		for(j=0; j< n-1-i; j++)    // 'n-1-i' because after every pass one comparison should be reduced
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j] ;
				arr[j] = arr[j+1]  ;
				arr[j+1] = temp ;
			}
		}
	}

	printf("\nThe Sorted List is:\t") ;
		for(i=0; i<n; i++)
			printf("%d\t", arr[i]) ;
}