/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:05:33 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 23:05:36 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_shift(int keycode, t_fdf *data)
{
	if (keycode == 126)
		data->shift.y = data->shift.y - 50;
	if (keycode == 125)
		data->shift.y = data->shift.y + 50;
	if (keycode == 123)
		data->shift.x = data->shift.x - 50;
	if (keycode == 124)
		data->shift.x = data->shift.x + 50;
}

void	key_zoom(int keycode, t_fdf *data)
{
	if (keycode == 24 || keycode == 69)
		data->zoom = data->zoom + 2;
	if (keycode == 27 || keycode == 78)
		data->zoom = data->zoom - 2;
	if (data->zoom < 2)
		data->zoom = 2;
}

void	key_rotate(int keycode, t_fdf *data)
{
	if (keycode == 83)
		data->rad.x = data->rad.x + 0.05;
	else if (keycode == 86)
		data->rad.y = data->rad.y + 0.05;
	else if (keycode == 89)
		data->rad.z = data->rad.z + 0.05;
	else if (keycode == 85)
		data->rad.x = data->rad.x - 0.05;
	else if (keycode == 88)
		data->rad.y = data->rad.y - 0.05;
	else if (keycode == 92)
		data->rad.z = data->rad.z - 0.05;
}

void	key_view(int keycode, t_fdf *data)
{
	if (keycode == 3)
		data->view = 1;
	else if (keycode == 17)
		data->view = 2;
	else if (keycode == 37)
		data->view = 3;
	else if (keycode == 34)
		data->view = 0;
	data->rad.x = 0;
	data->rad.y = 0;
	data->rad.z = 0;
}

int	key_hook(int keycode, t_fdf *data)
{
	if (keycode == 53)
	{	
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == 24 || keycode == 69 || keycode == 27 || keycode == 78)
		key_zoom(keycode, data);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		key_shift(keycode, data);
	if (keycode == 83 || keycode == 86 || keycode == 89
		|| keycode == 85 || keycode == 88 || keycode == 92)
		key_rotate(keycode, data);
	if (keycode == 3 || keycode == 17 || keycode == 37 || keycode == 34)
		key_view(keycode, data);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, 1600, 900);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	get_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	instruction(data);
	return (0);
}
