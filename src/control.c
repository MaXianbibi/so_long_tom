/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:05:56 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 18:53:34 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

// This is garbage should have been adapted for entities too :(
void	update_pos(t_game *game, uint64_t pos_x, uint64_t pos_y)
{
	uint64_t	old_x;
	uint64_t	old_y;

	if (pos_x > game->map->m_width || pos_y > game->map->m_height)
		return ;
	if (game->map->map[pos_y][pos_x] == '1')
		return ;
	if (find_entity(game, pos_x, pos_y))
		close_game(game, REASON_DEATH);
	old_x = game->player_x;
	old_y = game->player_y;
	game->player_x = pos_x;
	game->player_y = pos_y;
	game->move_count++;
	ft_printf("Moves: %u\n", game->move_count);
	if (game->map->map[game->player_y][game->player_x] == 'E'
		&& !game->map->collectible_count)
		close_game(game, REASON_WIN);
	if (game->map->map[game->player_y][game->player_x] == 'C')
	{
		game->map->map[game->player_y][game->player_x] = '0';
		game->map->collectible_count--;
	}
	render_frame(game, false, old_x, old_y);
}

void	attack(t_game *game)
{
	delete_entity(game, game->player_x - 1, game->player_y);
	delete_entity(game, game->player_x + 1, game->player_y);
	delete_entity(game, game->player_x, game->player_y + 1);
	delete_entity(game, game->player_x, game->player_y - 1);
}

void	animate(t_game *game)
{
	void	*temp;

	temp = game->res.player_img;
	game->res.player_img = game->res.player_anim_img;
	game->res.player_anim_img = temp;
	render_frame(game, false, game->player_x, game->player_y);
}
