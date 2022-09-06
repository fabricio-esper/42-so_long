/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:26:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/06 14:20:10 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;
	size_t			size_s1;
	size_t			size_s2;

	if (!n)
		return (0);
	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	while (n--)
	{
		if (str_s1[size_s1] != str_s2[size_s2])
			return (str_s1[size_s1] - str_s2[size_s2]);
		size_s1--;
		size_s2--;
	}
	return (0);
}

int	count_char(char *str, int c)
{
	int	rep;

	rep = 0;
	while (*str)
	{
		if (*str == c)
			rep++;
		str++;
	}
	return (rep);
}

void	put_param(t_game *game, char *param, int x, int y)
{
	mlx_put_image_to_window(game->connectid, game->window, \
		param, x, y);
}

void	put_entity(char map, t_game *game, int i, int j)
{
	if (map == '0')
		put_param(game, game->grass, j * SIZE, i * SIZE);
	if (map == '1')
		put_param(game, game->rock, j * SIZE, i * SIZE);
	if (map == 'P')
	{
		game->px_position = j;
		game->py_position = i;
		put_param(game, game->player, game->px_position * SIZE, \
			game->py_position * SIZE);
	}
	if (map == 'C')
		put_param(game, game->key, j * SIZE, i * SIZE);
	if (map == 'E')
	{
		if (game->coin > 0)
			put_param(game, game->chest, j * SIZE, i * SIZE);
		else
			put_param(game, game->treasure, j * SIZE, i * SIZE);
	}
	if (!game->exit)
		exit_game(game, "Congratulations, you win!");
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
