/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabricio <fabricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:30:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/23 19:11:07 by fabricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_imgs(t_game *game)
{
	int	size;

	size = SIZE;
	game->grass = mlx_xpm_file_to_image(game->connectid, \
		"./img/grass.xpm", &size, &size);
	game->rock = mlx_xpm_file_to_image(game->connectid, \
		"./img/rock.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->connectid, \
		"./img/player.xpm", &size, &size);
	game->key = mlx_xpm_file_to_image(game->connectid, \
		"./img/key.xpm", &size, &size);
	game->chest = mlx_xpm_file_to_image(game->connectid, \
		"./img/chest.xpm", &size, &size);
}

void	put_layout(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			put_entity(map[i][j], game, i, j);
	}
}

int	key_event(int key, t_game *game)
{
	int	size;

	size = SIZE;
	if (key == RIGHT_KEY)
	{
		ft_printf("text");
		game->px_position++;
	}
	if (key == ESC)
	{
		ft_printf("Game closed\n");
		exit(0);
	}
	mlx_destroy_image(game->connectid, game->player);
	game->player = mlx_xpm_file_to_image(game->connectid, "./img/player.xpm", &size, &size);
	mlx_put_image_to_window(game->connectid, game->window, game->player, \
		game->px_position * SIZE, game->py_position * SIZE);
	return (0);
}

t_game	game_reset(void)
{
	t_game	game;

	game.px_position = 0;
	game.py_position = 0;
	game.width = 0;
	game.height = 0;
	return (game);
}

void	create_window(char **map, t_game *game, t_map *layout)
{
	*game = game_reset();
	game->width = layout->width * SIZE;
	game->height = layout->height * SIZE;
	game->connectid = mlx_init();
	game->window = mlx_new_window(game->connectid, game->width, game->height, \
		"so_long");
	get_imgs(game);
	put_layout(map, game);
	mlx_key_hook(game->window, key_event, game);
	mlx_loop(game->connectid);
}
