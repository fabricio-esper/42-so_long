/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:30:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/22 14:41:29 by fesper-s         ###   ########.fr       */
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
	game->skull = mlx_xpm_file_to_image(game->connectid, \
		"./img/skull.xpm", &size, &size);
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

void	create_window(char **map, t_game *game, t_map *layout)
{
	game->width = layout->width * SIZE;
	game->height = layout->height * SIZE;
	game->connectid = mlx_init();
	game->window = mlx_new_window(game->connectid, game->width, game->height, \
		"so_long");
	get_imgs(game);
	put_layout(map, game);
	mlx_loop(game->connectid);
}
