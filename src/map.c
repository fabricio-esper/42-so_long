/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:13:05 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/29 17:43:16 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	layout_reset(void)
{
	t_map	layout;

	layout.height = 0;
	layout.width = 0;
	layout.player = 0;
	layout.enemy = 0;
	layout.coin = 0;
	layout.exit = 0;
	return (layout);
}

void	get_layout(t_map *layout, char *line)
{
	if (!layout->width)
		layout->width = ft_strlen(line) - 1;
	layout->player += count_char(line, 'P');
	layout->enemy += count_char(line, 'Y');
	layout->coin += count_char(line, 'C');
	layout->exit += count_char(line, 'E');
}

char	*join_map(int fd, t_map *layout, char *full_map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!layout->width)
				layout_error();
			break ;
		}
		get_layout(layout, line);
		full_map = join_layouts(full_map, line);
		layout->height++;
	}
	return (full_map);
}

char	**check_map(int fd, t_map *layout)
{
	char	*full_map;
	char	**split_map;

	full_map = NULL;
	*layout = layout_reset();
	full_map = join_map(fd, layout, full_map);
	split_map = ft_split(full_map, '\n');
	if (!split_map)
		split_error();
	free(full_map);
	return (split_map);
}

char	**read_map(char *map, t_map *layout)
{
	int		fd;

	if (ft_strrncmp(map, ".ber", 4) == 0)
	{
		fd = open(map, O_RDONLY);
		if (fd == -1)
			file_error();
		return (check_map(fd, layout));
	}
	else
		filetype_error();
	return (0);
}
