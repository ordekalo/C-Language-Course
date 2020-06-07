/********************************************/
/*   list.h                                 */
/*   a dynamic  linked list with a header   */
/********************************************/


#ifndef _LIST_
#define _LIST_

// a value not supposed in stack and queue
#define		EMPTY	0x7FFFFFFF

// new types
typedef int DATA;					// a type for data (easy to change)
typedef enum { False, True } BOOL;	// a boolean type

									// Node
typedef struct node
{
	DATA			key;
	struct node*	next;
}NODE;


/*** Definitions ***/

// List
typedef struct 
{
	NODE head;
}LIST;


/*** Function prototypes ***/

BOOL L_init(LIST* pList);					// create new list

NODE* L_insert(NODE* pNode, DATA Value);	// add new node after *pNode

BOOL L_delete(NODE* pNode);					// erase node after *pNode

NODE* L_find(NODE* pNode, DATA Value);		// return a pointer to the node 

BOOL L_free(LIST* pList);					// free list memory

int L_print(LIST* pList);					// print the list content

#endif
