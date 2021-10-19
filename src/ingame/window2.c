/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:30:35 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/19 14:59:27 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_visible(t_data *data)
{
	if (raycasting(data) == -1)
	{
		write(1, "Error\nError raycasting (visi)\n", 30);
		return (-1);
	}
	return (0);
}

int	ft_esc(t_data *data)
{
	(void)data;
	system("leaks cub3d");
	exit(0);
	return (0);
}
