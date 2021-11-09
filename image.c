/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:03:46 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:03:48 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, t_point p, int color)
{
	char	*dst;

	if (p.x > 0 && p.x < 1600 && p.y > 0 && p.y < 900)
	{
		dst = img->addr + (p.y * img->line_length
				+ p.x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	define_kbresenham(t_point p0, t_point p1, t_bres *k)
{
	k->stp.x = 1;
	k->stp.y = 1;
	if (p1.x - p0.x < 0)
		k->stp.x = -1;
	if (p1.y - p0.y < 0)
		k->stp.y = -1;
	k->dlt.x = abs(p1.x - p0.x);
	k->dlt.y = abs(p1.y - p0.y);
	k->err.y = k->dlt.x - k->dlt.y;
}

void	bresenham(t_point p0, t_point p1, t_img *img)
{
	t_bres	k;
	t_point	p;

	define_kbresenham(p0, p1, &k);
	p = p0;
	while (p.x != p1.x || p.y != p1.y)
	{
		my_mlx_pixel_put(img, p, p.col);
		k.err.x = k.err.y * 2;
		if (k.err.x > -k.dlt.y)
		{
			k.err.y = k.err.y - k.dlt.y;
			p.x = p.x + k.stp.x;
		}
		if (k.err.x < k.dlt.x)
		{
			k.err.y = k.err.y + k.dlt.x;
			p.y = p.y + k.stp.y;
		}
		p.col = define_color(p, p0, p1, k);
	}
	my_mlx_pixel_put(img, p1, p1.col);
}

void	get_image(t_fdf *data)
{
	int		i;
	int		j;
	t_point	p0;

	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (i < data->l)
		{
			p0 = get_coord(j, i, data);
			if (i + 1 < data->l)
				bresenham(p0, get_coord(j, i + 1, data), &data->img);
			if (j + 1 < data->h)
				bresenham(p0, get_coord(j + 1, i, data), &data->img);
			i++;
		}
		j++;
	}
}
