/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/17 12:51:45 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	layout;
	char	**map;
	int		i;

	if (argc == 2)
	{
		map = read_map(argv[1], &layout);
		i = 0;
		while (map[i])
		{
			ft_printf("%s\n", map[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Invalid number of arguments\n");
		return (2);
	}
	return (0);
}
