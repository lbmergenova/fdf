/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:01:50 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:01:52 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_comparsion(const char *s1, const char *s2,
				size_t len, size_t ls2);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lneedle;
	size_t	lhaystack;

	if (!haystack && !needle)
		return (NULL);
	lneedle = ft_strlen(needle);
	lhaystack = ft_strlen(haystack);
	if (!lneedle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	if (lhaystack < len)
		len = lhaystack;
	return (ft_comparsion(haystack, needle, len, lneedle));
}

static char	*ft_comparsion(const char *s1, const char *s2,
							size_t len, size_t ls2)
{
	while (len > 0)
	{
		if (*s1 == *s2)
		{
			if (len < ls2)
				return (NULL);
			else if (!ft_strncmp(s1, s2, ls2))
				return ((char *)s1);
		}
		s1++;
		len--;
	}	
	return (NULL);
}
