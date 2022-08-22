/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/22 09:44:11 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	layout;
	t_game	game;
	char	**map;

	if (argc == 2)
	{
		map = read_map(argv[1], &layout);
		if (map)
			create_window(map, &game, &layout);
	}
	else
	{
		ft_printf("Invalid number of arguments\n");
		return (2);
	}
	return (0);
}
