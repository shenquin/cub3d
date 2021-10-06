/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:32:09 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/06 12:05:41 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	north(char *line, t_data *data)
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	data->no = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->no, &img_width, &img_height);
	if (img == NULL)
		exit_error("Invalid NO path");
	data->map_argnb += 1;
}

void	south(char *line, t_data *data)
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	data->so = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->so, &img_width, &img_height);
	if (img == NULL)
		exit_error("Invalid SO path");
	data->map_argnb += 1;
}

void	west(char *line, t_data *data)
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	data->we = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->we, &img_width, &img_height);
	if (img == NULL)
		exit_error("Invalid WE path");
	data->map_argnb += 1;
}

void	east(char *line, t_data *data)
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	data->ea = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->ea, &img_width, &img_height);
	if (img == NULL)
		exit_error("Invalid EA path");
	data->map_argnb += 1;
}
