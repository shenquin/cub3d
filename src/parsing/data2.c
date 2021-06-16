/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:32:09 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/16 11:26:49 by thgillai         ###   ########.fr       */
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
	data->NO = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->NO, &img_width, &img_height);
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
	data->SO = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->SO, &img_width, &img_height);
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
	data->WE = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->WE, &img_width, &img_height);
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
	data->EA = ft_strtrim(line, " ");
	img = mlx_xpm_file_to_image(mlx, data->EA, &img_width, &img_height);
	if (img == NULL)
		exit_error("Invalid EA path");
	data->map_argnb += 1;
}
