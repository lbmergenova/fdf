/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:59:40 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:59:42 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_str(char *s, char c);
static char	*ft_sbegin(char *s, char c);
static char	*ft_send(char *s, char c);
static char	**ft_array(char **ars, char *send, char c, int n);

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**ars;

	if (!s)
		return (NULL);
	n = ft_nbr_str((char *)s, c);
	ars = (char **)malloc((n + 1) * sizeof(char *));
	if (ars)
		ars = ft_array(ars, (char *)s, c, n);
	return (ars);
}

static int	ft_nbr_str(char *send, char c)
{
	int		n;
	char	*sbegin;

	n = 0;
	while (*send)
	{
		sbegin = ft_sbegin(send, c);
		if (!*sbegin)
			return (n);
		send = ft_send(sbegin, c);
		n++;
	}
	return (n);
}

static char	*ft_sbegin(char *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static char	*ft_send(char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static char	**ft_array(char **ars, char *send, char c, int n)
{
	int		i;
	char	*sbegin;

	i = 0;
	while (i < n)
	{
		sbegin = ft_sbegin(send, c);
		send = ft_send(sbegin, c);
		*send = '\0';
		ars[i] = ft_strdup(sbegin);
		if (!ars[i])
		{
			while (i > 0)
				free(ars[--i]);
			free(ars);
			return (NULL);
		}
		if (i != n - 1)
			*send = c;
		i++;
	}
	ars[i] = NULL;
	return (ars);
}
