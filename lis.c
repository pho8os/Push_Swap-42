/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:23 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 19:46:10 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	justnorme(t_list *tmp ,t_list *node, t_list **maxlis, t_list *stack)
{
	while (tmp != node)
	{
		if (tmp->num < node->num && tmp->lis >= node->lis)
		{
			node->address = tmp;
			node->lis++;
					
		}
		if (node->lis > tmp->lis)
			*maxlis = node;
		else
			*maxlis = tmp;
		tmp = tmp->next;
		if (!tmp)
			tmp = stack;
	}
}

void	get_lis(t_list *stack, t_list *start, t_list **maxlis)
{
	t_list	*tmp;
	t_list	*node;
	int		size;
	
	size = ft_lstsize(stack);
	tmp = stack;
	node = start;
	while (size-- >= 0)
	{
		tmp = start;
		justnorme(tmp, node, maxlis, stack);
		node = node->next;
		if (!node)
			node = stack;
	}
}

void	getting_lis(t_list *stack, int *numlis)
{
	int		size;
	t_list	*tmp;
	t_list	*maxlis;

	size = -1;
	tmp = stack;
	while (tmp)
	{
		tmp->keep = 0;
		tmp->lis = 0;
		tmp = tmp->next;	
	}
	tmp = stack;
	while (++size < getpmin(stack))
		tmp = tmp->next;	
	get_lis(stack, tmp, &maxlis);
	while (maxlis)
	{
		(*numlis)++;
		maxlis->keep = 1;
		maxlis = maxlis->address;
	}
}

void	push_lis(t_list **stack_a, t_list **stack_b)
{
	int size;
	int lstsize;

	size = 0;
	getting_lis(*stack_a, &size);
	lstsize = ft_lstsize(*stack_a) - size;
	while (lstsize)
	{
		if (!((*stack_a)->keep == 1))
		{
			pb(stack_a, stack_b, 1);
			lstsize--;
		}
		else
			ra(stack_a, 1);
	}
	while (ft_lstsize(*stack_b))
		sorting(stack_a, stack_b);
	if (getpmin(*stack_a) <= ft_lstsize(*stack_a) / 2)
		while (getpmin(*stack_a))
			ra(stack_a, 1);
	if (getpmin(*stack_a) > ft_lstsize(*stack_a) / 2)
		while (getpmin(*stack_a))
			rra(stack_a, 1);
}
