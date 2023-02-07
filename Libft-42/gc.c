/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:01:33 by absaid            #+#    #+#             */
/*   Updated: 2023/02/07 13:32:32 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*gc(size_t size, int param)
{
	static t_list	*head;
	void			*address;
	t_list			*node;

	if (param)
	{
		address = malloc(size);
		if (!address)
			return (ft_lstclear(&head, free), exit(1), NULL);
		node = malloc(sizeof(t_list));
		node->address = address;
		node->next = NULL;
		if (!node)
			return (ft_lstclear(&head, free), exit(1), NULL);
		ft_lstadd_front(&head, node);
		return (address);
	}
	ft_lstclear(&head, free);
	return (exit(1), NULL);
}
