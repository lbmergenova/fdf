/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfearow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:54:00 by sfearow           #+#    #+#             */
/*   Updated: 2021/08/25 16:54:28 by sfearow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*d_lst;

	while (*lst)
	{
		d_lst = *lst;
		*lst = (*lst)->next;
		(*del)(d_lst->content);
		free(d_lst);
	}
	lst = NULL;
}
