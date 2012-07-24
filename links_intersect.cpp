/*********************************************************
要判断两个链表是否相交，首先要判断两个链表是否有环
*********************************************************/
#include <iostream>

struct node
{
	int  data;
	node *next;
	node(){next = NULL;}
};

bool Is_a_link_have_a_circle(node *head)
{
	if(head == NULL) return false;

	node *first = head;
	node *second = head->next;

	while(second != NULL && second->next != NULL)
	{
		first = head->next;
		second = second->next->next;

		if(first == second)	
		{
			std::cout << first->data << std::endl;
			return true;
		}
	}

	return false;
}

void find_link_ending(node *head,int &len,node *p)
{
	len = 0;
	p = head;
	while(p->next != NULL)
	{
		p = p->next;
		len++;
	}
}

void find_two_link_first_same_time_node(node *head1,node *head2,int l1,int l2,node *start1,node *start2)
{
	start1 = head1;
	start2 = head2;

	int k = abs(l1-l2);
	if(l1 < l2)
	{
		while(k)
		{
			start1 = start1->next;
			k--;
		}
	}
	else
	{
		while(k)
		{
			start2 = start2->next;
			k--;
		}
	}
}

bool No_circle_two_links_intersect(node *head1,node *head2,node *interNode)
{

	node *p = NULL,*q = NULL;
	int l1,l2;
	find_link_ending(head1,l1,p);
	find_link_ending(head2,l2,q);

	node *start1 = NULL,*start2 = NULL;
	find_two_link_first_same_time_node(head1,head2,l1,l2,start1,start2);

	while(start1->next != NULL && start2->next != NULL)
	{
		if(start1 == start2)
		{
			break;
		}
		else
		{
			start1 = start1->next;	
			start2 = start2->next;
		}

	}

	if(p == q)
	{
		return true;
		interNode = start1;
	}
	else
	{
		interNode = NULL;
		return false;
	}
}

bool two_circle_two_link_intersect(node *head1,node *head2,node *interNode)
{
	node *p = head1;
	node *q = head2->next;

	while(p != q && p != NULL && q != NULL)
	{
		p = p->next;
		q = q->next->next;

		if(p == q) break;
	}

	if(p != NULL && q != NULL)
	{
		interNode = p;
		return true;
	}
	else
	{
		interNode = NULL;
		return false;
	}
}

bool Is_two_links_intersect(node *head1,node *head2)
{
	if(head1 == NULL || head2 == NULL)
		return false;

	bool Is_circle1 = Is_a_link_have_a_circle(head1);
	bool Is_circle2 = Is_a_link_have_a_circle(head2);

	node *internode = NULL;
	if(!Is_circle1 && !Is_circle2)
	{
		if(No_circle_two_links_intersect(head1,head2,internode))
		{
			return true;
		}
	}
	else
	{
		if(two_circle_two_link_intersect(head1,head2,internode))
		{
			return true;
		}
	}

	return false;
}