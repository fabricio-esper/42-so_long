/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:30:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/18 14:30:36 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_game *game, t_map *layout)
{
	int	size;

	size = SIZE;
	game->width = layout->width * SIZE;
	game->height = layout->height * SIZE;
	game->connectid = mlx_init();
	game->window = mlx_new_window(game->connectid, game->width, game->height, \
		"so_long");
	game->image = mlx_xpm_file_to_image(game->connectid, \
		"./img/wounded-soldier.xpm", &size, &size);
	mlx_put_image_to_window(game->connectid, game->window, game->image, 32, 32);
	mlx_loop(game->connectid);
}
