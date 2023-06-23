/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:38 by tparadis          #+#    #+#             */
/*   Updated: 2022/11/07 16:14:05 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*ret;
	t_list	*i;

	if (!lst || !f || !del)
		return (NULL);
	current = lst;
	ret = NULL;
	while (current)
	{
		if (!ret)
		{
			ret = malloc(sizeof(t_list));
			i = ret;
		}
		else
		{
			ret->next = malloc(sizeof(t_list));
			ret = ret->next;
		}
		ret->content = f(current->content);
		ret->next = NULL;
		current = current->next;
	}
	return (i);
}
