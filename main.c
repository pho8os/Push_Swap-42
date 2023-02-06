/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/06 20:31:24 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if(ac > 2)
	{
		t_list *stack_a;
		stack_a = parser(av + 1);
		while(stack_a)
		{
			printf("%d\n", stack_a->num);
			stack_a = stack_a->next;
		}
	}
}