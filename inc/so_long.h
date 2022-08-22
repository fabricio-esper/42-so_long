/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabricio <fabricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:30:31 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/21 14:46:29 by fabricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#	include "../mlx_linux/mlx.h"
# else
#	include "../mlx/mlx.h"
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>

# define SIZE 32

typedef struct s_map
{
	int	height;
	int	width;
	int	player;
	int	enemy;
	int	coin;
	int	exit;
}				t_map;

typedef struct s_game
{
	void	*connectid;
	void	*window;
	void	*image;
	int		height;
	int		width;
	int		*player;

}				t_game;

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
char	**check_map(int fd, t_map *layout);
char	**read_map(char *map, t_map *layout);
char	*join_map(int fd, t_map *layout, char *full_map);
t_map	layout_reset(void);
void	get_layout(t_map *layout, char *line);
char	*join_layouts(char *s1, char *s2);
int		count_char(char	*str, int c);
void	create_window(t_game *game, t_map *layout);
void	file_error(void);
void	filetype_error(void);
void	layout_error(void);
void	split_error(void);

#endif
