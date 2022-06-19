/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:03:19 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:03:21 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c = c - 32;
	return (c);
}

static int	ft_islower(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	return (0);
}
