/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:05:53 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 04:26:22 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **stack)
{
	t_list *tmp;

	if(!*stack || !stack || !(*stack)->next)
		gc(0, 0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void ra(t_list **stack)
{
	rotate(stack);
	ft_putendl_fd("ra",1);
}

void rb(t_list **stack)
{
	rotate(stack);
	ft_putendl_fd("rb",1);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr",1);
}