#include <project.h>
#include "twl_json.h"

#define mt_test_parse(test_name, tested_str) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(twl_json_parse(tested_str) == NULL); \
	}

mt_test_parse(num0, "[tru,false]");
mt_test_parse(num1, "[,false]");
mt_test_parse(num2, "[true,]");
mt_test_parse(num3, "[,]");
mt_test_parse(num4, "[[]");
mt_test_parse(num5, "[]]");
mt_test_parse(num6, "[");
mt_test_parse(num7, "]");
mt_test_parse(num8, "[}");
mt_test_parse(num9, "{]");

mt_test_parse(num10, "{ key\" : 42 }");
mt_test_parse(num11, "{ \"key : 42 }");
mt_test_parse(num12, "{ \"key\" 42,  \"key\" : 42 }");
mt_test_parse(num13, "{ \"\" : 42 }");
mt_test_parse(num14, "{{}");
mt_test_parse(num15, "{}}");
mt_test_parse(num16, "{");
mt_test_parse(num17, "}");
mt_test_parse(num18, "{,false}");
mt_test_parse(num19, "{true,}");
mt_test_parse(num20, "[\"ab\"c\"]");
mt_test_parse(num21, "[][]");
mt_test_parse(num22, "{}{}");
mt_test_parse(num23, "");

void	suite_twl_json_parse_error_handling(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num0);
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
	SUITE_ADD_TEST(suite, test_num20);
	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);
	// SUITE_ADD_TEST(suite, test_num24);
	// SUITE_ADD_TEST(suite, test_num25);
	// SUITE_ADD_TEST(suite, test_num26);
	// SUITE_ADD_TEST(suite, test_num27);
	// SUITE_ADD_TEST(suite, test_num28);
	// SUITE_ADD_TEST(suite, test_num29);
	// SUITE_ADD_TEST(suite, test_num30);
	// SUITE_ADD_TEST(suite, test_num31);
	// SUITE_ADD_TEST(suite, test_num32);
	// SUITE_ADD_TEST(suite, test_num33);
	// SUITE_ADD_TEST(suite, test_num34);
	// SUITE_ADD_TEST(suite, test_num35);
	// SUITE_ADD_TEST(suite, test_num36);
	// SUITE_ADD_TEST(suite, test_num37);
	// SUITE_ADD_TEST(suite, test_num38);
	// SUITE_ADD_TEST(suite, test_num39);
	// SUITE_ADD_TEST(suite, test_num40);
	// SUITE_ADD_TEST(suite, test_num41);
	// SUITE_ADD_TEST(suite, test_num42);
	// SUITE_ADD_TEST(suite, test_num43);
	// SUITE_ADD_TEST(suite, test_num44);
	// SUITE_ADD_TEST(suite, test_num45);
	// SUITE_ADD_TEST(suite, test_num46);
	// SUITE_ADD_TEST(suite, test_num47);
}
