/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/15 14:57:29 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(void)
{
	void	*connectid;
	void	*window;

	connectid = mlx_init();
	window = mlx_new_window(connectid, 800, 800, "so_long");
	mlx_loop(connectid);
}

int	main(int argc, char **argv)
{
	int		mapfd;
	char	*line;

	if (argc == 2)
	{
		if (ft_strnstr(argv[1], ".ber", 4))
		{
			mapfd = open(argv[1], O_RDONLY);
			line = get_next_line(mapfd);
			ft_printf("%s\n", line);
			create_window();
		}
		else
		{
			ft_printf("Invalid file extension\n");
			return (2);
		}
	}
	else
	{
		ft_printf("Invalid number of arguments\n");
		return (1);
	}
	return (0);
}
