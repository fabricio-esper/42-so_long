/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabricio <fabricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:30:31 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/23 19:09:45 by fabricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>

# define SIZE 32

enum e_keycode
{
	UP_KEY = 13,
	DOWN_KEY = 1,
	LEFT_KEY = 0,
	RIGHT_KEY = 2,
	ESC = 53
};

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
	void	*player;
	void	*grass;
	void	*rock;
	void	*key;
	void	*chest;
	int		px_position;
	int		py_position;
	int		height;
	int		width;
}				t_game;

int		ft_strrncmp(const char *s1, const char *s2, size_t n);
char	**check_map(int fd, t_map *layout);
char	**read_map(char *map, t_map *layout);
char	*join_map(int fd, t_map *layout, char *full_map);
t_map	layout_reset(void);
void	get_layout(t_map *layout, char *line);
char	*join_layouts(char *s1, char *s2);
int		count_char(char	*str, int c);
void	create_window(char **map, t_game *game, t_map *layout);
void	put_layout(char **map, t_game *game);
void	get_imgs(t_game *game);
void	put_entity(char map, t_game *game, int i, int j);
int		key_event(int key, t_game *game);
t_game	game_reset(void);
void	file_error(void);
void	filetype_error(void);
void	layout_error(void);
void	split_error(void);

#endif
