#include <lcthw/dbg.h>
#include <lcthw/list.h>
#include <lcthw/list_algos.h>

int
swap_nodes(ListNode *left, ListNode *right)
{
	check(left, "Left node is NULL.");
	check(right, "Right node is NULL.");
	void *tmp = Node_value(right);
	debug("Swapping left (%s) and right (%s).", (char *)Node_value(left), (char *)Node_value(right));
	Node_value(right) = Node_value(left);
	Node_value(left) = tmp;
	debug("Swapped left (%s) and right (%s).", (char *)Node_value(left), (char *)Node_value(right));
	return 0;
error:
	return -1;
}


int
List_bubble_sort(List *list, List_compare cmp)
{
	int n = List_count(list);
	debug("List contains %d elements", n);
	int swapped = 1;
	/* repeat until not swapped */
	for ( ; n > 0 && swapped ; n--) {
		swapped = 0;
		LIST_FOREACH(list, first, next, cur) {
			check(cur, "List contains a NULL Node.");
			ListNode *next = Node_next(cur);
			/* if this pair is out of order */
			if ( next && cmp(Node_value(cur), Node_value(next)) > 0) {
				debug("%s is greater than %s", (char *)Node_value(cur), (char *)Node_value(next));
				/* swap them and remember something changed */
				swap_nodes(cur, next);
				swapped = 1;
			} else if (! next) {
				debug("The list is over.");
			} else {
				debug("%s is less than %s", (char *)Node_value(cur), (char *)Node_value(next));
			}
		}
		debug("We have %d rounds to go, and we did%s swapped last round", n, swapped ? "" : "n't");
		debug("We will%sgo to the next cycle.", (n > 0 && swapped) ? " " : " not ");
	}
	return 0;
error:
	return -1;
};

List *
List_merge_sort(List *list, List_compare cmp)
{
	if( list && cmp ) { goto error; } ;
/* function merge(left, right) */
/*     var result := empty list */
/*  */
/*     while left is not empty and right is not empty do */
/*         if first(left) ≤ first(right) then */
/*             append first(left) to result */
/*             left := rest(left) */
/*         else */
/*             append first(right) to result */
/*             right := rest(right) */
/*  */
/*     // Either left or right may have elements left; consume them. */
/*     // (Only one of the following loops will actually be entered.) */
/*     while left is not empty do */
/*         append first(left) to result */
/*         left := rest(left) */
/*     while right is not empty do */
/*         append first(right) to result */
/*         right := rest(right) */
/*     return result */
error:
	return NULL;
};
