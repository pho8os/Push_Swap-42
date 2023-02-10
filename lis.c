/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:23 by absaid            #+#    #+#             */
/*   Updated: 2023/02/10 20:42:49 by absaid           ###   ########.fr       */
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
	while(size-- >= 0)
	{
		tmp = start;
		while(tmp != node)
		{
			// 3 2 1 4 5 6
			// printf("tmp = %d lis = %d | node = %d lis = %d \n", tmp->num, tmp->lis, node->num, node->lis);
			if(tmp->num < node->num && tmp->lis >= node->lis)
			{
				node->address = tmp;
				node->lis++;
			}
			tmp = tmp->next;
			if(!tmp)
				tmp = stack;
		}
		node = node->next;
		if(!node)
			node = stack;
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
int main(int ac, char **av)
{
	(void)ac;
	t_list *head = parser(av + 1);
	t_list *tmp;
	add_lis(head);
	while(head)
	{
		
		printf("num = %d | lis : %d\n",head->num, head->lis);
		if(head->address)
		{
			tmp = head->address;
			printf("%d\n",tmp->num);
		}
		head = head->next;
	}
	
}