/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:26:06 by absaid            #+#    #+#             */
/*   Updated: 2023/02/15 23:02:21 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	chartoint(char *str)
{
	int	ret;
	int	i;

	i = -1;
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (write(2, "Error\n", 6), gc(0, 0), 0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (write(2, "Error\n", 6), gc(0, 0), 0);
	ret = ft_atoi(str);
	return (ret);
}

t_list	*chartolist(char **args)
{
	t_list	*head;
	int		i;

	head = NULL;
	i = -1;
	while (args[++i])
		ft_lstadd_back(&head, ft_lstnew(chartoint(args[i]), 0));
	return (head);
}

void	checkspace(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		while (args[i][j] && args[i][j] == 32)
			j++;
		if (args[i][j] == 0)
		{
			write(2, "Error\n", 6);
			gc(0, 0);
		}
	}
}

t_list	*parser(char **args)
{
	char	*str;
	int		i;
	t_list	*list;

	str = NULL;
	checkspace(args);
	i = -1;
	while (args[++i])
		str = ft_strjoin(str, args[i]);
	list = chartolist(ft_split(str, ' '));
	return (list);
}
