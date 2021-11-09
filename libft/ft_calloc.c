/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:53:30 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:53:32 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	a = (void *)malloc(nmemb * size);
	if (!a)
		return (NULL);
	ft_bzero(a, nmemb * size);
	return (a);
}
