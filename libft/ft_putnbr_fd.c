/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:59:02 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/12 22:59:04 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_dit(long	int lnb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_;

	n_ = n;
	if (n_ == 0)
		write(fd, "0", 1);
	else
	{
		if (n_ < 0)
		{
			n_ = -n_;
			write(fd, "-", 1);
		}
		print_dit(n_, fd);
	}
}

static void	print_dit(long	int n, int fd)
{
	int		ten;
	int		dit;
	int		mtk;
	char	c;

	c = '0';
	mtk = 0;
	ten = 1000000000;
	while (!(ten == 1))
	{
		dit = n / ten;
		if ((dit > 0) || (mtk > 0))
		{
			ft_putchar_fd(c + dit, fd);
			mtk = 1;
		}
		n = n % ten;
		ten = ten / 10;
	}
	ft_putchar_fd(c + n, fd);
}
