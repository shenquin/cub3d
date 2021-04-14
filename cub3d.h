/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:30:59 by shenquin          #+#    #+#             */
/*   Updated: 2021/04/14 14:04:48 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include "./inc/libft/libft.h"
#include "./inc/get_next_line/get_next_line.h"
#include "./inc/minilibx/mlx.h"
#include <math.h>
#include <fcntl.h>

typedef struct	s_data
{
	int		reso_x;
	int		reso_y;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	char	*north_text;
	char	*south_text;
	char	*east_text;
	char	*west_text;
	char	*sprite_text;
	char	*ceiling_color;
	char	*floor_color;
}				t_data;

typedef struct	s_pos
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
	double	deltadist_x;
	double	deltadist_y;
	int		x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_pos;

typedef struct	s_map
{
	int		color_r;
	int		color_b;
	int		color_g;
	int		colorc_r;
	int		colorc_g;
	int		colorc_b;
	int		colorf_r;
	int		colorf_g;
	int		colorf_b;
}				t_map;

void		movement(t_pos *pos, t_data *data, t_map *map);
void		delt_calc(t_pos *pos);
void		move_dir(t_pos *pos);
void		move_wall(t_pos *pos, t_data *data);
void		perp_calc(t_pos *pos);
void		init_base_param(t_pos *pos);
void		init_dir_param(t_pos *pos, t_data *data);
void		init_struct_pos(void);
void		exit_error(char *error_string);

#endif