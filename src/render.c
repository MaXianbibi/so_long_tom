/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:39:13 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 19:11:13 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	draw_text(t_game *game)
{
	char	*num;
	char	*full_str;

	num = mm_register_alloc(game->mm_instance, ft_itoa(game->move_count));
	full_str = mm_register_alloc(game->mm_instance, ft_strjoin(MOVE_STR, num));
	mlx_put_string(game->mlx, full_str, 0, game->map->m_height * IMG_SIZE + 10);
	mm_free(game->mm_instance, num);
	mm_free(game->mm_instance, full_str);
}

//use for bonus
void	draw_entities(t_game *game)
{
	t_entity	*current_entity;

	mlx_image_to_window(game->mlx, game->res.player_img, game->player_x
		* IMG_SIZE, game->player_y * IMG_SIZE);
	current_entity = game->entity_list;
	while (current_entity)
	{
		mlx_image_to_window(game->mlx, game->res.enemy_img,
			current_entity->pos_x * IMG_SIZE, current_entity->pos_y
			* IMG_SIZE);
		current_entity = current_entity->next;
	}
}

void	draw_map(t_game *game)
{
	uint64_t	x;
	uint64_t	y;
	mlx_image_t	*img;

	y = 0;
	while (y < game->map->m_height)
	{
		x = 0;
		while (x < game->map->m_width)
		{
			if (game->map->map[y][x] == '0')
				img = game->res.floor_img;
			else if (game->map->map[y][x] == '1')
				img = game->res.wall_img;
			else if (game->map->map[y][x] == 'C')
				img = game->res.collectible_img;
			else if (game->map->map[y][x] == 'E')
				img = game->res.exit_img;
			mlx_image_to_window(game->mlx, img, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
}

void	partial(t_game *game, uint64_t change_x, uint64_t change_y)
{
	mlx_image_t	*img;

	img = game->res.floor_img;
	if (game->map->map[change_y][change_x] == '1')
		img = game->res.wall_img;
	else if (game->map->map[change_y][change_x] == 'C')
		img = game->res.collectible_img;
	else if (game->map->map[change_y][change_x] == 'E')
		img = game->res.exit_img;
	mlx_image_to_window(game->mlx, img, change_x * IMG_SIZE, change_y
		* IMG_SIZE);
}

void	render_frame(t_game *game, bool full, uint64_t change_x,
		uint64_t change_y)
{
	mlx_image_to_window(game->mlx, game->blank, 0, game->map->m_height
		* IMG_SIZE);
	if (full)
		draw_map(game);
	else
		partial(game, change_x, change_y);
	draw_entities(game);
	draw_text(game);
}
