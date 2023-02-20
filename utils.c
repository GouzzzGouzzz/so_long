/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:11:30 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 18:49:52 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

int	print_error(int code)
{
	if (code == 1)
		ft_printf("Error\nUnexpected symbols\n");
	if (code == 2)
		ft_printf("Error\nMap is not rectangular or not a .ber\n");
	if (code == 3)
		ft_printf("Error\nMissing requirements\n");
	if (code == 4)
		ft_printf("Error\nBorder is not closed\n");
	if (code == 5)
		ft_printf("Error\nInvalid path\n");
	if (code == 6)
		ft_printf("Error\nMap not found or an error occured at open\n");
	if (code == 7)
		ft_printf("Error\nMemory error\n");
	return (-1);
}
