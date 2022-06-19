/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:44:41 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/13 16:44:43 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;
	size_t	n;

	if (dst == NULL && src == NULL)
		return (0);
	lsrc = ft_strlen(src);
	if (dstsize > 0)
	{
		if (lsrc >= dstsize)
			n = dstsize - 1;
		else
			n = lsrc;
		dst = ft_memcpy(dst, src, n);
		*(dst + n) = '\0';
	}
	return (lsrc);
}
