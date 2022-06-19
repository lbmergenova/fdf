/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:56:03 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:56:05 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr_s(char *s, long int n, int dsize);
static int	ft_digit_size(long int n);

char	*ft_itoa(int n)
{
	int			dsize;
	long int	n_;
	char		*str;

	n_ = n;
	dsize = ft_digit_size(n_);
	str = (char *)malloc((dsize + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n_ < 0)
	{
		n_ = -n_;
		*str = '-';
		ft_putnbr_s(str + 1, n_, dsize - 1);
	}
	else
		ft_putnbr_s(str, n_, dsize);
	return (str);
}

static int	ft_digit_size(long int n)
{
	int	dsize;

	dsize = 0;
	if (n <= 0)
	{
		n = -n;
		dsize++;
	}
	while (n > 0)
	{
		n = n / 10;
		dsize++;
	}
	return (dsize);
}

static char	*ft_putnbr_s(char *s, long int n, int dsize)
{
	s[dsize] = '\0';
	while (dsize > 0)
	{
		s[--dsize] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}
