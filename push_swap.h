/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:23:16 by absaid            #+#    #+#             */
/*   Updated: 2023/02/11 03:12:31 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include"Libft-42/libft.h"
# include <stdbool.h>

t_list *parser(char **args);
bool ft_sort(t_list *stack);
void sort_3(t_list **s);
void sort_5(t_list **sa, t_list **sb);
void push(t_list **src , t_list **dst);
void pa(t_list **src , t_list **dst);
void pb(t_list **src , t_list **dst);
void rrotate(t_list **stack);
void rra(t_list **stack);
void rrb(t_list **stack);
void rrr(t_list **stack_a, t_list **stack_b);
void rotate(t_list **stack);
void ra(t_list **stack);
void rb(t_list **stack);
void rr(t_list **stack_a, t_list **stack_b);
void swap(t_list **stack);
void sa(t_list **stack);
void sb(t_list **stack);
void ss(t_list **stack_a, t_list **stack_b);
int getpmin(t_list *stack);
void	push_b_lis(t_list **stack_a, t_list **stack_b);
void printstack(t_list *stack, char *name); //TODO : 7aydha

#endif