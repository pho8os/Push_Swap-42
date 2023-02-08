/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:45:50 by absaid            #+#    #+#             */
/*   Updated: 2023/02/08 05:17:31 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5(t_list **sa, t_list **sb)
{
	int pmin;
	getpose(*sa, &pmin, NULL);
	while(ft_lstsize(*sa) > 3)
	{
		if(pmin > (ft_lstsize(*sa) / 2) && pmin)
			rra(sa);
		else if(pmin <= (ft_lstsize(*sa) / 2) && pmin)
			ra(sa);
		else if(!pmin)	
			pb(sa, sb);
		getpose(*sa, &pmin, NULL);
	}
	sort_3(sa);
	while(*sb)
		pa(sb, sa);
}
