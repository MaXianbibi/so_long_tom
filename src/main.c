/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:19:58 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 19:41:05 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	print_map(t_map *map)
{
	uint64_t	i;
	uint64_t	y;

	i = 0;
	y = 0;
	while (i < map->m_height)
	{
		while (y < map->m_width)
		{
			printf("%c", map->map[i][y]);
			y++;
		}
		printf("\n");
		y = 0;
		i++;
	}
}

mlx_image_t	*load_img(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

bool	load_all_resources(t_game *game)
{
	game->res.floor_img = load_img(game, IMG_FLOOR);
	game->res.collectible_img = load_img(game, IMG_COLLECTIBLE);
	game->res.exit_img = load_img(game, IMG_EXIT);
	game->res.player_img = load_img(game, IMG_PLAYER);
	game->res.player_anim_img = load_img(game, IMG_PLAYER_ANIM);
	game->res.wall_img = load_img(game, IMG_WALL);
	game->res.enemy_img = load_img(game, IMG_ENEMY);
	if (!game->res.enemy_img || !game->res.collectible_img
		|| !game->res.exit_img || !game->res.player_img || !game->res.wall_img
		|| !game->res.enemy_img || !game->res.player_anim_img)
		return (false);
	return (true);
}

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map->m_width * IMG_SIZE, game->map->m_height
			* IMG_SIZE + 40, "so_long", false);
	if (!game->mlx)
		return (false);
	mlx_key_hook(game->mlx, (void (*)(struct mlx_key_data, void *))key_hook,
		game);
	game->blank = mlx_new_image(game->mlx, game->map->m_width * IMG_SIZE,
			game->map->m_height * IMG_SIZE + 40);
	if (!game->blank)
		return (false);
	ft_memset(game->blank->pixels, 128, game->blank->width * game->blank->height
		* sizeof(int32_t));
	if (!load_all_resources(game))
		return (false);
	if (!mlx_loop_hook(game->mlx, (void (*)(void *))loop, game))
		return (false);
	mlx_close_hook(game->mlx, (void (*)(void *))exit_hook, game);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int32_t	fd;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		close_game(&game, REASON_INVALID_ARGS);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 10))
		close_game(&game, REASON_MAP_ERROR);
	game.mm_instance = mm_initialize(true);
	if (!game.mm_instance)
		close_game(&game, REASON_FAST_FAIL);
	mm_register_callback(game.mm_instance, (void (*)(void *))exit_callback,
		&game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		close_game(&game, REASON_MAP_ERROR);
	game.map = parse_map(&game, fd);
	if (!game.map)
		close_game(&game, REASON_MAP_ERROR);
	if (!init_mlx(&game))
		close_game(&game, REASON_MLX_ERROR);
	render_frame(&game, true, 0, 0);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
