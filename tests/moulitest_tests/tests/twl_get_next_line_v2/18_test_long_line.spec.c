#include <project.h>
#include <fcntl.h>
#include "twl_get_next_line.h"

static void simple_string(t_test *test)
{
	char 	*line;
	char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	char *str = "bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa bb aa";
	write(fd, str, twl_strlen(str));
	close(p[1]);
	dup2(out, fd);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, str) == 0);
}

void	suite_18_test_long_line(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
