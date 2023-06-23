/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:48:41 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:05:33 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	key_hook(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_W)
		update_pos(game, game->player_x, game->player_y - 1);
	else if (keydata.key == MLX_KEY_S)
		update_pos(game, game->player_x, game->player_y + 1);
	else if (keydata.key == MLX_KEY_A)
		update_pos(game, game->player_x - 1, game->player_y);
	else if (keydata.key == MLX_KEY_D)
		update_pos(game, game->player_x + 1, game->player_y);
	else if (keydata.key == MLX_KEY_X)
		attack(game);
	else if (keydata.key == MLX_KEY_ESCAPE)
		close_game(game, REASON_NATURAL);
}

void	exit_hook(t_game *game)
{
	close_game(game, REASON_NATURAL);
}

void	loop(t_game *game)
{
	t_entity	*ent;
	double		time;

	ent = game->entity_list;
	game->last_tick += game->mlx->delta_time;
	time = mlx_get_time();
	if (game->last_tick > 1)
		game->last_tick = 0;
	else
		return ;
	while (ent)
	{
		if (time - ent->last_move >= 3)
			update_entity(game, ent, game->mlx->delta_time);
		ent = ent->next;
	}
	animate(game);
}
