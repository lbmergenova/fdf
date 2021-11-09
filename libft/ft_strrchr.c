/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:02:09 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:02:11 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_;
	char	*str;

	c_ = (char)c;
	str = NULL;
	while (*s)
	{
		if (*s == c_)
			str = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (str);
}
