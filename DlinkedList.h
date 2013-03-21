/*
* Prototypes of DlinkedList functions & boolean declaration
* By Isaac Chiboub - isaac.chiboub@utbm.fr
* And Thibault Miclo - thibault.miclo@utbm.fr
*
* Last edit : 23/12/11
*/

/* Define boolean type */
#define TRUE 1
#define FALSE 0
typedef int Boolean;

/* Define an element of a list */
typedef struct elem {
	int value;
	struct elem* next;
	struct elem* prev;
} Element;

/* Define a DLinked list */
typedef Element* Dlist;

/* Add an element to the head of the list and return the pointer on the list */
Dlist insertHead(Dlist list, int value);
/* Add an element to the end of the list and return the pointer on the list */
Dlist insertTail(Dlist list, int value);
/* Remove the head of the list and return the pointer on the list */
Dlist removeHead(Dlist list);
/* Remove the end of the list and return the pointer on the list */
Dlist removeTail(Dlist list);
/* Go to the head of the list, used to be sure that we are at the head of the list */
Dlist back2start(Dlist list);
/* Go to the end of the list, used to be sure that we are at the end of the list */
Dlist back2end(Dlist list);
/* Return the value of the head element */
int headValue(Dlist list);
/* Return the number of element in the DLinkedList */
int nbrElement(Dlist list);
/* Print the DLinkedList */
void displayList(Dlist list);
/* Test if a list is empty or not */
Boolean is_empty(Dlist list);
