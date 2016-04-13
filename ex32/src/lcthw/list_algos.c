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
	check(n >= 0, "List contains no elements");
	debug("List contains %d elements", n);
	int sorted = 0;
	/* repeat until sorted */
	for ( ; n > 0 && !sorted ; n--) {
		sorted = 1;
		LIST_FOREACH(list, first, next, cur) {
			check(cur, "List contains a NULL Node.");
			ListNode *next = Node_next(cur);
			/* if this pair is out of order */
			if ( next && cmp(Node_value(cur), Node_value(next)) > 0) {
				debug("%s is greater than %s", (char *)Node_value(cur), (char *)Node_value(next));
				swap_nodes(cur, next);
				sorted = 0;
			} else if (! next) {
				debug("The list is over.");
			} else {
				debug("%s is less than %s", (char *)Node_value(cur), (char *)Node_value(next));
			}
		}
		debug("We have %d rounds to go, and list is%ssorted", n, sorted ? " " : " not ");
		debug("We will%sgo to the next cycle.", (n > 0 && !sorted) ? " " : " not ");
	}
	return 0;
error:
	return -1;
};

List *
merge_sorted(List *left, List *right, List_compare cmp)
{

	List *merged = List_create();
	check(merged, "Could not create list");

	check(left && List_count(left) > 0,  "Invalid left list.");
	check(right && List_count(right) > 0, "Invalid right list.");

	int total = List_count(left) + List_count(right);

	void *l = List_shift(left);
	void *r = List_shift(right);

	int i = 0;
	for (i = 0; i < total; i++) {
		if(l && r) {
			if (cmp(l, r) <= 0) {
				debug("%s is less than or equal %s, "
					"adding %s to the list.", (const char *)l, (const char *)r, (const char *)l);
				List_push(merged, l);
				l = List_shift(left);
			} else {
				debug("%s is more than %s, "
					"adding %s to the list.", (const char *)l, (const char *)r, (const char *)r);
				List_push(merged, r);
				r = List_shift(right);
			}
		} else if (l) {
			debug("only elements on left remain, "
				"adding %s to the list", (const char *)l);
			List_push(merged, l);
			l = List_shift(left);
		} else if (r) {
			debug("only elements on right remain, "
				"adding %s to the list", (const char *)r);
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

	List *right = List_create();
	check_mem(right);
	List *left = List_create();
	check_mem(left);

	int i = 0;
	if (List_count(list) > 1) {
		int n = List_count(list);
		for (i=0; i < (n / 2); i++) {
			debug("Element %d / %d in left list.", i, n);
			List_push(left, List_shift(list));
		}
		for (; i < n ; i++) {
			debug("Element %d / %d in right list.", i, n);
			List_push(right, List_shift(list));
		}

		debug("Will sort left list.");
		left = List_merge_sort(left, cmp);
		debug("Left list is sorted.");
		debug("Will sort right list.");
		right = List_merge_sort(right, cmp);
		debug("Right list is sorted.");

		list = merge_sorted(left, right, cmp);

	} else if(List_count(list) == 0) {
		sentinel("Invalid list: no elements");
	}

	return list;

error:
	return NULL;
};
