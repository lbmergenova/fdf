/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:00:47 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:00:49 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	char	*dstr;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	dstr = dst + ldst;
	if (ldst >= dstsize)
	{
		return (dstsize + lsrc);
	}
	return (ldst + ft_strlcpy(dstr, src, dstsize - ldst));
}
