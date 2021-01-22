#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int data ;
	struct node* rlink ;
	struct node* llink ;
};

struct node* root = NULL ;

void append() ;
void display_beg() ;
void display_end() ;
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
		printf("\n\n* Doubly Linked List *\n") ;
		printf("\nMenu:") ;
		printf("\n\n1.Append") ;
		printf("\n2.Display the list from beginning") ;
		printf("\n3.Display the list from end") ;
		printf("\n4.Length") ;
		printf("\n5.Insert at beginning")  ;
		printf("\n6.Insert at end") ;
		printf("\n7.Insert at specified location") ;
		printf("\n8.Delete from beginning") ;
		printf("\n9.Delete from end") ;
		printf("\n10.Delete from specified location") ;
		printf("\n11.Reverse") ;
		printf("\n12.Swap") ;
		printf("\n13.Exit") ;

		printf("\n\nEnter your choice:\t") ;
		scanf("%d", &ch) ;

		switch(ch)
		{
			case 1: append() ;
			break ;

			case 2: display_beg() ;
			break ;

			case 3: display_end() ;
			break ;

			case 4: len = length() ;
				printf("\nThe length of list is: %d",len) ;
			break ;

			case 5: ins_at_beg() ;
			break ;

			case 6: ins_at_end() ;
			break ;

			case 7: ins_at_spec() ;
			break ;

			case 8: del_beg() ;
			break ;

			case 9: del_end() ;
			break ;

			case 10: del_spec() ;
			break ;

			case 11: reverse() ;
			break ;

			case 12: swap() ;
			break ;

			case 13: exit(1) ;
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
	temp -> rlink = NULL ;
	temp -> llink = NULL ;

	if(root == NULL)
		root = temp ;

	else
	{
		p = root ;
		while(p -> rlink!= NULL)
		{
			p = p -> rlink ;
		}
		p -> rlink = temp ;
		temp -> llink = p ;
	}
	printf("\n\nValue inserted: %d", val) ;
}

void display_beg()
{
	struct node* p ;
	clrscr() ;

	if(root == NULL)
		printf("\nLinked list is empty!") ;

	else
	{
		p = root ;

		printf("\nLinked list data from beginning: \t") ;
		while(p!=NULL)
		{
			printf("%d\t", p -> data)  ;
			p = p -> rlink ;
		}
	}
}

void display_end()
{
	struct node* p ;
	clrscr() ;

	if(root == NULL)
		printf("\nLinked list is empty!") ;

	else
	{
		p = root ;

		while(p -> rlink!= NULL)
		{
			p = p -> rlink ;
		}
		printf("\nLinked list data from end: \t") ;
		while(p!= NULL)
		{
			printf("%d\t", p -> data) ;
			p = p -> llink ;
		}
	}
}

int length(void)
{
	struct node* p ;
	int count = 0 ;

	if(root == NULL)
	{
		printf("\nList is empty!\n") ;
		return 0;
	}

	else
	{
		p = root ;

		while(p!=NULL)
		{
			count++ ;
			p = p -> rlink ;
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
	temp -> rlink = NULL ;
	temp -> llink = NULL ;

	if(root == NULL)
		root = temp ;

	else
	{
		temp -> rlink = root ;
		root -> llink = temp ;

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
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", len) ;
	}

	else
	{
		temp = (struct node*) malloc(sizeof(struct node)) ;

		printf("\nEnter node data:\t") ;
		scanf("%d", &val) ;

		temp -> data = val ;
		temp -> rlink = NULL ;
		temp -> llink = NULL ;

		p = root ;

		while(i < loc-1)
		{
			p = p -> rlink ;
			i++ ;
		}
		temp -> rlink = p -> rlink ;
		p -> rlink -> llink = temp ;

		temp -> llink = p ;
		p -> rlink = temp ;

		printf("\nValue: %d inserted at %d location", val, loc) ;
	}
}

void del_beg()
{
	if(root == NULL)
		printf("\nList is empty!")  ;

	else
	{
		root = root -> rlink ;
		printf("\nNode deleted from beginning!") ;
	}
}

void del_end()
{
	struct node* p;

	if(root == NULL)
		printf("\nList is empty!")  ;

	else if(root -> rlink == NULL)
	{
		root = NULL ;
		printf("\nNode deleted from end!") ;
	}

	else
	{
		p = root ;

		while(p -> rlink -> rlink!= NULL)
		{
			p = p -> rlink ;
		}
		p -> rlink = NULL ;

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
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", len) ;
	}

	else
	{
		p = root ;

		while(i < loc-1)
		{
			p = p -> rlink ;
			i++ ;
		}

		q = p -> rlink ;
		p -> rlink = q -> rlink ;
		q -> rlink -> llink = p ;

		q -> llink = q -> rlink = NULL ;

		printf("\nNode is deleted from %d location", loc) ;
	}
}

void reverse()
{
	struct node* p1, *p2, *p3 ;


	if(root == NULL)
	{
		printf("\nList is empty!") ;
	}

	else if(root -> rlink == NULL)
	{
		printf("\nList cannot be reversed, it has only one element") ;
	}

	else
	{
		p1 = root ;
		p2 = p1 -> rlink ;
		p3 = p2 -> rlink ;

		p1 -> llink = p2 ;
		p1 -> rlink = NULL ;

		p2 -> rlink = p1 ;
		p2 -> llink = p3 ;


		while(p3!= NULL)
		{
			p1 = p2 ;
			p2 = p3 ;
			p3 = p3 -> rlink ;
			p2 -> rlink = p1 ;
			p2 -> llink = p3 ;
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

		 while(i < loc -1)
		 {
			p = p -> rlink ;
			i++ ;
		 }

		 q = p -> rlink ;
		 r = q -> rlink ;

		 q -> rlink = r -> rlink ;
		 r -> rlink -> llink = q ;

		 r -> rlink = q ;
		 r -> llink = p ;

		 q -> llink = r ;
		 p -> rlink = r ;

		 printf("\nNodes are swaped!") ;
	}
}
