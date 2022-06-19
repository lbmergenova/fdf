/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:10:52 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 23:10:54 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	top_view(t_coord coord, t_fdf *data)
{
	t_point	p;

	p.x = coord.x + data->shift.x;
	p.y = coord.z + data->shift.y;
	p.col = coord.col;
	return (p);
}

t_point	front_view(t_coord coord, t_fdf *data)
{
	t_point	p;

	p.x = coord.x + data->shift.x;
	p.y = coord.y + data->shift.y;
	p.col = coord.col;
	return (p);
}

t_point	left_view(t_coord coord, t_fdf *data)
{
	t_point	p;

	p.x = coord.z + data->shift.x;
	p.y = coord.y + data->shift.y;
	p.col = coord.col;
	return (p);
}

t_point	iso(t_coord coord, t_fdf *data)
{
	t_point	p;

	p.x = (coord.x - coord.y) * cos(0.523599) + data->shift.x;
	p.y = (coord.x + coord.y) * sin(0.523599) - coord.z + data->shift.y;
	p.col = coord.col;
	return (p);
}

t_point	get_coord(int j, int i, t_fdf *data)
{
	t_point	p;
	t_coord	coord;
	t_coord	tmp;

	coord.x = i - floor(data->l / 2);
	coord.y = j - floor(data->h / 2);
	coord.z = data->coord[j][i].z / data->k;
	coord.col = data->coord[j][i].col;
	coord.x = coord.x * data->zoom;
	coord.y = coord.y * data->zoom;
	coord.z = coord.z * data->zoom;
	tmp = coord;
	coord.x = tmp.y;
	coord.y = -tmp.x;
	rotate(&coord, data);
	if (data->view == 1)
		p = front_view(coord, data);
	else if (data->view == 2)
		p = top_view(coord, data);
	else if (data->view == 3)
		p = left_view(coord, data);
	else
		p = iso(coord, data);
	return (p);
}
