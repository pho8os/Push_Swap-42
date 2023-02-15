/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 05:31:52 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 22:50:30 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getindex(t_list *stack)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(stack);
	j = 0;
	i = -1;
	while (++i <= size / 2 && stack)
	{
		stack->keep = i;
		stack = stack->next;
	}
	j = size / 2;
	if (size % 2 == 0)
		j--;
	while (stack)
	{
		stack->keep = -j;
		j--;
		stack = stack->next;
	}
}

t_list	*getmin(t_list *sa)
{
	t_list	*min;

	min = sa;
	while (sa)
	{
		if (sa->num < min->num)
			min = sa;
		sa = sa->next;
	}
	return (min);
}

void	getmoves(t_list *stack_a, t_list *stack_b)
{	
	t_list	*tmp;
	int		pob;
	int		poa;

	getindex(stack_a);
	getindex(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		tmp->address = nodecor(stack_a, tmp);
		poa = tmp->address->keep;
		pob = tmp->keep;
		if (poa < 0 && pob < 0)
			tmp->lis = ((poa < pob) * poa + (pob * !(poa < pob))) * -1;
		else if (poa >= 0 && pob >= 0)
			tmp->lis = (poa >= pob) * poa + (pob * !(poa >= pob));
		else if (poa >= 0 && pob < 0)
			tmp->lis = (pob * -1) + poa;
		else if (poa < 0 && pob >= 0)
			tmp->lis = (poa * -1) + pob;
		tmp = tmp->next;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if (node->address->keep >= 0 && node->keep >= 0)
		push_1(stack_a, stack_b, node);
	else if (node->address->keep < 0 && node->keep < 0)
		push_2(stack_a, stack_b, node);
	else if (node->address->keep >= 0 && node->keep < 0)
		push_3(stack_a, stack_b, node);
	else if (node->address->keep < 0 && node->keep >= 0)
		push_4(stack_a, stack_b, node);
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*node;
	int		moves;

	getmoves(*stack_a, *stack_b);
	tmp = *stack_b;
	moves = tmp->lis;
	node = tmp;
	while (tmp)
	{
		if (moves > tmp->lis)
		{
			moves = tmp->lis;
			node = tmp;
		}
		tmp = tmp->next;
	}
	push_b(stack_a, stack_b, node);
}
