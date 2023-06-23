/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:12:21 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/25 20:07:03 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	exit_callback(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	ft_printf(TXT_FAST_FAIL);
}

void	print_exit_msg(t_exit_reason reason)
{
	if (reason == REASON_DEATH)
		ft_printf(TXT_DEATH);
	if (reason == REASON_FAST_FAIL)
		ft_printf(TXT_FAST_FAIL);
	if (reason == REASON_MAP_ERROR)
		ft_printf(TXT_MAP_ERROR);
	if (reason == REASON_MLX_ERROR)
		ft_printf(TXT_MLX_ERROR);
	if (reason == REASON_WIN)
		ft_printf(TXT_WIN);
	if (reason == REASON_NATURAL)
		ft_printf(TXT_NATURAL);
	if (reason == REASON_INVALID_ARGS)
		ft_printf(TXT_INVALID_ARGS);
}

void	close_game(t_game *game, t_exit_reason reason)
{
	print_exit_msg(reason);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->mm_instance)
		mm_exit(game->mm_instance);
	exit((reason == REASON_DEATH || reason == REASON_WIN
			|| reason == REASON_NATURAL));
}
