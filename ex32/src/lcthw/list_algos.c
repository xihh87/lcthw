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
merge_sorted(List *left, List *right, List_compare cmp)
{

	check(left && List_count(left) >= 0,  "Invalid left list.");
	check(right && List_count(right) >= 0, "Invalid right list.");

	List *merged = List_create();
	check(merged, "Could not create list");

	int total = List_count(left) + List_count(right);

	void *l = List_shift(left);
	void *r = List_shift(right);

	for (int i = 0; i < total; i++) {
		if(l && r) {
			if (cmp(l, r) <= 0) {
				debug("%s is less than or equal %s.", (const char *)l, (const char *)r);
				List_push(merged, l);
				l = List_shift(left);
			} else {
				debug("%s is more than %s.", (const char *)l, (const char *)r);
				List_push(merged, r);
				r = List_shift(right);
			}
		} else if (l) {
			debug("only elements on left remain.");
			List_push(merged, l);
			l = List_shift(left);
		} else if (r) {
			debug("only elements on right remain.");
			List_push(merged, r);
			l = List_shift(right);
		}
	}

	check(List_count(merged) == total, "Merged list have the wrong number of elements");
	return merged;
error:
	List_clear_destroy(merged);
	return NULL;
}

List *
List_merge_sort(List *list, List_compare cmp)
{
	check(list, "Invalid list.");
	check(cmp, "Invalid compare function.");

error:
	return NULL;
};
