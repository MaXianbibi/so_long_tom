/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:45:04 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:15:54 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

t_map	*dup_map(t_game *game, t_map *to_copy)
{
	t_map		*dup;
	uint32_t	i;

	dup = mm_alloc(game->mm_instance, sizeof(t_map));
	ft_memcpy(dup, to_copy, sizeof(t_map));
	dup->map = mm_alloc(game->mm_instance, sizeof(char *) * to_copy->m_height);
	i = 0;
	while (i < to_copy->m_height)
	{
		dup->map[i] = mm_alloc(game->mm_instance, sizeof(char)
				* to_copy->m_width);
		ft_memcpy(dup->map[i], to_copy->map[i], sizeof(char)
			* to_copy->m_width);
		i++;
	}
	return (dup);
}

void	free_dup(t_game *game, t_map *map)
{
	uint32_t	i;

	i = 0;
	while (i < map->m_height)
	{
		mm_free(game->mm_instance, map->map[i]);
		i++;
	}
	mm_free(game->mm_instance, map);
}

void	fill(t_map *map, bool *exit, uint64_t x, uint64_t y)
{
	if (x < 0 || x > map->m_width || y < 0 || y > map->m_height
		|| map->map[y][x] == '1')
		return ;
	if (map->map[y][x] == 'C')
		map->collectible_count++;
	if (map->map[y][x] == 'E')
		*exit = 1;
	map->map[y][x] = '1';
	fill(map, exit, x + 1, y);
	fill(map, exit, x - 1, y);
	fill(map, exit, x, y + 1);
	fill(map, exit, x, y - 1);
}

// so lazy and ugly :(
bool	flood_fill(t_game *game, t_map *map)
{
	t_map		*dup;
	bool		exit;
	uint32_t	collectibles;

	dup = dup_map(game, map);
	dup->collectible_count = 0;
	exit = 0;
	fill(dup, &exit, game->player_x, game->player_y);
	collectibles = dup->collectible_count;
	free_dup(game, dup);
	return (exit && (collectibles == map->collectible_count));
}
