/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:51:41 by absaid            #+#    #+#             */
/*   Updated: 2023/02/07 23:00:03 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
bool ft_sort(t_list *stack)
{
	
	while(stack->next)
	{
		if(stack->num < stack->next->num)
			stack = stack->next;
		else
			return (false);
	}
	return (true);
}