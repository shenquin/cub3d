/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:28:07 by thgillai          #+#    #+#             */
/*   Updated: 2021/09/23 16:15:09 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/get_next_line/get_next_line.h"

# define MS 0.1
# define RS 0.1
# define TXW 64
# define TXH 64

# define XEVENT_KEYPRESS 2
# define XEVENT_KEYRELEASE 3
# define XEVENT_EXIT 17

# define INT_MAX 2148473647
# define INT_MIN -2148473648
# define KEYCODE_ESC 53
# define KEYCODE_UPARROW 126
# define KEYCODE_DOWNARROW 125
# define KEYCODE_RIGHTARROW 124
# define KEYCODE_LEFTARROW 123
# define KEYCODE_W 13
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2

typedef struct s_data
{
	int				ce_r;
	int				ce_g;
	int				ce_b;
	int				fl_r;
	int				fl_g;
	int				fl_b;
	int				map_argnb;
	int				nb_line;
	int				line_place;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			**map;
	char			position;
	void			*mlx_ptr;
	int				nb_map;
	int				existmap;
}				t_data;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_raycast
{
	double	*zbuffer;
	double	camerax;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	sidedistx;
	double	sidedisty;
	double	wallx;
	double	step;
	double	texpos;
	int		mapx;
	int		mapy;
	int		hit;
	int		stepx;
	int		stepy;
	int		side;
	int		drawstart;
	int		drawend;
	int		lineheight;
	int		screenwidth;
	int		screenheight;
	int		texx;
	int		texy;
	int		texwidth;
	int		texheight;
	int		color;
	int		*addrno;
	int		*addrso;
	int		*addrwe;
	int		*addrea;
	int		color_sky;
	int		color_floor;
}				t_raycast;

void	parsing(t_data *data, char *line);
void	parsing2(t_data *data, char *line);
void	parsing3(t_data *data, char *line);
int		ft_raycasting(t_raycast *raycast, t_img *img, t_data *data);
void	ft_raycast(t_raycast *raycast, int a);
void	ft_raycast2(t_raycast *raycast);
void	ft_raycast3(t_raycast *raycast, t_data *data);
void	ft_raycast4(t_raycast *raycast);
void	ft_verline(t_raycast *raycast, t_img *img, int a);
void	ft_verline2(t_raycast *raycast, t_img *img, int a, int b);
int		ft_walltexture(t_raycast *raycast);
void	resolution(char *line);
void	exit_error(char *error_string);
void	res(char *line, t_data *data);
void	*ft_calloc2(size_t size);
void	north(char *line, t_data *data);
void	south(char *line, t_data *data);
void	west(char *line, t_data *data);
void	east(char *line, t_data *data);
void	sprite(char *line, t_data *data);
void	parsemap(char *line, t_data *data);
void	allocmap(t_data *data, int fd);
void	fl(char *line, t_data *data);
void	ce(char *line, t_data *data);
int		ft_atoi2(const char *str);
void	check_data(t_data *data);
void	check_cefl(char *line);
void	check_comma(char *line);
void	checkifmap(char *line, t_data *data);
int		checkifmap2(char *line);
void	verifmapline(char *line);
void	checkifhole(t_data *data);
void	check_data2(t_data *data);
int		ft_visible(t_list *list);
int		ft_esc(t_list *list);
void	emptylineinmap(t_data *data);
void	window(void);

#endif
