#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void simple_string(t_test *test)
{
	char 	*line;
	char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "abcdefghijklmnop") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "qrstuvwxyzabcdef") == 0);
	free(line);
	ret = twl_gnl(p[0], &line, &remainder);
	mt_assert(ret == 0);
	free(line);
	free(remainder);
}

void	suite_gnl_10_test_two_lines_of_16(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
