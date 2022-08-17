/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:30:31 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/17 13:11:57 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <string.h>

typedef struct s_map
{
	int	height;
	int	width;
	int	player;
	int	enemy;
	int	coin;
	int	exit;
}				t_map;

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
char	**check_map(int fd, t_map *layout);
char	**read_map(char *map, t_map *layout);
char	*join_map(int fd, t_map *layout, char *full_map);
t_map	layout_reset(void);
void	get_layout(t_map *layout, char *line);
char	*join_layouts(char *s1, char *s2);
int		count_char(char	*str, int c);
void	file_error(void);
void	filetype_error(void);
void	layout_error(void);
void	split_error(void);

#endif
