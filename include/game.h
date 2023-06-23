/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:12:56 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/27 19:39:44 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define IMG_FLOOR "./assets/square-32-1437702471.png"
# define IMG_WALL "./assets/square-32-2312627640.png"
# define IMG_PLAYER "./assets/kjorska_the_mage-1295629913.png"
# define IMG_PLAYER_ANIM "./assets/piq_63383-3614519094.png"
# define IMG_EXIT "./assets/square-32-2688316580.png"
# define IMG_COLLECTIBLE "./assets/square-32-3330092962.png"
# define IMG_ENEMY "./assets/square-32-3373446759.png"
# define MAX_DIMENSION 100
# define ALLOWED_CHARS "10PCEV"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGTH 720
# define IMG_SIZE 32
# define MOVE_STR "Current moves: "
# define TXT_MAP_ERROR "Error\nMap error"
# define TXT_WIN "wow you won"
# define TXT_DEATH "you died"
# define TXT_MLX_ERROR "Error\nMLX error"
# define TXT_FAST_FAIL "Error\nFast fail"
# define TXT_NATURAL "Game closed"
# define TXT_INVALID_ARGS "Error\nInvalid arguments"

# include "../MLX42-master/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef enum e_exit_reason
{
	REASON_MAP_ERROR,
	REASON_WIN,
	REASON_DEATH,
	REASON_MLX_ERROR,
	REASON_FAST_FAIL,
	REASON_NATURAL,
	REASON_INVALID_ARGS
}						t_exit_reason;

typedef struct s_entity
{
	struct s_entity		*next;
	uint64_t			pos_x;
	uint64_t			pos_y;
	double				last_move;
	double				last_animation;
}						t_entity;

typedef struct s_resources
{
	mlx_image_t			*floor_img;
	mlx_image_t			*player_img;
	mlx_image_t			*player_anim_img;
	mlx_image_t			*wall_img;
	mlx_image_t			*exit_img;
	mlx_image_t			*collectible_img;
	mlx_image_t			*enemy_img;
}						t_resources;

typedef struct s_map
{
	uint64_t			m_height;
	uint64_t			m_width;
	uint32_t			collectible_count;
	char				**map;
}						t_map;

typedef struct s_game
{
	mlx_t				*mlx;
	uint64_t			player_x;
	uint64_t			player_y;
	uint32_t			move_count;
	double				last_tick;
	mlx_image_t			*blank;
	t_memory_manager	*mm_instance;
	t_map				*map;
	t_resources			res;
	t_entity			*entity_list;
}						t_game;

t_map					*parse_map(t_game *game, int fd);
void					update_pos(t_game *game, uint64_t pos_x,
							uint64_t pos_y);
void					attack(t_game *game);
void					key_hook(mlx_key_data_t keydata, t_game *game);
void					render_frame(t_game *game, bool full, uint64_t change_x,
							uint64_t change_y);
void					close_game(t_game *game, t_exit_reason reason);
bool					create_entity(t_game *game, t_map *map, uint64_t pos_x,
							uint64_t pos_y);
void					delete_entity(t_game *game, uint64_t pos_x,
							uint64_t pos_y);
t_entity				*find_entity(t_game *game, uint64_t pos_x,
							uint64_t pos_y);
void					update_entity(t_game *game, t_entity *entity,
							double delta);
void					mm_register_callback(t_memory_manager *instance,
							void (*callback_func)(void *), void *param);
void					print_map(t_map *map);
bool					flood_fill(t_game *game, t_map *map);
void					loop(t_game *game);
void					exit_callback(t_game *game);
void					animate(t_game *game);
void					exit_hook(t_game *game);

#endif