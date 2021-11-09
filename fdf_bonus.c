/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:06:26 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 23:14:19 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	define_fdf_param(t_fdf	*data, t_map map)
{
	data->l = map.l;
	data->h = map.h;
	data->view = 0;
	data->rad.x = 0;
	data->rad.y = 0;
	data->rad.z = 0;
	map.min.x = -(double)map.h * cos(0.523599);
	map.max.x = (double)map.l * cos(0.523599);
	data->zoom = fmin(1600 / ceil(fabs(map.min.x) + map.max.x),
			900 / ceil(fabs(map.min.y) + map.max.y));
	if (data->zoom < 2)
		data->zoom = 2;
	data->shift.x = (1600 - (fabs(map.min.x) + map.max.x
				- (map.l + map.h) * cos(0.523599)) * data->zoom) / 2;
	data->shift.y = fabs(map.min.y) * data->zoom
		+ (900 - (fabs(map.min.y) + map.max.y) * data->zoom) / 2;
}

void	init_fdf(t_fdf	*data, t_map map)
{
	data->k = 1;
	if (fmax(map.max.z, fabs(map.min.z)) >= fmax(map.l, map.h)
		&& map.max.z != map.min.z)
		data->k = ceil(fmax(map.max.z, fabs(map.min.z))
				/ fmax(map.l, map.h)) + 1;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit_error(1);
	data->win = mlx_new_window(data->mlx, 1600, 900, "FdF");
	if (!data->win)
		ft_exit_error(1);
	data->img.img = mlx_new_image(data->mlx, 1600, 900);
	if (!data->img.img)
		ft_exit_error(1);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

void	instruction(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 25, 800,
		0xFFFFFF, "ISO:        I Key");
	mlx_string_put(data->mlx, data->win, 25, 825,
		0xFFFFFF, "Top view:   T Key");
	mlx_string_put(data->mlx, data->win, 25, 850,
		0xFFFFFF, "Front view: F Key");
	mlx_string_put(data->mlx, data->win, 25, 875,
		0xFFFFFF, "Left view:  L Key");
	mlx_string_put(data->mlx, data->win, 235, 800, 0xFFFFFF, "Rotate:");
	mlx_string_put(data->mlx, data->win, 235, 825, 0xFFFFFF, "x-axis - 1/3");
	mlx_string_put(data->mlx, data->win, 235, 850, 0xFFFFFF, "y-axis - 4/6");
	mlx_string_put(data->mlx, data->win, 235, 875, 0xFFFFFF, "z-axis - 7/9");
	mlx_string_put(data->mlx, data->win, 400, 850, 0xFFFFFFFF, "Zoom: +/-");
	mlx_string_put(data->mlx, data->win, 400, 875, 0xFFFFFF, "Move: arrows");
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	data;

	(void)argc;
	if (argc > 2)
	{
		write(1, "Too many arguments\n", 19);
		return (0);
	}
	init_map(&map);
	define_map(argv[1], &map);
	init_fdf(&data, map);
	define_data_coord(&data, &map);
	define_fdf_param(&data, map);
	get_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	instruction(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
