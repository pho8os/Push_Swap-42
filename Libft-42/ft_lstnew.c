/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:51 by absaid            #+#    #+#             */
/*   Updated: 2023/02/04 16:26:23 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(int num, void *address)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof (t_list));
	if (!node)
		return (NULL);
	node -> address = address;
	node -> num = num;
	node -> next = NULL;
	return (node);
}
