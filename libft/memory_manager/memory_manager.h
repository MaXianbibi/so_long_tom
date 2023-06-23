/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:15:58 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 18:46:26 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGER_H
# define MEMORY_MANAGER_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mm_node
{
	struct s_mm_node	*next;
	void				*allocation;
}						t_mm_node;

typedef struct s_memory_manager
{
	bool				exit_on_fail;
	t_mm_node			*alloc_list;
	void				(*exit_callback)(void *);
	void				*callback_param;
}						t_memory_manager;

void					mm_exit(t_memory_manager *instance);
t_mm_node				*mm_create_push_node(t_memory_manager *instance);
void					mm_delete_node(t_memory_manager *instance,
							t_mm_node *node);
t_mm_node				*mm_get_node_from_address(t_memory_manager *instance,
							void *address);
void					*mm_free(t_memory_manager *instance, void *address);
void					*mm_alloc(t_memory_manager *instance, uint64_t size);
void					*mm_calloc(t_memory_manager *instance, uint64_t size);
t_memory_manager		*mm_initialize(bool exit_on_fail);
void					mm_bzero(void *s, size_t n);
void					*mm_register_alloc(t_memory_manager *instance,
							void *address);
void					*mm_unregister_alloc(t_memory_manager *instance,
							void *address);
void					mm_fast_exit(t_memory_manager *instance);

#endif