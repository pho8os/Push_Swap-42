/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:23:16 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 21:13:47 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include"Libft-42/libft.h"
# include <stdbool.h>

t_list	*parser(char **args);
bool	ft_sort(t_list *stack);
void	sort_3(t_list **s);
void	sort_5(t_list **sa, t_list **sb);
void	push(t_list **src , t_list **dst);
void	pa(t_list **src , t_list **dst, int flag);
void	pb(t_list **src , t_list **dst, int flag);
void	rrotate(t_list **stack);
void 	rra(t_list **stack, int flag);
void 	rrb(t_list **stack, int flag);
void 	rrr(t_list **stack_a, t_list **stack_b, int flag);
void 	rotate(t_list **stack);
void 	ra(t_list **stack, int flag);
void 	rb(t_list **stack, int flag);
void 	rr(t_list **stack_a, t_list **stack_b, int flag);
void 	swap(t_list **stack);
void 	sa(t_list **stack, int flag);
void 	sb(t_list **stack, int flag);
void 	ss(t_list **stack_a, t_list **stack_b, int flag);
int		getpmin(t_list *stack);
void 	push_lis(t_list **stack_a, t_list **stack_b);
void 	sorting(t_list **stack_a, t_list **stack_b);
void 	getmoves(t_list *stack_a, t_list *stack_b);
void	push_1(t_list **stack_a, t_list **stack_b, t_list *node);
void	push_2(t_list **stack_a, t_list **stack_b, t_list *node);
void	push_3(t_list **stack_a, t_list **stack_b, t_list *node);
void	push_4(t_list **stack_a, t_list **stack_b, t_list *node);
t_list *nodecor(t_list *stack, t_list *node);
t_list *getmin(t_list *sa);

#endif