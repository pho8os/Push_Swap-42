/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/11 04:08:40 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void check()
{
	system("leaks push_swap");
}
void printstack(t_list *stack, char *name)
{
	
	printf("------------\n");
	printf("|%-10s|\n", name);
	printf("------------\n");
	while(stack != NULL)
	{
		printf("|%-10d|\n",stack->num);
		stack = stack->next;
	}
	printf("------------\n");
}
int main(int ac, char **av)
{
	// atexit(check);
	if(ac > 1)
	{
		t_list *stack_b = NULL;
		t_list *stack_a;
		stack_a = parser(av + 1);
		printstack(stack_a, "stack A");
		if(!ft_sort(stack_a))
		{
			if(ft_lstsize(stack_a) <= 3)
				sort_3(&stack_a);
			else if(ft_lstsize(stack_a) <= 5)
				sort_5(&stack_a, &stack_b);
			else if(ft_lstsize(stack_a) > 5)
				push_b_lis(&stack_a, &stack_b);
		}
		printstack(stack_a, "stack A");
		printstack(stack_b, "stack B");
		// if(!ft_sort(stack_a))
		// 	printf("false");
	}
	gc(0, 5);
}
	