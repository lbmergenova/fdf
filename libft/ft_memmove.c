/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:57:35 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:57:37 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_fwd(char *destc, char *srcc, size_t n);
static void	ft_copy_bwd(char *destc, char *srcc, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	l;
	char	*destc;
	char	*srcc;

	destc = (char *)dest;
	srcc = (char *)src;
	l = destc - srcc;
	if (destc == NULL && srcc == NULL)
		return (NULL);
	if (l <= n && destc > srcc)
	{
		ft_copy_fwd(destc, srcc, n);
	}
	else
	{
		ft_copy_bwd(destc, srcc, n);
	}
	return (dest);
}

static void	ft_copy_fwd(char *destc, char *srcc, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		*(destc + i) = *(srcc + i);
	}
}

static void	ft_copy_bwd(char *destc, char *srcc, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(destc + i) = *(srcc + i);
		i++;
	}
}
