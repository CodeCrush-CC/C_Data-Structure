	/* Write a program to perform creation, display and length of Linked list.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
 int data ;
 struct node* next ;
};

struct node* head = NULL;

void append() ;
void display() ;
int length() ;
int len ;

void main()
{
	int ch ;
	clrscr() ;

	printf("******* Linked List *******") ;

	while(1)
	{
		printf("\n\n1.Append") ;
		printf("\n2.Display") ;
		printf("\n3.Length of list") ;
		printf("\n4.Exit") ;

		printf("\nEnter your choice:\t") ;
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1: append() ;
			break ;

			case 2: display() ;
			break ;

			case 3:	len = length() ;
				printf("\n\nThe length of list is: %d\t",len) ;
			break ;

			case 4: exit(1) ;
			break ;

			default: printf("\n\nInvalid input")  ;
		}
	}
}

void append()
{
	struct node* temp ;      // A temporary variable 'temp' is created which will destroy itself after this function.

	temp = (struct node*) malloc(sizeof(struct node))  ;

	printf("\nEnter the node value:\t") ;
	scanf("%d", &temp -> data) ;

	temp -> next = NULL ;

	if(head == NULL)    //this means list is empty
	 head = temp ;

	 else
	 {
		struct node* p ;       // A temporary variable 'p' is created

		p = head ;

		while(p -> next!= NULL)
		  p = p -> next ;

		p -> next = temp;
	 }
}

void display()
{
	struct node* temp ;

	temp = head ;

	if(temp == NULL)
	 printf("\n\nThe list is empty:") ;

	 else
	 {
		printf("\n\nThe list is:") ;
		while(temp!= NULL)
		{
			printf("%d --> ", temp -> data) ;
			temp = temp -> next ;
		}
	 }
	 printf("\n") ;
}

int length()
{
	int count = 0 ;
	struct node* temp ;

	temp = head ;

	while(temp!= NULL)
	{
		count++ ;
		temp = temp -> next ;
	}
	return count ;
}