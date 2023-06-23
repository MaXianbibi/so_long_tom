/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:59 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:20:56 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

// Function called to clean up. is not 
// called internally therefore doesnt callback
void	mm_exit(t_memory_manager *instance)
{
	t_mm_node	*current_node;
	void		*address;

	current_node = instance->alloc_list;
	while (current_node)
	{
		address = current_node->allocation;
		current_node = current_node->next;
		mm_free(instance, address);
	}
	free(instance);
	exit(EXIT_SUCCESS);
}

// Function called when a malloc or any other error fails
void	mm_fast_exit(t_memory_manager *instance)
{
	t_mm_node	*current_node;
	void		*address;

	instance->exit_callback(instance->callback_param);
	current_node = instance->alloc_list;
	while (current_node)
	{
		address = current_node->allocation;
		current_node = current_node->next;
		mm_free(instance, address);
	}
	free(instance);
	exit(EXIT_FAILURE);
}
