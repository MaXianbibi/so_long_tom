/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:49:02 by tparadis          #+#    #+#             */
/*   Updated: 2022/11/16 20:46:30 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	t_list	*current;

	if (!lst || !newlst)
		return ;
	current = *lst;
	*lst = newlst;
	newlst->next = current;
}
