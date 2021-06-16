/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:18 by gverhelp          #+#    #+#             */
/*   Updated: 2021/06/16 13:03:19 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	ft_checktxterror2(t_list *list)
{
	if (ft_checktextures(list) == -1)
	{
		write(1, "Error\nError in textures\n", 24);
		return (-1);
	}
	return (0);
}

int	ft_checktxterror(t_list *list)
{
	if (ft_checkpos(list) == -1)
	{
		write(1, "Error\nPosition Error\n", 21);
		return (-1);
	}
	if (ft_checkscreen(list) == -1)
	{
		write(1, "Error\nScreen Error\n", 19);
		return (-1);
	}
	if (ft_checkskyfloor(list) == -1)
	{
		write(1, "Error\nError sky or floor\n", 25);
		return (-1);
	}
	if (ft_checkmap(list) == -1)
	{
		write(1, "Error\nError in map 2\n", 21);
		return (-1);
	}
	if (ft_checktxterror2(list) == -1)
		return (-1);
	return (0);
}

int	ft_map(t_list *list)
{
	char	*tmp;

	tmp = list->tmpmap;
	list->map = ft_split(tmp, '\n');
	free(tmp);
	if (ft_checktxterror(list) == -1)
		return (-1);
	return (1);
}

int	ft_check(t_list *list)
{
	if (!(list->mlx = mlx_init()))
		return (-1);
	if (!list->size)
		return (-1);
	if (list->bparsing < 3)
	{
		write(1, "Error\nError in map 1\n", 21);
		return (-1);
	}
	if (ft_map(list) == -1)
		return (-1);
	return (1);
}
