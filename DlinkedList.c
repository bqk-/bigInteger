/*
* Body of DlinkedList functions
* By Isaac Chiboub - isaac.chiboub@utbm.fr
* And Thibault Miclo - thibault.miclo@utbm.fr
*
* Last edit : 23/12/11
*/


#include <DlinkedList.h>
#include <stdio.h>
#include <stdlib.h>


Dlist removeHead(Dlist list)
{
	if(!is_empty(list) && !is_empty(list->next)) /* if the next is empty, list is NULL */
	{
		Element* temp=malloc(sizeof(Element));	
		temp=list;
		/* Remove the previous of the next element */
		temp->next->prev=NULL;
		return temp->next;
	}
	else
	{
		return NULL;
	}
}

Dlist back2start(Dlist list)
{
	if(is_empty(list))
	{
		return NULL;
	}
	else
	{
		Element* temp=malloc(sizeof(Element));
		temp=list;	
		/* go to the first element, and return the pointer on it */
		while(temp->prev!=NULL)
		{
			temp=temp->prev;
		}
		return temp;
	}
}

Dlist back2end(Dlist list)
{
	if(is_empty(list))
	{
		return NULL;
	}
	else
	{
		Element* temp=malloc(sizeof(Element));
		temp=list;	
		/* go to the last element, and return the pointer on it */
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		return temp;
	}
}

Dlist removeTail(Dlist list)
{
	if(!is_empty(list) && !is_empty(list->next))
	{
		Element* temp=malloc(sizeof(Element));
		temp=list;
		/* go to the last element */
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		/* remove the next on the previous element */
		temp->prev->next=NULL;
		return list;
	}
	else
	{
		return NULL;
	}	
}

int headValue(Dlist list)
{
	if(is_empty(list))
	{
		return 0;
	}
	else
	{
		Element* temp=malloc(sizeof(Element));
		temp=list;	
		/* go to the first element and return its value */
		temp=back2start(temp);
		return temp->value;
	}
}

int nbrElement(Dlist list)
{
	if(is_empty(list))
	{
		return FALSE;
	}
	else
	{
		int i=1;
		Element* temp=malloc(sizeof(Element));
		temp=list;	
		/* go to the first element */
		while(temp->prev!=NULL)
		{
			temp=temp->prev;
		}
		/* count the next elements while we don't reach the end of the list */
		while(temp->next!=NULL)
		{
			i++;
			temp=temp->next;
		}
		return i;
	}
}
		
Boolean is_empty(Dlist list)
{
	/* if the list is null */
	if(list!=NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

Dlist insertHead(Dlist list, int value)
{
	Element* temp=malloc(sizeof(Element));
	if(!is_empty(list)) /* Just add the element */
	{
		temp->value=value;
		temp->next=list;
		temp->prev=NULL;
		list->prev=temp;
	}
	else /* Create a new list */
	{
		temp->value=value;
		temp->next=NULL;
		temp->prev=NULL;
	}
	return temp;
}

Dlist insertTail(Dlist list, int value)
{
	Element* temp=malloc(sizeof(Element));
	if(!is_empty(list)) /* Add the new element */
	{
		Element* new=malloc(sizeof(Element));	
		temp=list;
		new->value=value;
		new->next=NULL;
		/* Go to the end and add the element */
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		new->prev=temp;
		temp->next=new;
		return list;
	}
	else /* Create a new list */
	{
		temp->value=value;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
}

void displayList(Dlist list)
{
	Element* temp=malloc(sizeof(Element));
	temp=list;
	printf("-------------------------------\n");	
	/* foreach the list, and print elements */
	while(temp!=NULL)
	{
		printf("%d > ",temp->value);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("-------------------------------\n");
}
