/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_color.h"
#include "twl_xstdio.h"
#include "twl_logger.h"

void				twl_debug_main_start(void)
{
	LOG_INFO("\n");
	LOG_INFO(C_CYAN);
	LOG_INFO("====================================================\n");
	LOG_INFO("START MAIN\n");
	LOG_INFO("====================================================\n");
	LOG_INFO(C_CLEAR);
}
