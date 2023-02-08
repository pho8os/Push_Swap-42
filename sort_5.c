/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:45:50 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 23:02:38 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int getpmin(t_list *stack)
{
	int min;
	int pos;
	int l;
	
	l = 0;
	pos = 0;
	min = stack->num;
	while(stack)
	{
		if(stack->num < min)
		{
			pos = l;
			min = stack->num;
		}
		l++;
		stack = stack->next;
	}
	return(pos);
}
void sort_5(t_list **sa, t_list **sb)
{
	int pmin;

	pmin = getpmin(*sa);
	while(ft_lstsize(*sa) > 3)
	{
		if(ft_sort(*sa) && !*sb)
			return ;
		if(pmin > 2 && pmin)
			rra(sa);
		else if(pmin <= 2 && pmin)
			ra(sa);
		else if(!pmin)
			pb(sa, sb);
		pmin = getpmin(*sa);
	}
	sort_3(sa);
	while(*sb)
		pa(sb, sa);
}
