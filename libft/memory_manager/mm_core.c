/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:47:16 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:19:37 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

t_memory_manager	*mm_initialize(bool exit_on_fail)
{
	t_memory_manager	*instance;

	instance = malloc(sizeof(t_memory_manager));
	if (!instance)
		return (NULL);
	instance->exit_on_fail = exit_on_fail;
	instance->alloc_list = NULL;
	return (instance);
}

void	mm_register_callback(t_memory_manager *instance,
		void (*callback_func)(void *), void *param)
{
	instance->callback_param = param;
	instance->exit_callback = callback_func;
}
