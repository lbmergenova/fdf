/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:02:58 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 23:10:26 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int p, int p0, int p1)
{
	if (p0 != p1)
		return ((double)(p - p0) / (double)(p1 - p0));
	return (1);
}

int	array_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		ft_exit_error(1);
	while (*(str + i))
		i++;
	return (i);
}

int	file_open(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		ft_exit_error(1);
	return (fd);
}

void	ft_exit_error(int er)
{
	if (er == 1)
	{
		write(1, "Map error\n", 10);
		exit(0);
	}
	else if (er == 2)
	{
		write(1, "Found wrong line length. Exiting.\n", 34);
		exit(0);
	}
	else if (er == 3)
	{
		write(1, "Incorrect data. Exiting.\n", 25);
		exit(0);
	}
}

int	ft_close(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}
