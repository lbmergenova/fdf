/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:52:54 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:52:57 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *nptr)
{
	unsigned long long int	i;
	int						sign;

	i = 0;
	sign = 1;
	while (ft_isspace(*nptr))
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
		if (i > 9223372036854775807 && sign == -1)
			return (0);
		else if (i > 9223372036854775806 && sign == 1)
			return (-1);
		nptr++;
	}
	i = i * sign;
	return ((int)i);
}

static int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	else if ((c >= 9) && (c <= 13))
		return (1);
	return (0);
}
