/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:19 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/18 18:46:53 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	hexa_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ce(char *line, t_data *data)
{
	char	**sky;
	char	*trim;

	check_cefl(line);
	sky = ft_split(line, ',');
	if (!sky || strslen(sky) != 3)
		exit_error("Invalid ce");
	trim = ft_strtrim(sky[0], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->ce_r = atoi(trim);
	free(trim);
	trim = ft_strtrim(sky[1], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->ce_g = atoi(trim);
	free(trim);
	trim = ft_strtrim(sky[2], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->ce_b = atoi(trim);
	data->color_ce = hexa_color(data->ce_r, data->ce_g, data->ce_b);
	free(trim);
	ft_free_split(sky);
	data->map_argnb += 1;
}

void	fl(char *line, t_data *data)
{
	char	**sol;
	char	*trim;

	check_cefl(line);
	sol = ft_split(line, ',');
	if (!sol || strslen(sol) != 3)
		exit_error("Invalid ce");
	trim = ft_strtrim(sol[0], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->fl_r = atoi(trim);
	free(trim);
	trim = ft_strtrim(sol[1], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->fl_g = atoi(trim);
	free(trim);
	trim = ft_strtrim(sol[2], " ");
	if (!trim || ft_strlen(trim) > 3)
		exit_error("Invalid ce");
	data->fl_b = atoi(trim);
	data->color_fl = hexa_color(data->fl_r, data->fl_g, data->fl_b);
	free(trim);
	ft_free_split(sol);
	data->map_argnb += 1;
}
