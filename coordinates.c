/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:02:18 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:02:22 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_map_param(double i, double j, double z, t_map *map)
{
	double	tmp_y;
	t_coord	coord;

	coord.x = j;
	coord.y = -i;
	coord.z = z;
	tmp_y = (coord.x + coord.y) * sin(0.523599) - coord.z;
	if (tmp_y < map->min.y)
		map->min.y = tmp_y;
	if (tmp_y > map->max.y)
		map->max.y = tmp_y;
}

int	define_coord_col(long int col, int z, t_map *map)
{
	int	ret_col;

	ret_col = col;
	if (map->flag_col == 0)
		ret_col = redifine_color(z, map->min.z, map->max.z);
	else if (col == 0)
		ret_col = 0xFFFFFF;
	return (ret_col);
}

void	define_data_coord(t_fdf *data, t_map *map)
{
	int			i;
	int			j;
	t_list		*lst;

	j = 0;
	data->h = map->h;
	lst = map->b_lst;
	data->coord = (t_coord **)malloc(map->h * sizeof(t_coord *));
	while (lst)
	{
		i = 0;
		data->coord[j] = (t_coord *)malloc(map->l * sizeof(t_coord));
		while (i < map->l)
		{
			data->coord[j][i].z = ((t_content *)lst->content)[i].z;
			data->coord[j][i].col
				= define_coord_col(((t_content *)lst->content)[i].col,
					data->coord[j][i].z, map);
			define_map_param(i, j, data->coord[j][i].z / data->k, map);
			i++;
		}
		j++;
		lst = lst->next;
	}
	ft_lstclear(&(map->b_lst), free);
}
