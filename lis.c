/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:23 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 14:14:16 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void clearkeep(t_list *stack)
{
	while (stack)
	{
		stack->keep = 0;
		stack->lis = 0;
		stack = stack->next;	
	}
}

int getkeepval(t_list *stack, t_list *node)
{
	int lis;
	int max;
	int size;
	
	size = ft_lstsize(stack);
	clearkeep(stack);
	lis = 0;
	max = node->num;
	while(size--)
	{
		if(node->num > max)
		{
			max = node->num;
			node->keep = 1;
			lis++;
		}
		if(node->next)
			node = node->next;
		else
			node = stack;
	}
	return (lis);
}
int get_lis_(t_list *stack)
{
	t_list *tmp;
	t_list *headkeep;
	int lis;
	int top;
	
	headkeep = stack;
	top = 0;
	tmp = stack;
	while(tmp)
	{
	 	lis = getkeepval(stack, tmp);
		if (lis > top || ((lis == top) && headkeep->num < tmp->num))
		{
			headkeep = tmp;
			top = lis;
		}
		tmp = tmp->next;
	}
	getkeepval(stack, headkeep);
	return(top);
}

void	push_lis(t_list **stack_a, t_list **stack_b)
{
	int size;
	int lstsize;
	size = 0;
	
	size = get_lis_(*stack_a);
	lstsize = ft_lstsize(*stack_a) - size;
	while(lstsize)
	{
		if(!((*stack_a)->keep == 1))
		{
			pb(stack_a, stack_b);
			lstsize--;
		}
		else
			ra(stack_a);
	}
	while((ft_lstsize(*stack_b)))
		sorting(stack_a, stack_b);
	if(getpmin(*stack_a) <= ft_lstsize(*stack_a) / 2)
		while(getpmin(*stack_a))
			ra(stack_a);
	if(getpmin(*stack_a) > ft_lstsize(*stack_a) / 2)
		while(getpmin(*stack_a))
			rra(stack_a);
}
