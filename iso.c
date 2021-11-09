/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:02:42 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:02:44 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	coord.x = i;
	coord.y = j;
	tmp = coord;
	coord.x = tmp.x * cos(-1.5708) - tmp.y * sin(-1.5708);
	coord.y = tmp.x * sin(-1.5708) + tmp.y * cos(-1.5708);
	coord.z = data->coord[j][i].z / data->k;
	coord.col = data->coord[j][i].col;
	coord.x = coord.x * data->zoom;
	coord.y = coord.y * data->zoom;
	coord.z = coord.z * data->zoom;
	p = iso(coord, data);
	return (p);
}
