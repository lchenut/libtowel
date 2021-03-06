#include <project.h>
#include "twl_dict.h"

// size_t		twl_lstcount(t_lst *lst, void *(*f)(void *));

bool twl_count_chars_3(void *s, void *context)
{
	if (strlen(s) == 3)
		return (true);
	return (false);
	(void)context;
}


static void test_simple_count(t_test *test)
{
	t_lst *lst;

	lst = twl_lst_new();

	twl_lst_push_back(lst, strdup("aaa"));
	twl_lst_push_back(lst, strdup("4444444"));
	twl_lst_push_back(lst, strdup("bbb"));
	twl_lst_push_back(lst, strdup("0"));
	twl_lst_push_back(lst, strdup("1111"));
	twl_lst_push_back(lst, strdup("ccc"));

	mt_assert(twl_lst_count(lst, twl_count_chars_3, NULL) == 3);
}

void	suite_twl_lst_count(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_count);
}
