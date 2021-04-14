/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:21:33 by shenquin          #+#    #+#             */
/*   Updated: 2021/04/14 13:31:00 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void		init_struct_pos(void)
{
	t_pos *pos;
	
	pos = ft_calloc(sizeof(t_pos), 1);
	if (!pos)
		exit_error("Memory Error");
}

void		exit_error(char *error_string)
{
	ft_putstr_fd(error_string, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}
