/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:02:33 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:02:35 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sbegin(char *sbegin, char const *s1, char const *set);
static char	*ft_send(char *send, char *sbegin, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sbegin;
	char	*send;

	if (!s1)
		return (NULL);
	sbegin = NULL;
	send = (char *)s1 + ft_strlen(s1);
	sbegin = ft_sbegin(sbegin, s1, set);
	if (sbegin == NULL)
		return ((char *)ft_calloc(1, sizeof(char)));
	else
	{
		send = ft_send(send, sbegin, set);
		return (ft_substr(sbegin, 0, send - sbegin + 1));
	}
}

static char	*ft_sbegin(char *sbegin, char const *s1, char const *set)
{
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
		{
			sbegin = (char *)s1;
			break ;
		}
		s1++;
	}
	return (sbegin);
}

static char	*ft_send(char *send, char *sbegin, char const *set)
{
	while (send >= sbegin)
	{
		if (!ft_strchr(set, *send))
		{
			break ;
		}
		send--;
	}
	return (send);
}
