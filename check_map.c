/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:10:16 by nmorandi          #+#    #+#             */
/*   Updated: 2023/02/07 16:11:27 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_border(t_map *arr)
{
	size_t	i;

	i = -1;
	while (++i < arr->lenght - 1)
		if (arr->map[0][i] != '1' || arr->map[arr->height - 1][i] != '1')
			return (print_error(4));
	i = 0;
	while (++i < arr->height - 1)
		if (arr->map[i][0] != '1' || arr->map[i][arr->lenght - 1] != '1')
			return (print_error(4));
	return (1);
}

static int	check_requirements(t_map *arr)
{
	size_t	i;
	size_t	j;
	int		reqmnts[3];

	ft_memset(reqmnts, 0, (sizeof(int) * 3));
	j = -1;
	i = 0;
	while (++i < arr->height - 1)
	{
		while (++j < arr->lenght - 1)
		{
			if (arr->map[i][j] == 'E')
				reqmnts[0]++;
			if (arr->map[i][j] == 'C')
				reqmnts[1]++;
			if (arr->map[i][j] == 'P')
				reqmnts[2]++;
		}
		j = -1;
	}
	if (reqmnts[0] != 1 || reqmnts[1] < 1 || reqmnts[2] != 1)
		return (print_error(3));
	return (1);
}

int	check_ext(char *map_name)
{
	char	*check_ext;
	char	*ext;
	int		i;

	i = -1;
	check_ext = "ber";
	ext = NULL;
	ext = ft_strchr(map_name, '.');
	if (ext == NULL || ext[1] == '\0')
		return (print_error(2));
	ext = ft_strchr(map_name, '.') + 1;
	if (ft_strlen(ext) > 3)
		return (print_error(2));
	while (ext[++i])
		if (ext[i] != check_ext[i])
			return (print_error(2));
	return (1);
}

static int	check_elements(t_map *arr)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = 0;
	while (++i < arr->height - 1)
	{
		while (++j < arr->lenght - 1)
		{
			if (!is_in_set(arr->map[i][j], "01EPC"))
				return (print_error(1));
		}
		j = -1;
	}
	return (1);
}

int	check_all(t_map *arr)
{
	if (check_border(arr) == -1 || check_requirements(arr) == -1
		|| check_elements(arr) == -1)
	{
		clear_map(arr);
		return (-1);
	}
	if (arr->lenght < arr->height)
		return (print_error(2));
	return (0);
}
