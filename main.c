/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 23:04:18 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = NULL;
		stack_a = parser(av + 1);
		if (!ft_sort(stack_a))
		{
			if (ft_lstsize(stack_a) <= 3)
				sort_3(&stack_a);
			else if (ft_lstsize(stack_a) <= 5)
				sort_5(&stack_a, &stack_b);
			else if (ft_lstsize(stack_a) > 5)
				push_lis(&stack_a, &stack_b);
		}
	}
	gc(0, 5);
}
