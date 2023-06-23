/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:53:15 by tparadis          #+#    #+#             */
/*   Updated: 2022/11/16 20:46:00 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*current;

	if (!lst || !newlst)
		return ;
	if (!*lst)
		*lst = newlst;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = newlst;
	}
}
