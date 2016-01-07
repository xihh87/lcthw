# include <lcthw/list.h>
# include <lcthw/list_algos.h>


int
List_bubble_sort(List *list, List_compare cmp)
{
	if( list && cmp ) { goto error; };
/*    n = length(A)  */
/*    repeat   */
/*      swapped = false */
/*      for i = 1 to n-1 inclusive do */
/*        if this pair is out of order */
/*        if A[i-1] > A[i] then */
/*          swap them and remember something changed */
/*          swap( A[i-1], A[i] ) */
/*          swapped = true */
/*        end if */
/*      end for */
/*    until not swapped */
/* end procedure  */
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
