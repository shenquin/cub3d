/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:28:07 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/16 16:56:21 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define INT_MAX 2148473647

#include "../lib/libft/inc/libft.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/get_next_line/get_next_line.h"

typedef struct	s_data
{
	unsigned int			pos_x;
	unsigned int			pos_y;
	int						ce_r;
	int						ce_g;
	int						ce_b;
	int						fl_r;
	int						fl_g;
	int						fl_b;
	int						map_argnb;
	char					*NO;
	char					*SO;
	char					*WE;
	char					*EA;
	char					*sprite;
	char					**map;
	void					*mlx_ptr;
}				t_data;

typedef struct	s_utils
{
	int			i;
	int			nb_line;
}				t_utils;

typedef struct		s_pain
{
	void			*content;
	struct s_chain	*next;
}					t_pain;

void	parsing(t_data *data, char *line);
void	parsing2(t_data *data, char *line);
void	parsing3(t_data *data, char *line);
void	resolution(char *line);
void	exit_error(char *error_string);
void	res(char *line, t_data *data);
void	*ft_calloc2(size_t size);
void	north(char *line, t_data *data);
void	south(char *line, t_data *data);
void	west(char *line, t_data *data);
void	east(char *line, t_data *data);
void	sprite(char *line, t_data *data);
void	parsemap(char *line, t_data *data, t_utils *utils);
void	allocmap(char *line, t_data *data);
void	fl(char *line, t_data *data);
void	ce(char *line, t_data *data);
int		ft_atoi2(const char *str);
void	check_data(t_data *data);
void	check_cefl(char *line);

#endif
