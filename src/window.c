/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:30:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/01 13:26:16 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (key == RIGHT_KEY)
		key_direction(game, RIGHT_KEY);
	if (key == UP_KEY)
		key_direction(game, UP_KEY);
	if (key == DOWN_KEY)
		key_direction(game, DOWN_KEY);
	if (key == LEFT_KEY)
		key_direction(game, LEFT_KEY);
	if (key == ESC)
		exit_game(game, "Game closed");
	return (0);
}

void	move(t_game *game, int dir)
{
	if (dir == RIGHT_KEY && game->map[game->py_position][game->px_position + 1] \
		!= '1')
		one_direction(game, game->py_position, game->px_position + 1);
	if (dir == UP_KEY && game->map[game->py_position - 1][game->px_position] \
		!= '1')
		one_direction(game, game->py_position - 1, game->px_position);
	if (dir == DOWN_KEY && game->map[game->py_position + 1][game->px_position] \
		!= '1')
		one_direction(game, game->py_position + 1, game->px_position);
	if (dir == LEFT_KEY && game->map[game->py_position][game->px_position - 1] \
		!= '1')
		one_direction(game, game->py_position, game->px_position - 1);
}

char	**map_backup(char **map)
{
	char	**bkp;
	int		lines;
	int		i;

	lines = 0;
	while (map[lines])
		lines++;
	bkp = malloc((lines + 1) * sizeof(char *));
	if (!bkp)
		return (0);
	i = -1;
	while (map[++i])
		bkp[i] = ft_strdup(map[i]);
	bkp[i] = 0;
	return (bkp);
}

void	create_window(char **map, t_game *game, t_map *layout)
{
	is_rectangle(map);
	error_map_content(layout);
	is_wall(layout, map);
	game->map = map_backup(map);
	game->width = layout->width * SIZE;
	game->height = layout->height * SIZE;
	game->connectid = mlx_init();
	game->window = mlx_new_window(game->connectid, game->width, game->height, \
		"so_long");
	get_imgs(game);
	put_layout(map, game);
	mlx_key_hook(game->window, key_event, game);
	mlx_hook(game->window, 17, 0, close_win_x, game);
	mlx_loop(game->connectid);
}
