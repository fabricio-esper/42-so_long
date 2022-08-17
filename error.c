/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:40:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/17 11:26:15 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(void)
{
	ft_putstr_fd(strerror(2), 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	filetype_error(void)
{
	ft_putstr_fd("Invalid file extension\n", 2);
	exit(EXIT_FAILURE);
}

void	layout_error(void)
{
	ft_putstr_fd("Empty map", 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
