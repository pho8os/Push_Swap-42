/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:01:33 by absaid            #+#    #+#             */
/*   Updated: 2023/02/16 01:01:44 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*gc(size_t size, int param)
{
	static t_list	*head;
	void			*address;
	t_list			*node;

	if (param == 1)
	{
		address = malloc(size);
		if (!address)
			return (ft_lstclear(&head, free), exit(1), NULL);
		node = malloc(sizeof(t_list));
		if (!node)
			return (ft_lstclear(&head, free), exit(1), NULL);
		node->address = address;
		node->next = NULL;
		ft_lstadd_front(&head, node);
		return (address);
	}
	if (!param)
		return (ft_lstclear(&head, free), exit(1), NULL);
	return (ft_lstclear(&head, free), exit(0), NULL);
}
