/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:14:27 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 17:34:52 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int get_max(t_list *stack)
{
	int max;

	max = stack->num;
	while(stack)
	{
		if(stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return(max);
}

void sort_3(t_list **s)
{
	int max;

	max = get_max(*s);
	if(ft_lstsize(*s) == 3)
	{
		if((*s)->num == max)
			ra(s, 1);
		else if((*s)->next->num == max)
			rra(s, 1);
	}
	if((*s)->num > (*s)->next->num)
		sa(s, 1);
}