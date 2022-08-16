/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:26:15 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/16 12:05:15 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;
	size_t			size_s1;
	size_t			size_s2;

	if (!n)
		return (0);
	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	while (n--)
	{
		if (str_s1[size_s1] != str_s2[size_s2])
			return (str_s1[size_s1] - str_s2[size_s2]);
		size_s1--;
		size_s2--;
	}
	return (0);
}
