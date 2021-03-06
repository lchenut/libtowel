#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void simple_string(t_test *test)
{
	char *line;
	char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "aaa") == 0);
	mt_assert(gnl_ret == 1);
	free(line);
	free(remainder);
}

void	suite_gnl_02_test_eof_with_close(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
