/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:22 by absaid            #+#    #+#             */
/*   Updated: 2023/02/06 20:21:07 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*t;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		t = tmp;
		tmp = tmp->next;
		del(t -> address);
		free(t);
	}
	*lst = NULL;
}
