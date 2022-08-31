/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:26:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/31 09:58:29 by fesper-s         ###   ########.fr       */
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

char	*join_layouts(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	ft_strlcat(new_str, s2, len_s1 + len_s2 + 1);
	free(s1);
	free(s2);
	return (new_str);
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
