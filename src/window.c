/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:30:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/24 14:38:40 by fesper-s         ###   ########.fr       */
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
	{
		mlx_clear_window(game->connectid, game->window);
		move(game, RIGHT_KEY);
		put_layout(game->map, game);
	}
	if (key == UP_KEY)
	{
		mlx_clear_window(game->connectid, game->window);
		move(game, UP_KEY);
		put_layout(game->map, game);
	}
	if (key == DOWN_KEY)
	{
		mlx_clear_window(game->connectid, game->window);
		move(game, DOWN_KEY);
		put_layout(game->map, game);
	}
	if (key == LEFT_KEY)
	{
		mlx_clear_window(game->connectid, game->window);
		move(game, LEFT_KEY);
		put_layout(game->map, game);
	}
	if (key == ESC)
	{
		ft_printf("Game closed\n");
		exit(0);
	}
	return (0);
}

void	move(t_game *game, int dir)
{
	if (dir == RIGHT_KEY && game->map[game->py_position][game->px_position + 1] != '1')
	{
		if (game->map[game->py_position][game->px_position + 1] == 'C')
			game->coin--;
		game->map[game->py_position][game->px_position] = '0';
		game->map[game->py_position][++game->px_position] = 'P';
	}
	if (dir == UP_KEY && game->map[game->py_position - 1][game->px_position] != '1')
	{
		if (game->map[game->py_position - 1][game->px_position] == 'C')
			game->coin--;
		game->map[game->py_position][game->px_position] = '0';
		game->map[--game->py_position][game->px_position] = 'P';
	}
	if (dir == DOWN_KEY && game->map[game->py_position + 1][game->px_position] != '1')
	{
		if (game->map[game->py_position + 1][game->px_position] == 'C')
			game->coin--;
		game->map[game->py_position][game->px_position] = '0';
		game->map[++game->py_position][game->px_position] = 'P';
	}
	if (dir == LEFT_KEY && game->map[game->py_position][game->px_position - 1] != '1')
	{
		if (game->map[game->py_position][game->px_position - 1] == 'C')
			game->coin--;
		game->map[game->py_position][game->px_position] = '0';
		game->map[game->py_position][--game->px_position] = 'P';
	}
	int i = -1;
	while (game->map[++i])
		ft_printf("%s\n", game->map[i]);
	ft_printf("\n");
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
	game->map = map_backup(map);
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
