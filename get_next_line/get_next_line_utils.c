/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:52:14 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 16:52:17 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	c_;

	if (!s)
		return (NULL);
	c_ = (char)c;
	while (*s)
	{
		if (*s == c_)
			return ((char *)s);
		s++;
	}
	if (c_ == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	ls1;
	size_t	ls2;
	char	*ret;

	ls1 = 0;
	if (s1)
		ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ret = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ls1)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	while (i < ls1 + ls2)
	{
		*(ret + i) = *(s2 + i - ls1);
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}
