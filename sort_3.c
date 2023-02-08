/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:14:27 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 00:16:14 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **s)
{
	if((*s)->num > (*s)->next->num && (*s)->next->num < (*s)->next->next->num)
	{
		swap(s);
		write(1, "sa\n", 3);
	}
	if((*s)->num > (*s)->next->num && (*s)->next->num > (*s)->next->next->num)
	{
		swap(s);
		rrotate(s);
		write(1, "sa\nrra\n", 7);
	}
}