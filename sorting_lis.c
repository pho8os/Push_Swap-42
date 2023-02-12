/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 05:31:52 by absaid            #+#    #+#             */
/*   Updated: 2023/02/12 23:04:06 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getpose(t_list *stack,t_list *node)
{
	int i = 0;
	while(stack)
	{
		if(stack->num == node->num)
			return(i);
		stack = stack->next;
		i++;
	}
	return (0);
}

void getmoves(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;
	t_list *ptr;
	t_list *bro;
	int sa;
	int pa;
	int sb;
	int pb;
	
	tmp = stack_b;
	while(tmp)
	{
		ptr = stack_a;
		while(ptr)
		{
			bro = ptr;
			if(tmp->num < ptr->num && ptr->num < bro->num)
				bro = ptr;
			ptr = ptr->next;
		}
		tmp->address = bro;
		pb = getpose(stack_b, tmp);
		sb = ft_lstsize(stack_b);
		pa = getpose(stack_a, bro);
		sa = ft_lstsize(stack_a);
		
		if(pa > (sa / 2) && pb > (sb / 2))
			tmp->lis = (sb - pb > sa - pa) * (sb - pb)
				+ ((sa - pa) * !(sb - pb > sa - pa));
		else if(pa < (sa / 2) && pb < (sb / 2))
			tmp->lis = (pb > pa) * pb + (pa * !(pb > pa));
		else
			tmp->lis = ((pa < sa / 2) * (pa + (sb - pb)))
				+ (!(pa < sa / 2) * (pb + (sa - pa))); 	
		tmp = tmp->next;
	}
}
void push_b(t_list **stack_a, t_list **stack_b, t_list *node)
{
	// t_list *tmp;
	
	int pb = getpose(*stack_b, node);
	int pa = getpose(*stack_a, node->address);
	int sa = ft_lstsize(*stack_a);
	int sb = ft_lstsize(*stack_b);
	
	
	if(pa > (sa / 2) && pb > (sb / 2))
	{
		while(getpose(*stack_b, node) && getpose(*stack_a, node->address))
			rrr(stack_a, stack_b);
		while(getpose(*stack_b, node))
			rrb(stack_b);
		while(getpose(*stack_a, node->address))
			rra(stack_a);
	}

	else if(pa < (sa / 2) && pb < (sb / 2))
	{
		while(getpose(*stack_b, node) && getpose(*stack_a, node->address))
			rr(stack_a, stack_b);
		while(getpose(*stack_b, node))
			rb(stack_b);
		while(getpose(*stack_a, node->address))
			ra(stack_a);
	}
	else if (pa < (sa / 2) && pb > (sb / 2))
	{
		while(getpose(*stack_a, node->address))
			ra(stack_a);
		while(getpose(*stack_b, node))
			rrb(stack_b);
	}
	else if (pa > (sa / 2) && pb < (sb / 2))
	{
		while(getpose(*stack_a, node->address))
			rra(stack_a);
		while(getpose(*stack_b, node))
			rb(stack_b);
	}
}
void sorting(t_list **stack_a, t_list **stack_b)
 {
	t_list *tmp;
	t_list *node;
	int moves;

	getmoves(*stack_a, *stack_b);
	tmp = *stack_b;
	moves = tmp->lis;
	while(tmp)
	{
		if(moves < tmp->lis)
		{
			moves = tmp->lis;
			node  = tmp;
		}
		tmp = tmp->next;
	}
	push_b(stack_a, stack_b, node);
 }