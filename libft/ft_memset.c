/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:57:53 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:57:55 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c_;
	unsigned char	*str;

	c_ = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = c_;
		str++;
		n--;
	}
	return (s);
}
