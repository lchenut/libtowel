/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_val_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 20:44:43 by yyang             #+#    #+#             */
/*   Updated: 2015/01/07 20:50:35 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_printf.h"

void *pf_conv_val_percent(t_pf *pf)
{
	(void)pf;
	return (twl_strdup("%"));
}
