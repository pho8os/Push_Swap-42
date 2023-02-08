/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:14:27 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 04:36:10 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void getpose(t_list *list,int *min, int *max)
{
	int i;
	int j;
	int l;
	
	l = 0;
	i = list->num;
	j = list->num;
	*min = 0;
	*max = 0;
	while(list)
	{
		if(list->num > i)
		{
			*max = l;	
			i = list->num;
		}	
		if(list->num < j)
		{
			*min = l;	
			j = list->num;
		}
		l++;
		list = list->next;
	}
}

void sort_3(t_list **s)
{
	int pmin;
	int pmax;

	getpose(*s, &pmin, &pmax);
	if((pmin == 1 && pmax == 2) || ft_lstsize(*s) == 2)
		sa(s);
	if(pmin == 2 && pmax ==0)
	{
		sa(s);
		rra(s);
	}
	if(pmin == 1 && pmax == 0)
		ra(s);
	if(pmin == 0 && pmax == 1)
	{
		sa(s);
		ra(s);
	}
	if(pmin == 2 && pmax == 1)
		rra(s);
}