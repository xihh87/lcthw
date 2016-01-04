#ifndef lcthw_list_h
#define lcthw_list_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

/* Return a new list. */
List *List_create();

/* Unalocate memory from a list. */
void List_destroy(List *list);

/* Clear the values from all the nodes in the list. */
void List_clear(List *list);

/* Clear the values from all the nodes in the list and the list itself. */
void List_clear_destroy(List *list);

/* Return the list's number of elements. */
#define List_count(A) ((A)->count)

/* Return the list's first item. */
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)

/* Return the list's last item. */
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

/* Add `value` as the last element of a list. */
void List_push(List *list, void *value);

/* Remove the last element of a list and return it's value. */
void *List_pop(List *list);

/* Add `value` as the first element of a list. */
void List_unshift(List *list, void *value);

/* Remove the first element of a list and return it's value. */
void *List_shift(List *list);

/* Remove `node` from `list`. */
void *List_remove(List *list, ListNode *node);

/* Return a new list containing the elements from `right` and `left`. */
List *List_merge(List *right, List *left);

/* Iterates through a list `L`,
 * starting from `L->S`,
 * and moving in `M` direction
 * storing the value on `V` variable.
 */
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
	ListNode *V = NULL;\
	for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
