/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:04:03 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:04:05 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_new_chanal(int col0, int col1, double pct)
{
	return ((int)((1 - pct) * col0 + pct * col1));
}

int	get_chanal(long int trgb, char shift)
{
	return ((trgb >> shift) & 0xFF);
}

int	create_rgb(long int col0, long int col1, double pct)
{
	int	col_r;
	int	col_g;
	int	col_b;

	col_r = get_new_chanal(get_chanal(col0, 16), get_chanal(col1, 16), pct);
	col_g = get_new_chanal(get_chanal(col0, 8), get_chanal(col1, 8), pct);
	col_b = get_new_chanal(get_chanal(col0, 0), get_chanal(col1, 0), pct);
	return ((col_r << 16) | (col_g << 8) | col_b);
}

int	define_color(t_point p, t_point p0, t_point p1, t_bres k)
{
	double	pct;

	if (p.col == p1.col)
		return (p.col);
	if (k.dlt.x > k.dlt.y)
		pct = percent(p.x, p0.x, p1.x);
	else
		pct = percent(p.y, p0.y, p1.y);
	return (create_rgb(p0.col, p1.col, pct));
}

int	redifine_color(int z, int min_z, int max_z)
{
	double	pct;

	if (min_z == max_z)
		return (0xFFFFFF);
	pct = percent(z, min_z, max_z);
	return (create_rgb(0x0088FF, 0xFF8800, pct));
}
