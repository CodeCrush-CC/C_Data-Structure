	/* Write a program to perform creation and display of Linked list.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data ;
	struct node* next ;
};

struct node* head ;

void append();
void display();

void main()
{
	int ch ;
	clrscr();
	printf("\n******* Linked list *******\n");
	while(1)
	{
		printf("\n\n1.Append");
		printf("\n2.Display") ;
		printf("\n3.Exit") ;

		printf("\n\nEnter your choice:\t") ;
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1: append();
			break ;

			case 2: display();
			break ;

			case 3: exit(1) ;
			break;

			default: printf("\n\nInvalid input") ;
		}
	}
}

void append()
{
	struct node* temp ;

	temp = (struct node*) malloc(sizeof(struct node)) ;

	printf("\n\nEnter node value:\t") ;
	scanf("%d", &temp->data) ;

	temp -> next = NULL ;

	if(head == NULL)  //this means list is empty
	 head = temp ;

	else
	{
		struct node* p ;

		p = head ;

		while(p -> next!= NULL)
		 p = p -> next ;

		 p -> next = temp ;

	}
}

void display()
{
	struct node* temp ;

	temp = head ;

	if(temp == NULL)
	 printf("\n\nThe list is empty") ;

	else
	{       printf("\n\nThe list is:\t") ;
		while(temp!= NULL)
		{
		 printf("%d --> ", temp -> data) ;
		 temp = temp -> next ;
		}
	}
	printf("\n") ;
}