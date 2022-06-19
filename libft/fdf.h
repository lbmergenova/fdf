/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:04:16 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:04:21 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	col;
}	t_point;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
	int		col;
}	t_coord;

typedef struct s_bres
{
	t_point	stp;
	t_point	dlt;
	t_point	err;
}	t_bres;

typedef struct s_content
{
	int	z;
	int	col;
}	t_content;

typedef struct s_map
{
	int		l;
	int		h;
	t_list	*b_lst;
	t_coord	min;
	t_coord	max;
	int		flag_col;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_coord	**coord;
	int		l;
	int		h;
	int		zoom;
	int		k;
	t_point	shift;
}	t_fdf;

//color.c
int		define_color(t_point p, t_point p0, t_point p1, t_bres k);
int		redifine_color(int z, int min_z, int max_z);
//coordinates.c
void	define_data_coord(t_fdf *data, t_map *map);
//parser.c
void	define_map(char *f_name, t_map *map);
void	init_map(t_map *map);
//image.c
void	get_image(t_fdf *data);
// hook.c
int		key_hook(int keycode, t_fdf *data);
//iso.c
t_point	get_coord(int j, int i, t_fdf *data);
//utils.c
double	percent(int p, int p0, int p1);
int		array_len(char **str);
int		file_open(char *f_name);
void	ft_exit_error(int er);
int		ft_close(t_fdf *data);

#endif
