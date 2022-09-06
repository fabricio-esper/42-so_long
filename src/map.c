/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:13:05 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/06 14:20:04 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_layout(t_map *layout, char *line)
{
	if (!layout->width)
		layout->width = ft_strlen(line) - 1;
	layout->player += count_char(line, 'P');
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
