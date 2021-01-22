#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct slnode
{
	int data ;
	struct slnode* link ;
};
struct slnode* root = NULL ;

struct dlnode
{
	int data ;
	struct dlnode* rlink ;
	struct dlnode* llink ;
};
struct dlnode* head = NULL ;

void Singly_LL() ;

void sl_append() ;
void sl_display() ;
int sl_length(void) ;
int sl_len ;
void sl_ins_at_beg() ;
void sl_ins_at_end() ;
void sl_ins_at_spec() ;
void sl_del_beg() ;
void sl_del_end() ;
void sl_del_spec() ;
void sl_reverse() ;
void sl_swap() ;

void Doubly_LL() ;

void dl_append() ;
void dl_display_beg() ;
void dl_display_end() ;
int dl_length(void) ;
int dl_len ;
void dl_ins_at_beg() ;
void dl_ins_at_end() ;
void dl_ins_at_spec() ;
void dl_del_beg() ;
void dl_del_end() ;
void dl_del_spec() ;
void dl_reverse() ;
void dl_swap() ;

void main()
{
	int ch ;
	clrscr() ;

	printf("\nMenu:") ;
	printf("\n\n1.Singly Linked List") ;
	printf("\n2.Doubly Linked List") ;
	printf("\n3.Exit") ;

	printf("\nEnter your choice:\t") ;
	scanf("%d", &ch) ;

	switch(ch)
	{
		case 1: Singly_LL() ;
		break ;

		case 2: Doubly_LL() ;
		break ;

		case 3: exit(1) ;
		break ;

		default: printf("Wrong choice!") ;
	}
}

void Singly_LL()
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
			case 1: sl_append() ;
			break ;

			case 2: sl_display() ;
			break ;

			case 3: sl_len = sl_length() ;
				printf("\nThe length of list is: %d",sl_len) ;
			break ;

			case 4: sl_ins_at_beg() ;
			break ;

			case 5: sl_ins_at_end() ;
			break ;

			case 6: sl_ins_at_spec() ;
			break ;

			case 7: sl_del_beg() ;
			break ;

			case 8: sl_del_end() ;
			break ;

			case 9: sl_del_spec() ;
			break ;

			case 10: sl_reverse() ;
			break ;

			case 11: sl_swap() ;
			break ;

			case 12: exit(1) ;
			break ;

			default: printf("\n\nWrong choice!") ;
	       }
	       getch();
	}
}

void Doubly_LL()
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
			case 1: dl_append() ;
			break ;

			case 2: dl_display_beg() ;
			break ;

			case 3: dl_display_end() ;
			break ;

			case 4: dl_len = dl_length() ;
				printf("\nThe length of list is: %d",dl_len) ;
			break ;

			case 5: dl_ins_at_beg() ;
			break ;

			case 6: dl_ins_at_end() ;
			break ;

			case 7: dl_ins_at_spec() ;
			break ;

			case 8: dl_del_beg() ;
			break ;

			case 9: dl_del_end() ;
			break ;

			case 10: dl_del_spec() ;
			break ;

			case 11: dl_reverse() ;
			break ;

			case 12: dl_swap() ;
			break ;

			case 13: exit(1) ;
			break ;

			default: printf("\n\nWrong choice!") ;
	       }
	       getch();
	}
}

