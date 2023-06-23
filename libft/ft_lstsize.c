/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:54:19 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/26 16:52:14 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lt)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!lt)
		return (0);
	current = lt;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
