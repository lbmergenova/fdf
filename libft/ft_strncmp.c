/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:01:35 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:01:37 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l1;
	size_t	l2;
	int		res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!n)
		return (0);
	if (l1 == 0 || l2 == 0)
		res = ft_memcmp(s1, s2, 1);
	else if (l1 <= l2 && l1 < n)
		res = ft_memcmp(s1, s2, l1 + 1);
	else if (l2 < l1 && l2 < n)
		res = ft_memcmp(s1, s2, l2 + 1);
	else
		res = ft_memcmp(s1, s2, n);
	return (res);
}
