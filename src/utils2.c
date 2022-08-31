/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:45:03 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/31 09:58:59 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	game_reset(void)
{
	t_game	game;

	game.px_position = 0;
	game.py_position = 0;
	game.coin = 0;
	game.exit = 0;
	game.steps = 0;
	game.height = 0;
	game.width = 0;
	return (game);
}

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
	game->treasure = mlx_xpm_file_to_image(game->connectid, \
		"./img/treasure.xpm", &size, &size);
}

void	key_direction(t_game *game, int dir)
{
	mlx_clear_window(game->connectid, game->window);
	move(game, dir);
	put_layout(game->map, game);
}

void	one_direction(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		game->coin--;
	if (game->map[y][x] != 'E' || !game->coin)
	{
		if (game->map[y][x] == 'E')
			game->exit--;
		if (game->map[y][x] != '1')
		{
			game->steps++;
			ft_printf("Steps: %d\n", game->steps);
		}
		game->map[game->py_position][game->px_position] = '0';
	game->py_position = y;
	game->px_position = x;
		game->map[y][x] = 'P';
	}
}
