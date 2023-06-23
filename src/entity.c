/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:03:54 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:07:14 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	move_entity(t_game *game, t_entity *entity, uint64_t pos_x,
		uint64_t pos_y)
{
	if (pos_x > game->map->m_width || pos_y > game->map->m_height)
		return ;
	if (game->map->map[pos_y][pos_x] == '1')
		return ;
	if (find_entity(game, pos_x, pos_y))
		return ;
	entity->pos_x = pos_x;
	entity->pos_y = pos_y;
}

void	update_entity(t_game *game, t_entity *entity, double delta)
{
	uint64_t	time;
	uint32_t	direction;
	uint64_t	old_x;
	uint64_t	old_y;

	time = (uint64_t)(delta * 100000);
	direction = time % 4;
	old_x = entity->pos_x;
	old_y = entity->pos_y;
	if (direction == 0)
		move_entity(game, entity, entity->pos_x - 1, entity->pos_y);
	if (direction == 1)
		move_entity(game, entity, entity->pos_x + 1, entity->pos_y);
	if (direction == 2)
		move_entity(game, entity, entity->pos_x, entity->pos_y - 1);
	if (direction == 3)
		move_entity(game, entity, entity->pos_x, entity->pos_y + 1);
	if (entity->pos_x == game->player_x && entity->pos_y == game->player_y)
		close_game(game, REASON_DEATH);
	entity->last_move = mlx_get_time();
	render_frame(game, false, old_x, old_y);
}

t_entity	*find_entity(t_game *game, uint64_t pos_x, uint64_t pos_y)
{
	t_entity	*current;

	current = game->entity_list;
	while (current)
	{
		if (current->pos_x == pos_x && current->pos_y == pos_y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	delete_entity(t_game *game, uint64_t pos_x, uint64_t pos_y)
{
	t_entity	*current;
	t_entity	*last;

	last = NULL;
	current = game->entity_list;
	while (current)
	{
		if (current->pos_x == pos_x && current->pos_y == pos_y)
			break ;
		last = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (!last)
		game->entity_list = current->next;
	else
		last->next = current->next;
	mm_free(game->mm_instance, current);
	render_frame(game, false, pos_x, pos_y);
}

bool	create_entity(t_game *game, t_map *map, uint64_t pos_x, uint64_t pos_y)
{
	t_entity	*ent;
	t_entity	*last;

	ent = mm_calloc(game->mm_instance, sizeof(t_entity));
	last = game->entity_list;
	while (last && last->next)
		last = last->next;
	if (!last)
		game->entity_list = ent;
	else
		last->next = ent;
	ent->pos_x = pos_x;
	ent->pos_y = pos_y;
	ent->last_animation = mlx_get_time();
	ent->last_move = mlx_get_time();
	map->map[pos_y][pos_x] = '0';
	return (true);
}
