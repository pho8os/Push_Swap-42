/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 05:31:52 by absaid            #+#    #+#             */
/*   Updated: 2023/02/11 06:15:34 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_place(t_list *stack_a, t_list *stack_b)
{
	int moves;
	
	while(stack_b)
	{
		get_pmin_place(stack_a, stack_b);
		stack_b = stack_b->next;
	}

	
}

void sorting(t_list **stack_a , t_list **stack_b)
{
	
}