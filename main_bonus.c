/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:46 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 16:09:32 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void execfunc2(t_func *list, t_list **stack_a, t_list **stack_b)
{
	if(ft_strncmp(list->func, "sa\n", 3))
		sa(stack_a);
	else if(ft_strncmp(list->func, "sb\n", 3))
		sb(stack_b);
	else if(ft_strncmp(list->func, "ss\n", 3))
		ss(stack_a, stack_b);
	else if(ft_strncmp(list->func, "ra\n", 3))
		ra(stack_a);
	else if(ft_strncmp(list->func, "rb\n", 3))
		rb(stack_b);
}
void execfunc(t_func *list, t_list **stack_a, t_list **stack_b)
{
	while (list)
	{
		execfunc2(list, stack_a, stack_b);
		if(ft_strncmp(list->func, "rr\n", 3))
			rr(stack_a, stack_b);
		else if(ft_strncmp(list->func, "rra\n", 4))
			rra(stack_a);
		else if(ft_strncmp(list->func, "rrb\n", 4))
			rrb(stack_b);
		else if(ft_strncmp(list->func, "rrr\n", 4))
			rrr(stack_a, stack_b);
		else if(ft_strncmp(list->func, "pa\n", 3))
			pa(stack_b, stack_a);
		else if(ft_strncmp(list->func, "pb\n", 3))
			pb(stack_a, stack_b);
		list = list->next;
	}
}

t_func *readfunc()
{
	char *line;
	t_func *list;
	t_func *tmp;

	list = NULL;
	tmp = list;
	line = get_next_line(0);
	while(line)
	{
		tmp = gc(sizeof(t_func),1);
		tmp->func = line;
		line = get_next_line(0);
		tmp = tmp->next;
	}
	if(tmp)
		tmp->next = NULL;
	return(list);
}
int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	t_func *func;
	
	stack_b = NULL;
	if(ac > 1)
	{
		stack_a = parser(av + 1);
		func = readfunc();
		execfunc(func, &stack_a, &stack_a);
		if(ft_sort(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}