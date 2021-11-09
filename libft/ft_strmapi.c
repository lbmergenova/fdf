/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:01:20 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 23:01:22 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			ls;
	char			*ret;

	i = 0;
	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	ret = malloc((ls + 1) * sizeof(char));
	if (ret)
	{
		while (i < ls)
		{
			ret[i] = (*f)(i, *s);
			s++;
			i++;
		}
		ret[ls] = '\0';
		return (ret);
	}
	else
		return (NULL);
}
