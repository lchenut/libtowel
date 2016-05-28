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
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	write(fd, "ijkl\n", 5);
	write(fd, "mnop\n", 5);
	write(fd, "qrst\n", 5);
	write(fd, "uvwx\n", 5);
	write(fd, "yzab\n", 5);
	close(p[1]);
	dup2(out, fd);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "abcd") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "efgh") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ijkl") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "mnop") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "qrst") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "uvwx") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "yzab") == 0);
	free(line);
	ret = twl_gnl(p[0], &line, &remainder);
	free(line);
	mt_assert(ret == 0);
	free(remainder);
}

void	suite_gnl_14_test_few_lines_of_4(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
