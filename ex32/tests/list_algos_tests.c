#include "minunit.h"
#include <time.h>
#include <assert.h>
#include <string.h>

#include <lcthw/list.h>
#include <lcthw/list_algos.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define ITER 5000
#define NUM_VALUES 5
#define REP 10

List *create_words()
{
	int i = 0;
	List *words = List_create();

	for (i= 0; i < NUM_VALUES * REP; i++) {
		List_push(words, values[i % NUM_VALUES]);
	}

	return words;
}

int is_sorted(List *words)
{
	debug("List contents:");
	LIST_FOREACH(words, first, next, cur) {
		debug("\t%s", (char *)cur->value);
		if(cur->next && strcmp(cur->value, cur->next->value) > 0) {
			debug("\t%s is greater than %s", (char *)cur->value, (char *)cur->next->value);
			return 0;
		}
	}

	return 1;
}

char *test_bubble_sort()
{
	List *words = create_words();

	/* should work on a list that needs sorting */
	int rc = List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc == 0, "Bubble sort failed.");
	mu_assert(is_sorted(words), "Words are not sorted after bubble sort.");

	/* should work on an already sorted list */
	rc = List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc == 0, "Bubble sort of already sorted failed.");
	mu_assert(is_sorted(words), "Words should be sort if already bubble sorted.");

	List_destroy(words);

	return NULL;
}

char *test_merge_sort()
{
	List *words = create_words();

	/* should work on a list that needs sorting */
	List *res = List_merge_sort(words, (List_compare)strcmp);
	mu_assert(res && is_sorted(res), "Words are not sorted after merge sort.");

	List *res2 = List_merge_sort(res, (List_compare)strcmp);
	mu_assert(res2 && is_sorted(res2), "Should still be sorted after merge sort.");
	List_destroy(res2);
	List_destroy(res);

	List_destroy(words);
	return NULL;
}

char *test_time_merge()
{
	time_t ts = 0;
	time_t te = 0;
	List *wds = NULL;

	ts = time(NULL);
	int i = 0;
	for (i = 1; i <= ITER; i++) {
		wds = create_words();
		List_merge_sort(wds, (List_compare)strcmp);
		free(wds);
	}
	te = time(NULL);
	printf("Merge sort %d times a %d item list takes only %lds!\n", ITER, NUM_VALUES * REP, te - ts);
	return NULL;
}


char *test_time_bubble()
{
	time_t ts = 0;
	time_t te = 0;
	List *wds = NULL;

	ts = time(NULL);
	int i = 0;
	for (i = 1; i <= ITER; i++) {
		wds = create_words();
		List_bubble_sort(wds, (List_compare)strcmp);
		free(wds);
	}
	te = time(NULL);
	printf("Bubble sort %d times a %d item list takes only %lds!\n", ITER, NUM_VALUES * REP, te - ts);
	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_bubble_sort);
	mu_run_test(test_merge_sort);
	mu_run_test(test_time_merge);
	mu_run_test(test_time_bubble);

	return NULL;
}

RUN_TESTS(all_tests);