void sl_append()
{
	int val ;
	struct slnode* temp, *p ;
	clrscr() ;

	temp = (struct slnode*) malloc(sizeof(struct slnode)) ;

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

void sl_display()
{
	struct slnode* p ;
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

int sl_length(void)
{
	struct slnode* p ;
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

void sl_ins_at_beg()
{
	int val ;
	struct slnode* temp ;

	temp = (struct slnode*) malloc(sizeof(struct slnode))  ;

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

void sl_ins_at_end()
{
	 sl_append() ;
}

void sl_ins_at_spec()
{
	struct slnode* temp, *p ;
	int val, loc, i=1 ;

	printf("\nEnter location where you want to insert node:\t") ;
	scanf("%d", &loc) ;

	sl_len = sl_length() ;

	if(loc > sl_len)
	{
		printf("\n\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", sl_len) ;
	}

	else
	{
		temp = (struct slnode*) malloc(sizeof(struct slnode)) ;

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

void sl_del_beg()
{
	if(root == NULL)
		printf("\nList is empty!")  ;

	else
	{
		root = root -> link ;
		printf("\nNode deleted from beginning!") ;
	}
}

void sl_del_end()
{
	struct slnode* p;

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

void sl_del_spec()
{
	struct slnode* p, *q ;
	int loc, i=1 ;

	printf("\nEnter location for node you want to delete:\t") ;
	scanf("%d", &loc) ;

	sl_len = sl_length() ;

	if(loc > sl_len)
	{
		printf("\n\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", sl_len) ;
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

void sl_reverse()
{
	struct slnode* p1, *p2, *p3 ;

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

void sl_swap()
{
	 int loc, i =1 ;
	 struct slnode* p, *q, *r ;

	 printf("\nEnter location of node that you want to swap:\t") ;
	 scanf("%d", &loc) ;

	sl_len = sl_length() ;

	if(loc > sl_len -1)
	{
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", sl_len) ;
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


void dl_append()
{
	int val ;
	struct dlnode* temp, *p ;
	clrscr() ;

	temp = (struct dlnode*) malloc(sizeof(struct dlnode)) ;

	printf("\nEnter node data:\t") ;
	scanf("%d", &val) ;

	temp -> data = val ;
	temp -> rlink = NULL ;
	temp -> llink = NULL ;

	if(head == NULL)
		head = temp ;

	else
	{
		p = head ;
		while(p -> rlink!= NULL)
		{
			p = p -> rlink ;
		}
		p -> rlink = temp ;
		temp -> llink = p ;
	}
	printf("\n\nValue inserted: %d", val) ;
}

void dl_display_beg()
{
	struct dlnode* p ;
	clrscr() ;

	if(head == NULL)
		printf("\nLinked list is empty!") ;

	else
	{
		p = head ;

		printf("\nLinked list data from beginning: \t") ;
		while(p!=NULL)
		{
			printf("%d\t", p -> data)  ;
			p = p -> rlink ;
		}
	}
}

void dl_display_end()
{
	struct dlnode* p ;
	clrscr() ;

	if(head == NULL)
		printf("\nLinked list is empty!") ;

	else
	{
		p = head ;

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

int dl_length(void)
{
	struct dlnode* p ;
	int count = 0 ;

	if(head == NULL)
	{
		printf("\nList is empty!\n") ;
		return 0;
	}

	else
	{
		p = head ;

		while(p!=NULL)
		{
			count++ ;
			p = p -> rlink ;
		}
		return count ;
	}
}

void dl_ins_at_beg()
{
	int val ;
	struct dlnode* temp ;

	temp = (struct dlnode*) malloc(sizeof(struct dlnode))  ;

	printf("\nEnter node data:\t") ;
	scanf("%d", &val) ;

	temp -> data = val ;
	temp -> rlink = NULL ;
	temp -> llink = NULL ;

	if(head == NULL)
		head = temp ;

	else
	{
		temp -> rlink = head ;
		head -> llink = temp ;

		head = temp ;
	}
	printf("\nValue: %d inserted in beginning", val)  ;
}

void dl_ins_at_end()
{
	 dl_append() ;
}

void dl_ins_at_spec()
{
	struct dlnode* temp, *p ;
	int val, loc, i=1 ;

	printf("\nEnter location where you want to insert node:\t") ;
	scanf("%d", &loc) ;

	dl_len = dl_length() ;

	if(loc > dl_len)
	{
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", dl_len) ;
	}

	else
	{
		temp = (struct dlnode*) malloc(sizeof(struct dlnode)) ;

		printf("\nEnter node data:\t") ;
		scanf("%d", &val) ;

		temp -> data = val ;
		temp -> rlink = NULL ;
		temp -> llink = NULL ;

		p = head ;

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

void dl_del_beg()
{
	if(head == NULL)
		printf("\nList is empty!")  ;

	else
	{
		head = head -> rlink ;
		printf("\nNode deleted from beginning!") ;
	}
}

void dl_del_end()
{
	struct dlnode* p;

	if(head == NULL)
		printf("\nList is empty!")  ;

	else if(head -> rlink == NULL)
	{
		root = NULL ;
		printf("\nNode deleted from end!") ;
	}

	else
	{
		p = head ;

		while(p -> rlink -> rlink!= NULL)
		{
			p = p -> rlink ;
		}
		p -> rlink = NULL ;

		printf("\nNode deleted from end!") ;
	}
}

void dl_del_spec()
{
	struct dlnode* p, *q ;
	int loc, i=1 ;

	printf("\nEnter location for node you want to delete:\t") ;
	scanf("%d", &loc) ;

	dl_len = dl_length() ;

	if(loc > dl_len)
	{
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", dl_len) ;
	}

	else
	{
		p = head ;

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

void dl_reverse()
{
	struct dlnode* p1, *p2, *p3 ;


	if(head == NULL)
	{
		printf("\nList is empty!") ;
	}

	else if(head -> rlink == NULL)
	{
		printf("\nList cannot be reversed, it has only one element") ;
	}

	else
	{
		p1 = head ;
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

		head = p2 ;

		printf("\nList is reversed!")  ;
	}
}

void dl_swap()
{
	 int loc, i =1 ;
	 struct dlnode* p, *q, *r ;

	 printf("\nEnter location of node that you want to swap:\t") ;
	 scanf("%d", &loc) ;

	 dl_len = dl_length() ;

	if(loc > dl_len-1)
	{
		printf("\nInvalid location!") ;
		printf("\nCurrently list has %d nodes", dl_len) ;
	}

	else
	{
		 p = head ;

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




