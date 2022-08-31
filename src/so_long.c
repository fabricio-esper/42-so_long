/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/31 09:59:03 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	layout;
	t_game	game;
	char	**map;

	if (argc == 2)
	{
		map = read_map(argv[1], &layout);
		game = game_reset();
		game.coin = layout.coin;
		game.exit = layout.exit;
		if (map)
			create_window(map, &game, &layout);
	}
	else
	{
		ft_printf("Invalid number of arguments\n");
		return (2);
	}
	return (0);
}

void	exit_game(t_game *game, char *str)
{
	mlx_clear_window(game->connectid, game->window);
	mlx_destroy_window(game->connectid, game->window);
	ft_printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

int	close_win_x(void)
{
	ft_printf("Game closed\n");
	exit(EXIT_SUCCESS);
	return (0);
}
