/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 04:57:17 by absaid           ###   ########.fr       */
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
		if(ft_lstsize(stack_a) <= 3)
			sort_3(&stack_a);
		else if(ft_lstsize(stack_a) <= 5)
			sort_5(&stack_a, &stack_b);
		
	}
	gc(0, 0);
}
	