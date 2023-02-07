/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:23:16 by absaid            #+#    #+#             */
/*   Updated: 2023/02/07 21:55:44 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include"Libft-42/libft.h"

t_list *parser(char **args);
void push(t_list **src , t_list **dst);
void rotate(t_list **stack);
void rrotate(t_list **stack);
void swap(t_list **stack);

#endif