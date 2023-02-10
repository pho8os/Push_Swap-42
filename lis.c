/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:23 by absaid            #+#    #+#             */
/*   Updated: 2023/02/10 19:50:45 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
static void get_lis(t_list *stack, t_list *start)
{
	t_list *tmp;
	t_list *node;
	int size;
	
	size = ft_lstsize(stack);
	tmp = stack;
	while(tmp)
	{
		tmp->lis = 0;
		tmp = tmp->next;	
	}
	node = start;
	while(size--)
	{
		if(node != start)
		{
			tmp = start;
			while(tmp != node)
			{
				if(tmp < node)
					node->lis++;
				tmp = tmp->next;
				if(!tmp)
					tmp = stack;
			}
		}
		node = node->next;
		if(!node)
			node = start;
	}
}
void add_lis(t_list *stack)
{
	int size;
	t_list *tmp;

	if(!stack || !stack->next)
		gc(0,2);
	size = -1;
	tmp = stack;
	while(++size < getpmin(stack))
		tmp = tmp->next;
	get_lis(stack, tmp);
}
int main()
{
	t_list *head;
	head = ft_lstnew(2,0);
	head->next = ft_lstnew(1,0);
	head->next->next = ft_lstnew(3,0);
	head->next->next->next = ft_lstnew(4,0);
	head->next->next->next->next = ft_lstnew(5,0);
	head->next->next->next->next->next = ft_lstnew(6,0);
	head->next->next->next->next->next->next = NULL;
	add_lis(head);
	while(head)
	{
		printf("lis : %d\n",head->lis);
		head = head->next;
	}
	
}