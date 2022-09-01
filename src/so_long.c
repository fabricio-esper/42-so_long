/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/01 09:16:59 by fesper-s         ###   ########.fr       */
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
		validate_map(map);
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

void	validate_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("PEC01", map[i][j]))
			{
				ft_putstr_fd("Error\nWrong character in map\n", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	exit_game(t_game *game, char *str)
{
	mlx_clear_window(game->connectid, game->window);
	mlx_destroy_window(game->connectid, game->window);
	ft_printf("%s\n", str);
	exit(EXIT_SUCCESS);
}

int	close_win_x(t_game *game)
{
	mlx_clear_window(game->connectid, game->window);
	mlx_destroy_window(game->connectid, game->window);
	ft_printf("Game closed\n");
	exit(EXIT_SUCCESS);
	return (0);
}
