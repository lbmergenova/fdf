/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:56:50 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:56:52 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_;

	c_ = (unsigned char)c;
	if (!n)
		return (NULL);
	while (n > 0)
	{
		if (*(unsigned char *)s == c_)
			return ((void *)s);
		s++;
		n--;
	}
	if (c_ == 0)
		return ((char *)s);
	return (NULL);
}
