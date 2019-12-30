#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data ;
	struct node* link ;
};

struct node* root = NULL ;

void append() ;
void display() ;
int length(void) ;
int len ;
void ins_at_beg() ;
void ins_at_end() ;
void ins_at_spec() ;
void del_beg() ;
void del_end() ;
void del_spec() ;
void reverse() ;
void swap() ;

void main()
{
	int ch  ;
	clrscr() ;

	while(1)
	{
		clrscr() ;
		printf("\n\n* Singly Linked List *\n") ;
		printf("\nMenu:") ;
		printf("\n\n1.Append") ;
		printf("\n2.Display") ;
		printf("\n3.Length") ;
		printf("\n4.Insert at beginning")  ;
		printf("\n5.Insert at end") ;
		printf("\n6.Insert at specified location") ;
		printf("\n7.Delete from beginning") ;
		printf("\n8.Delete from end") ;
		printf("\n9.Delete from specified location") ;
		printf("\n10.Reverse") ;
		printf("\n11.Swap") ;
		printf("\n12.Exit") ;

		printf("\n\nEnter your choice:\t") ;
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1: append() ;
			break ;

			case 2: display() ;
			break ;

			case 3: len = length() ;
				printf("\nThe length of list is: %d",len) ;
			break ;

			case 4: ins_at_beg() ;
			break ;

			case 5: ins_at_end() ;
			break ;

			case 6: ins_at_spec() ;
			break ;

			case 7: del_beg() ;
			break ;

			case 8: del_end() ;
			break ;

			case 9: del_spec() ;
			break ;

			case 10: reverse() ;
			break ;

			case 11: swap() ;
			break ;

			case 12: exit(1) ;
			break ;

			default: printf("\n\nWrong choice!") ;
	       }
	       getch();
	}
}

void append()
{
	int val ;
	struct node* temp, *p ;
	clrscr() ;

	temp = (struct node*) malloc(sizeof(struct node)) ;

	printf("\nEnter node data:\t") ;
	scanf("%d", &val) ;

	temp -> data = val ;
	temp -> link = NULL ;

	if(root == NULL)
		root = temp ;

	else
	{
		p = root ;
		while(p->link!= NULL)
		{
			p = p -> link ;
		}
		p -> link = temp ;
	}
	printf("\n\nValue inserted: %d", val) ;
}

void display()
{
	struct node* p ;
	clrscr() ;

	if(root == NULL)
		printf("\nLinked list is empty!") ;

	else
	{
		p = root ;

		printf("\nLinked list data: \t") ;
		while(p!=NULL)
		{
			printf("%d\t", p -> data)  ;
			p = p -> link ;
		}
	}
}

int length(void)
{
	struct node* p ;
	int count = 0 ;

	if(root == NULL)
	{
		printf("\nList is empty!") ;
		return 0;
	}

	else
	{
		p = root ;

		while(p!=NULL)
		{
			count++ ;
			p = p -> link ;
		}
		return count ;
	}
}

void ins_at_beg()
{
	int val ;
	struct node* temp ;

	temp = (struct node*) malloc(sizeof(struct node))  ;

	printf("\nEnter node data:\t") ;
	scanf("%d", &val) ;

	temp -> data = val ;
	temp -> link = NULL ;

	if(root == NULL)
		root = temp ;

	else
	{
		temp -> link = root ;
		root = temp ;
	}
	printf("\nValue: %d inserted in beginning", val)  ;
}

void ins_at_end()
{
	 append() ;
}

void ins_at_spec()
{
	struct node* temp, *p ;
	int val, loc, i=1 ;

	printf("\nEnter location where you want to insert node:\t") ;
	scanf("%d", &loc) ;

	len = length() ;

	if(loc > len)
	{
		printf("\n\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", len) ;
	}

	else
	{
		temp = (struct node*) malloc(sizeof(struct node)) ;

		printf("\nEnter node data:\t") ;
		scanf("%d", &val) ;

		temp -> data = val ;
		temp -> link = NULL ;

		p = root ;

		while(i < loc -1)
		{
			p = p -> link ;
			i++ ;
		}
		temp -> link = p -> link ;
		p -> link = temp ;

		printf("\nValue: %d inserted at %d location", val, loc) ;
	}
}

void del_beg()
{
	if(root == NULL)
		printf("\nList is empty!")  ;

	else
	{
		root = root -> link ;
		printf("\nNode deleted from beginning!") ;
	}
}

void del_end()
{
	struct node* p;

	if(root == NULL)
		printf("\nList is empty!")  ;

	else if(root -> link == NULL)
	{
		root = NULL ;
		printf("\nNode deleted from end!") ;
	}

	else
	{
		p = root ;

		while(p -> link -> link!= NULL)
		{
			p = p -> link ;
		}
		p -> link = NULL ;

		printf("\nNode deleted from end!") ;
	}
}

void del_spec()
{
	struct node* p, *q ;
	int loc, i=1 ;

	printf("\nEnter location for node you want to delete:\t") ;
	scanf("%d", &loc) ;

	len = length() ;

	if(loc > len)
	{
		printf("\n\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", len) ;
	}

	else
	{
		p = root ;

		while(i < loc-1)
		{
			p = p -> link ;
			i++ ;
		}
		q = p -> link ;
		p -> link = q -> link ;
		q -> link = NULL ;

		printf("\nNode deleted from %d location", loc) ;
	}
}

void reverse()
{
	struct node* p1, *p2, *p3 ;

	if(root == NULL)
	{
		printf("\nList is empty!") ;
	}

	else if(root -> link == NULL)
	{
		printf("\nList cannot be reversed, it has only one element") ;
	}

	else
	{
		p1 = root ;
		p2 = p1 -> link ;
		p3 = p2 -> link ;

		p1 -> link = NULL ;
		p2 -> link = p1 ;

		while(p3!= NULL)
		{
			p1 = p2 ;
			p2 = p3 ;
			p3 = p3 -> link ;
			p2 -> link = p1 ;
		}
		root = p2 ;

		printf("\nList is reversed!")  ;
	}
}

void swap()
{
	 int loc, i =1 ;
	 struct node* p, *q, *r ;

	 printf("\nEnter location of node that you want to swap:\t") ;
	 scanf("%d", &loc) ;

	len = length() ;

	if(loc > len -1)
	{
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", len) ;
	}

	else
	{

		p = root ;

		while(i < loc-1)
		{
			p = p -> link ;
			i++ ;
		}

		 q = p -> link ;
		 r = q -> link ;

		 q -> link = r -> link ;
		 r -> link = q ;
		 p -> link = r ;

		 printf("\nNodes swaped!") ;
	}
}
