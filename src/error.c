/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:40:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/01 09:17:30 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(strerror(2), 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	filetype_error(void)
{
	ft_putstr_fd("Error\nInvalid file extension\n", 2);
	exit(EXIT_FAILURE);
}

void	layout_error(void)
{
	ft_putstr_fd("Error\nEmpty map", 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	split_error(void)
{
	ft_putstr_fd("Error\nSplit failed", 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
