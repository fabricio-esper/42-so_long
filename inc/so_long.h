/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:30:31 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/31 14:27:42 by fesper-s         ###   ########.fr       */
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

# ifdef __linux__

enum e_keycode
{
	UP_KEY = 119,
	DOWN_KEY = 115,
	LEFT_KEY = 97,
	RIGHT_KEY = 100,
	ESC = 65307
};
# else

enum e_keycode
{
	UP_KEY = 13,
	DOWN_KEY = 1,
	LEFT_KEY = 0,
	RIGHT_KEY = 2,
	ESC = 53
};
# endif

typedef struct s_map
{
	int	height;
	int	width;
	int	player;
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
	void	*treasure;
	char	**map;
	int		px_position;
	int		py_position;
	int		coin;
	int		exit;
	int		steps;
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
char	**map_backup(char **map);
void	move(t_game *game, int dir);
void	put_param(t_game *game, char *param, int x, int y);
void	key_direction(t_game *game, int dir);
void	one_direction(t_game *game, int y, int x);
t_game	game_reset(void);
void	exit_game(t_game *game, char *str);
void	validate_map(char **map);
void	file_error(void);
void	filetype_error(void);
void	layout_error(void);
void	split_error(void);
void	is_wall(t_map *layout, t_game *game);
void	error_map_content(t_map *layout);
int		close_win_x(t_game *game);

#endif
