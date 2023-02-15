/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:58:00 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 21:04:01 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void push_1(t_list **stack_a, t_list **stack_b, t_list *node)
{
	while(node->keep && node->address->keep)
	{
		rr(stack_a, stack_b, 1);
		node->address->keep--;
		node->keep--;
	}
	while(node->keep)
	{	
		rb(stack_b, 1);
		node->keep--;
	}
	while(node->address->keep)
	{	
		ra(stack_a, 1);
		node->address->keep--;
	}
	pa(stack_b, stack_a, 1);
}

void push_2(t_list **stack_a, t_list **stack_b, t_list *node)
{
	while(node->keep && node->address->keep)
	{
		rrr(stack_a, stack_b, 1);
		node->address->keep++;
		node->keep++;
	}
	while(node->keep)
	{	
		rrb(stack_b, 1);
		node->keep++;
	}
	while(node->address->keep)
	{
		rra(stack_a, 1);
		node->address->keep++;	
	}
	pa(stack_b, stack_a, 1);
}

void push_3(t_list **stack_a, t_list **stack_b, t_list *node)
{
	while(node->address->keep)
	{	
		ra(stack_a, 1);
		node->address->keep--;
	}
	while(node->keep)
	{	
		rrb(stack_b, 1);
		node->keep++;
	}
	pa(stack_b, stack_a, 1);
}

void push_4(t_list **stack_a, t_list **stack_b, t_list *node)
{
	while(node->address->keep)
	{	
		rra(stack_a, 1);
		node->address->keep++;
	}
	while(node->keep)
	{	
		rb(stack_b, 1);
		node->keep--;
	}
	pa(stack_b, stack_a, 1);
}

t_list *nodecor(t_list *stack, t_list *node)
{
	t_list *top;
	t_list *tmp;

	tmp = stack;
	top = getmin(stack);
	while(tmp)
	{
		if(tmp->num > node->num)
		{
			top = tmp;
			break;
		}
		tmp = tmp->next;
	}
	while(stack)
	{
		if(stack->num > node->num && stack->num < top->num)
			top = stack;
		stack = stack->next;
	}
	return top;
}