# ifndef _list_algos_h_
# define _list_algos_h_

typedef int (*List_compare)(const char *, const char *);

int
List_bubble_sort(List *list, List_compare cmp);

List *
List_merge_sort(List *list, List_compare cmp);

# endif