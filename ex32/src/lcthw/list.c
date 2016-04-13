#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
	return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
	LIST_FOREACH(list, first, next, cur) {
		Node_destroy(cur->prev);
	}

	Node_destroy(list->last);
	free(list);
}

void List_clear(List *list)
{
	LIST_FOREACH(list, first, next, cur) {
		Node_clear(cur);
	}
}

void List_clear_destroy(List *list)
{

	LIST_FOREACH(list, first, next, cur) {
		Node_clear(cur);
		Node_destroy(cur->prev);
	}

	Node_destroy(list->last);
	free(list);
}


void List_push(List * list, void *value)
{
	ListNode *node = Node_create();
	check_mem(node);

	node->value = value;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;

error:
	return;
}

void *List_pop(List *list)
{
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value)
{
	ListNode *node = Node_create();
	check_mem(node);

	node->value = value;

	if(list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}

	list->count++;

error:
	return;
}

void *List_shift(List *list)
{
	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
	void *result = NULL;

	check(list->first && list->last, "List is empty.");
	check(node, "node can't be NULL.");


	if (node == list->first && node == list->last) {
		list->first = NULL;
		list->last = NULL;
	} else if (node == list->first) {
		list->first = node->next;
		check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
		list->first->prev = NULL;
	} else if (node == list->last) {
		list->last = node->prev;
		check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
		list->last->next = NULL;
	} else {
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next = after;
	}

	list->count--;
	result = node->value;
	free(node);

error:
	return result;
}

void List_extend(List *left, List *right)
{
	check(left && right, "One or more input list are NULL.");

	LIST_FOREACH(left, first, next, cur) {
		List_push(right, cur->value);
	}

error:
	return;
}

List *List_merge(List *left, List *right)
{
	check(right && left, "One or more input list are NULL.");

	List *new = List_create();
	check(new, "Could not create new list.");

	List_extend(new, left);
	List_extend(new, right);

	check(new->count == right->count + left->count, "Failed to merge lists.");
	return new;
error:
	return NULL;
}

List *
List_join(List *left, List *right)
{
	int total = List_count(left) + List_count(right);
	List_count(left) = total;

	/* Join the last and first nodes from both lists */
	left->last->next = right->first;
	right->first->prev = left->last;

	/* Set the last node */
	left->last = right->last;

	free(right);
	return left;

}

List *
List_split(List *list, int n)
{
	check(n < List_count(list), "Can't split list past it's length.");

	List *new = List_create();
	check(new, "Unable to create new List.");

	new->last = list->last;
	new->count = list->count - n;
	list->count = n;

	LIST_FOREACH(list, first, next, cur) {
		if (n == 0) {
			new->first = cur->next;
			new->first->prev = NULL;
			cur->next = NULL;
		}
		n--;
	}
	return new;
error:
	return NULL;
}
