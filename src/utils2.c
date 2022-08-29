/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:45:03 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/29 13:33:45 by fesper-s         ###   ########.fr       */
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

int	close_win_x(void)
{
	ft_printf("Game closed\n");
	exit(EXIT_SUCCESS);
	return (0);
}