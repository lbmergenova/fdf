/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:54:46 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:54:48 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c);
static int	ft_isupper(int c);

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	return (0);
}

static int	ft_isupper(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	return (0);
}
