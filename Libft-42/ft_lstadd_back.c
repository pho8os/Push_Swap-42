/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:24:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 21:34:01 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->num == new->num)
		{
			write(2, "Error\n", 6);
			gc(0, 0);
		}
		tmp = tmp -> next;
	}
	if (tmp->num == new->num)
	{
		write(2, "Error\n", 6);
		gc(0, 0);
	}
	tmp->next = new;
}
