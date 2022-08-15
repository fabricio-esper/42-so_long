/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:27:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/12 10:27:12 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*retinit;
	void	*retnew;
	int		i;

	(void) argc;
	(void) argv;
	retinit = mlx_init();
	retnew = mlx_new_window(retinit, 800, 800, "so_long");
	i = -1;
	while (++i < 800)
		mlx_pixel_put(retinit, retnew, 457, i, 0xff0000);
	i = -1;
	while (++i < 800)
		mlx_pixel_put(retinit, retnew, 459, i, 0xffffff);
	mlx_string_put(retinit, retnew, 255, 255, 0xffffff, "REDBULL");
	mlx_loop(retinit);
	return (0);
}
