/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twl_opt_checkerr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:23:02 by yyang             #+#    #+#             */
/*   Updated: 2015/02/25 16:06:38 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <twl_opt.h>
#include <twl_bool.h>
#include <twl_opt_elem.h>
#include <twl_bool.h>
#include <twl_opt_elem.h>
#include <twl_stdio.h>

static t_bool find_fn(void *opt_elem_, void *valid_opts_)
{
	t_twl_opt_elem *opt_elem;
	char *valid_opts;

	opt_elem = opt_elem_;
	valid_opts = valid_opts_;
	if (!twl_strchr(valid_opts, *opt_elem->key))
		return (TRUE);
	return (FALSE);
}

char *twl_opt_checkerr(t_twl_opt *twl_opt, char *valid_opts)
{
	t_twl_opt_elem *opt_elem;

	opt_elem = twl_lst_find(twl_opt->opts, find_fn, valid_opts);
	if (opt_elem)
		return (opt_elem->key);
	return (NULL);
}
