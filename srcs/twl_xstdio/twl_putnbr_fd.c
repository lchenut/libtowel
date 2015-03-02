/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarraul <gbarraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:45:53 by yyang             #+#    #+#             */
/*   Updated: 2015/03/02 18:08:45 by gbarraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "twl_xstdio.h"

/*
** print number 'n' to file descriptor 'fd'
** works with minimum int and negatives
*/

void	twl_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		twl_putchar_fd('-', fd);
		if (n < -9)
		{
			twl_putnbr_fd(n / 10 * -1, fd);
		}
		twl_putchar_fd((char)(n % 10 * -1 + 48), fd);
	}
	else
	{
		if (n > 9)
		{
			twl_putnbr_fd(n / 10, fd);
		}
		twl_putchar_fd((char)(n % 10 + 48), fd);
	}
}
