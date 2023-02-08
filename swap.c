/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:43:34 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 04:26:44 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void swap(t_list **stack) 
{
	int tmp;
	
	if(!*stack || !(*stack)->next || !stack)
		gc(0, 0);
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	//TODO : if i will use indexs i must swap em to.
}

void sa(t_list **stack)
{
	swap(stack);
	ft_putendl_fd("sa",1);
}

void sb(t_list **stack)
{
	swap(stack);
	ft_putendl_fd("sb",1);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss",1);
}