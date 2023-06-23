/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:05:21 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 15:56:11 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*last;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		last = current;
		del(current->content);
		current = current->next;
		free(last);
	}
	*lst = NULL;
}
