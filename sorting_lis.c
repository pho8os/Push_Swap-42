/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 05:31:52 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 19:46:43 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void getindex(t_list *stack)
{
	int i = -1;
	int j = 0;
	int size = ft_lstsize(stack);
	while(++i <= size / 2 && stack)
	{
		stack->keep = i;
		stack = stack->next;
	}
	j = size / 2;
	if (size % 2 == 0)
		j--;
	while(stack)
	{
		stack->keep = -j;
		j--;
		stack = stack->next;
	}
}

t_list *getmin(t_list *sa)
{
	t_list *min;

	min = sa;
	while(sa)
	{
		if(sa->num < min->num)
			min = sa;
		sa = sa->next;
	}
	return(min);
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
void getmoves(t_list *stack_a, t_list *stack_b)
{	
	t_list *tmp;
	int sa;
	int sb;
	
	sb = ft_lstsize(stack_b);
	sa = ft_lstsize(stack_a);
	getindex(stack_a);
	getindex(stack_b);
	tmp = stack_b;
	while(tmp)
	{
		tmp->address = nodecor(stack_a, tmp);
		int poa = tmp->address->keep;
		int pob = tmp->keep;

		if(poa < 0 && pob < 0)
			tmp->lis = ((poa < pob) * poa + (pob * !(poa < pob))) * -1;
		else if(poa >= 0 && pob >= 0)
			tmp->lis = (poa >= pob) * poa + (pob * !(poa >= pob));
		else if(poa >= 0 && pob < 0)
			tmp->lis = (pob * -1) + poa;
		else if(poa < 0 && pob >= 0)
			tmp->lis = (poa * -1) + pob;	
		tmp = tmp->next;
	}
}

void push_b(t_list **stack_a, t_list **stack_b, t_list *node)
{

	if(node->address->keep >= 0 && node->keep >= 0)
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
	else if(node->address->keep < 0 && node->keep < 0)
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
	else if (node->address->keep >= 0 && node->keep < 0)
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
	else if (node->address->keep < 0 && node->keep >= 0)
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

}

void sorting(t_list **stack_a, t_list **stack_b)
 {
	t_list *tmp;
	t_list *node;
	int moves;

	getmoves(*stack_a, *stack_b);
	tmp = *stack_b;
	moves = tmp->lis;
	node = tmp;
	while(tmp)
	{
		if(moves > tmp->lis)
		{
			moves = tmp->lis;
			node  = tmp;
		}
		tmp = tmp->next;
	}
	push_b(stack_a, stack_b, node);	
 }
