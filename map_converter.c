/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:12:52 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/11 16:54:33 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_linelen(char *line, t_map *arr)
{
	if (line)
		if (ft_strlen(line) != arr->lenght + 1)
			return (-1);
	return (1);
}

static int	map_converter(int fd, t_map *arr)
{
	char	*line;
	size_t	i;
	int		flag;

	flag = 0;
	i = -1;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	arr->lenght = ft_strlen(line) - 1;
	while (line != NULL)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (check_linelen(line, arr) != 1)
			flag = 1;
		arr->height++;
	}
	arr->map = malloc(sizeof(char *) * arr->height);
	while (++i < arr->height)
		arr->map[i] = malloc(sizeof(char *) * arr->lenght);
	return (flag);
}

static void	fill_map(int fd, t_map *arr)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = -1;
	while (++i < arr->height)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (line)
			ft_strlcpy(arr->map[i], line, arr->lenght + 1);
	}
	free(line);
}

void	clear_map(t_map *arr)
{
	size_t	i;

	i = -1;
	if (!arr)
		return ;
	while (++i < arr->height)
		free(arr->map[i]);
	if (arr->height > 0)
		free(arr->map);
}

int	create_map(t_map *arr, int fd, char *map_name)
{
	if (fd < 0 || !fd || check_ext(map_name) == -1)
		return (-1);
	arr->height = 0;
	arr->lenght = 0;
	if (map_converter(fd, arr))
	{
		if (arr)
			clear_map(arr);
		close(fd);
		return (print_error(2));
	}
	close(fd);
	fd = open(map_name, O_RDONLY);
	fill_map(fd, arr);
	close(fd);
	if (check_all(arr) == -1)
		return (-1);
	return (0);
}
