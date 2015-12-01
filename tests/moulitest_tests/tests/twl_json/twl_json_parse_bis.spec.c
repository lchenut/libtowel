#include <project.h>
#include "twl_json.h"

#define mt_test_parse_bis(test_name, tested_str, expected_str) \
	static void test_## test_name(t_test *test) \
	{ \
		t_jnode			*node; \
		char			*json_dump_res; \
		node = twl_json_parse(tested_str); \
		json_dump_res = twl_json_dump(node); \
		mt_assert(node && twl_strcmp(json_dump_res, expected_str) == 0); \
		twl_jnode_del(node); \
	} \

mt_test_parse_bis(num1, "[true,false]", "[true,false]");
mt_test_parse_bis(num2, "\"abc\"", "\"abc\"");
mt_test_parse_bis(num3, "42", "42");
mt_test_parse_bis(num4, "true", "true");
mt_test_parse_bis(num5, "false", "false");

void	suite_twl_json_parse_bis(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
}
