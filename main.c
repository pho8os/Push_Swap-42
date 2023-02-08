/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 00:36:54 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void check()
{
	system("leaks a.out");
}
int main(int ac, char **av)
{
	// atexit(check);
	if(ac > 1)
	{
		t_list *stack_b = NULL;
		t_list *stack_a;
		stack_a = parser(av + 1);
		t_list *tmp;
		
		tmp = stack_a;
		printf("stack a\n");
		while(tmp)
		{
			
			printf("%d\n", tmp->num);
			tmp = tmp->next;
		}
		printf("---------------\n");
		tmp = stack_b;
		printf("stack b\n");
		while(tmp)
		{
			printf("%d\n", tmp->num);
			tmp = tmp->next;
		}
		if(!ft_sort(stack_a))
			sort_3(&stack_a);
		printf("---------------\n");
		printf("stack a\n");
		tmp  = stack_a;
		while(tmp)
		{
			printf("%d\n", tmp->num);
			tmp = tmp->next;
		}
		if(ft_sort(stack_a))
			printf("true\n");
		
	}
	gc(0, 0);
}
	