/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:16:00 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/01 13:50:30 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(char **map)
{
	size_t	len_line1;
	int		i;

	len_line1 = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
	{
		if (len_line1 != ft_strlen(map[i]))
		{
			ft_putstr_fd("Error\nMap is not a rectangle\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	is_wall(t_map *layout, char **map)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	cols = layout->width - 1;
	rows = layout->height - 1;
	i = 0;
	j = 0;
	while (map[i][0] == '1' && map[i][cols] == '1' && i < rows)
		i++;
	while (map[0][j] == '1' && map[rows][j] == '1' && j <= cols)
		j++;
	if (i != rows || j - 1 != cols)
	{
		ft_putstr_fd("Error\nMissing wall\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_map_content(t_map *layout)
{
	if (layout->player > 1 || layout->player == 0 || layout->exit == 0 \
		|| layout->coin == 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (layout->player > 1)
			ft_putstr_fd("More than 1 player found\n", 2);
		if (layout->player == 0)
			ft_putstr_fd("No players found\n", 2);
		if (layout->exit == 0)
			ft_putstr_fd("No exit found\n", 2);
		if (layout->coin == 0)
			ft_putstr_fd("No key found\n", 2);
		exit(EXIT_FAILURE);
	}
}
