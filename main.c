/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:27:07 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/02 14:22:37 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("./teste.txt", O_RDONLY);
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd);
		ft_printf("linha %d: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
