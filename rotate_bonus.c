/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:05:51 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 23:06:01 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_coord *coord, t_fdf *data)
{
	t_coord	tmp;

	tmp = *coord;
	coord->y = tmp.y * cos(data->rad.x) + tmp.z * sin(data->rad.x);
	coord->z = -tmp.y * sin(data->rad.x) + tmp.z * cos(data->rad.x);
}

void	rotate_y(t_coord *coord, t_fdf *data)
{
	t_coord	tmp;

	tmp = *coord;
	coord->x = tmp.x * cos(data->rad.y) + tmp.z * sin(data->rad.y);
	coord->z = -tmp.x * sin(data->rad.y) + tmp.z * cos(data->rad.y);
}

void	rotate_z(t_coord *coord, t_fdf *data)
{
	t_coord	tmp;

	tmp = *coord;
	coord->x = tmp.x * cos(data->rad.z) - tmp.y * sin(data->rad.z);
	coord->y = tmp.x * sin(data->rad.z) + tmp.y * cos(data->rad.z);
}

void	rotate(t_coord *coord, t_fdf *data)
{
	if (data->rad.x != 0)
		rotate_x(coord, data);
	if (data->rad.y != 0)
		rotate_y(coord, data);
	if (data->rad.z != 0)
		rotate_z(coord, data);
}
