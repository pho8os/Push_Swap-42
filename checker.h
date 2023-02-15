/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:05:46 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 16:08:37 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"

typedef struct s_func
{
	char *func;
	struct s_func *next;
} t_func;

t_list *parser(char **args);

#endif