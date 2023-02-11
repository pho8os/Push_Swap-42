/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:19:41 by absaid            #+#    #+#             */
/*   Updated: 2023/02/11 03:21:10 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrotate(t_list **stack)
{
	t_list *tmp;
	t_list *tmp2;
	
	if(!*stack || !(*stack)->next)
		return ;
	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while(tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(stack, tmp);
}

void rra(t_list **stack)
{
	rrotate(stack);
	ft_putendl_fd("rra",1);
}

void rrb(t_list **stack)
{
	rrotate(stack);
	ft_putendl_fd("rrb",1);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_putendl_fd("rrr",1);
}
