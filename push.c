/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:45:26 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 04:31:26 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **src , t_list **dst)
{
	if(!*src || !src)
		return ;
	t_list *tmp;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, tmp);
}

void pa(t_list **src , t_list **dst)
{
	push(src, dst);
	ft_putendl_fd("pa", 1);
}

void pb(t_list **src , t_list **dst)
{
	push(src, dst);
	ft_putendl_fd("pb", 1);
}