/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:47:21 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 18:48:00 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

void	*mm_free(t_memory_manager *instance, void *address)
{
	t_mm_node	*node;

	if (!instance || !address)
		return (NULL);
	node = mm_get_node_from_address(instance, address);
	if (!node)
		return (NULL);
	free(node->allocation);
	mm_delete_node(instance, node);
	return (NULL);
}

void	*mm_alloc(t_memory_manager *instance, uint64_t size)
{
	t_mm_node	*node;

	node = mm_create_push_node(instance);
	if (!node)
	{
		if (instance->exit_on_fail)
			mm_fast_exit(instance);
		return (NULL);
	}
	node->allocation = malloc(size);
	if (!node->allocation)
	{
		if (instance->exit_on_fail)
			mm_fast_exit(instance);
		return (NULL);
	}
	return (node->allocation);
}

void	*mm_calloc(t_memory_manager *instance, uint64_t size)
{
	void	*alloc;

	alloc = mm_alloc(instance, size);
	if (alloc)
		mm_bzero(alloc, size);
	return (alloc);
}

void	*mm_register_alloc(t_memory_manager *instance, void *address)
{
	t_mm_node	*node;

	if (!address || !instance)
		return (NULL);
	node = mm_create_push_node(instance);
	if (!node)
	{
		if (instance->exit_on_fail)
			mm_fast_exit(instance);
		return (NULL);
	}
	node->allocation = address;
	return (node->allocation);
}

void	*mm_unregister_alloc(t_memory_manager *instance, void *address)
{
	t_mm_node	*node;

	if (!instance || !address)
		return (NULL);
	node = mm_get_node_from_address(instance, address);
	if (!node)
		return (NULL);
	mm_delete_node(instance, node);
	return (NULL);
}
