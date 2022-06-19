/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:05:10 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 17:05:12 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->l = -1;
	map->h = 0;
	map->b_lst = NULL;
	map->min.x = 0;
	map->min.y = 0;
	map->min.z = 0;
	map->max.x = 0;
	map->max.y = 0;
	map->max.z = 0;
	map->flag_col = 0;
}

static int	ft_getnbr(char *nptr)
{
	long int	i;
	int			sign;

	i = 0;
	sign = 1;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		i = i * 10 + (*nptr - 48);
		nptr++;
	}
	i = i * sign;
	if (i > INT32_MAX || i < INT32_MIN)
		ft_exit_error(3);
	return (i);
}

static long int	ft_getcol(char *nptr)
{
	int			i;
	long int	nbr;

	i = 0;
	nbr = 0;
	while (*(nptr + i) != 'x' && *(nptr + i))
		i++;
	if ((int)ft_strlen(nptr) == i)
		return (nbr);
	i++;
	while (ft_strchr("0123456789ABCDEFabcdef", *(nptr + i)) && *(nptr + i))
	{
		if (ft_strchr("0123456789", *(nptr + i)))
			nbr = nbr * 16 + (*(nptr + i) - 48);
		else if (ft_strchr("ABCDEF", *(nptr + i)))
			nbr = nbr * 16 + (*(nptr + i) - 55);
		else
			nbr = nbr * 16 + (*(nptr + i) - 87);
		i++;
	}
	if ((int)ft_strlen(nptr) != i)
		ft_exit_error(3);
	if (nbr > 0xFFFFFF)
		ft_exit_error(3);
	return (nbr);
}

void	*define_content(char *line, t_map *map)
{
	int			i;
	char		**tmp;
	t_content	*content;

	i = 0;
	tmp = ft_split(line, ' ');
	if (map->l == -1)
		map->l = array_len(tmp);
	else if (map->l != array_len(tmp))
		ft_exit_error(2);
	content = (t_content *)malloc(map->l * sizeof(t_content));
	while (i < map->l)
	{
		content[i].z = ft_getnbr(tmp[i]);
		content[i].col = ft_getcol(tmp[i]);
		if (content[i].z < map->min.z)
			map->min.z = content[i].z;
		if (content[i].z > map->max.z)
			map->max.z = content[i].z;
		if (content[i].col != 0)
			map->flag_col = 1;
		free(tmp[i++]);
	}
	free(tmp);
	return (content);
}

void	define_map(char *f_name, t_map *map)
{
	int		fd;
	int		rf;
	char	*line;
	t_list	*lst;

	lst = NULL;
	fd = file_open(f_name);
	rf = get_next_line(fd, &line);
	if (rf < 0)
		ft_exit_error(1);
	while (rf > 0 || (line && *line))
	{
		lst = ft_lstadd_next(lst, ft_lstnew(define_content(line, map)));
		if (!map->b_lst)
			map->b_lst = lst;
		free(line);
		line = NULL;
		map->h++;
		if (rf > 0)
			rf = get_next_line(fd, &line);
	}
	if (line)
		free(line);
	close (fd);
}
