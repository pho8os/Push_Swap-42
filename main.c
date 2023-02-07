/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:22:58 by absaid            #+#    #+#             */
/*   Updated: 2023/02/07 21:57:35 by absaid           ###   ########.fr       */
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
		
		swap(&stack_a);
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
		
	}
	gc(0, 0);
}
	