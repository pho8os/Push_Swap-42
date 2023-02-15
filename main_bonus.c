/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:46 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 23:03:45 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	execfunc2(char *func, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(func, "sa"))
		sa(stack_a, 0);
	else if (!ft_strncmp(func, "rra"))
		rra(stack_a, 0);
	else if (!ft_strncmp(func, "sb"))
		sb(stack_b, 0);
	else if (!ft_strncmp(func, "ss"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(func, "ra"))
		ra(stack_a, 0);
	else if (!ft_strncmp(func, "rb"))
		rb(stack_b, 0);
}

void	execfunc(char *func, t_list **stack_a, t_list **stack_b)
{
	execfunc2(func, stack_a, stack_b);
	if (!ft_strncmp(func, "rr"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(func, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strncmp(func, "rrr"))
		rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(func, "pa"))
		pa(stack_b, stack_a, 0);
	else if (!ft_strncmp(func, "pb"))
		pb(stack_a, stack_b, 0);
	else
	{
		write(2, "Error\n", 6);
		gc(0, 0);
	}
}

void	readfunc(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execfunc(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = parser(av + 1);
		readfunc(&stack_a, &stack_b);
		if (ft_sort(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	gc(0, 5);
}
