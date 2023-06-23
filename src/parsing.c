/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:14:33 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 20:02:51 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

bool	verify_line(t_game *game, t_map *map, char *line)
{
	uint64_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(ALLOWED_CHARS, line[i]))
			return (false);
		if (line[i] == 'P')
		{
			game->player_x = i;
			game->player_y = map->m_height;
		}
		i++;
	}
	if (i > MAX_DIMENSION)
		return (false);
	if (map->m_width && map->m_width != i)
		return (false);
	else if (!map->m_width)
		map->m_width = i;
	return (true);
}

bool	validate_map(t_game *game, t_map *map)
{
	uint64_t	x;
	uint64_t	y;

	y = -1;
	x = -1;
	if (!map->m_height || !map->m_width)
		return (false);
	while (++y < map->m_height)
	{
		while (++x < map->m_width)
		{
			if ((y == map->m_height - 1 && map->map[y][x] != '1') || (y == 0
					&& map->map[y][x] != '1') || (x == 0
					&& map->map[y][x] != '1') || (x == map->m_width - 1
					&& map->map[y][x] != '1'))
				return (false);
		}
		x = -1;
	}
	if (!flood_fill(game, map))
		return (false);
	map->map[game->player_y][game->player_x] = '0';
	return (true);
}

bool	parse_map_obj(t_game *game, t_map *map)
{
	uint64_t	x;
	uint64_t	y;
	bool		exits;
	bool		player;

	y = -1;
	exits = 0;
	player = 0;
	while (++y < map->m_height)
	{
		x = -1;
		while (++x < map->m_width)
		{
			if (map->map[y][x] == 'C')
				map->collectible_count++;
			else if (map->map[y][x] == 'P')
				player++;
			else if (map->map[y][x] == 'E')
				exits++;
			else if (map->map[y][x] == 'V')
				create_entity(game, map, x, y);
		}
	}
	return ((exits == 1) && (player == 1));
}

t_map	*parse_map(t_game *game, int fd)
{
	t_map	*map;
	char	*lines[MAX_DIMENSION + 1];
	char	*curr_line;

	map = mm_calloc(game->mm_instance, sizeof(t_map));
	curr_line = get_next_line(game->mm_instance, fd);
	while (curr_line)
	{
		if (ft_strlen(curr_line) > 1)
		{
			if (map->m_height >= MAX_DIMENSION - 1 || !verify_line(game, map,
					curr_line))
				return (NULL);
			lines[map->m_height] = curr_line;
			map->m_height++;
		}
		curr_line = get_next_line(game->mm_instance, fd);
	}
	map->map = mm_alloc(game->mm_instance, sizeof(char *) * (map->m_height
				+ 1));
	ft_memcpy(map->map, lines, sizeof(char *) * map->m_height);
	if (!parse_map_obj(game, map) || !validate_map(game, map))
		return (NULL);
	return (map);
}
