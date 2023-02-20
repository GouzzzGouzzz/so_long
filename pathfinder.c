/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:53:24 by nmorandi          #+#    #+#             */
/*   Updated: 2023/02/07 16:06:17 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	cell_number(t_vars *vars)
{
	size_t	i;
	size_t	j;
	int		size;

	size = 0;
	i = 0;
	j = 0;
	while (j < vars->map.height)
	{
		while (i < vars->map.lenght)
		{
			if (vars->map.map[j][i] == '0' || vars->map.map[j][i] == 'C'
					|| vars->map.map[j][i] == 'E' || vars->map.map[j][i] == 'P')
				size++;
			i++;
		}
		i = 0;
		j++;
	}
	return (size);
}

static void	manage_neighbors(t_vars *vars, t_pathfinder *path, int *coord)
{
	int	x;
	int	y;

	x = coord[0];
	y = coord[1];
	if (vars->map.map[y + 1][x] != '1' && not_reached(path, x, y + 1) == 1)
		add_node(x, y + 1, path, vars);
	if (vars->map.map[y - 1][x] != '1' && not_reached(path, x, y - 1) == 1)
		add_node(x, y - 1, path, vars);
	if (vars->map.map[y][x - 1] != '1' && not_reached(path, x - 1, y) == 1)
		add_node(x - 1, y, path, vars);
	if (vars->map.map[y][x + 1] != '1' && not_reached(path, x + 1, y) == 1)
		add_node(x + 1, y, path, vars);
}

static int	bfs_algo(t_vars *vars, t_pathfinder *path)
{
	int	*coord;

	while (queue_status(&path->queue) != 1)
	{
		coord = dequeue(&path->queue);
		if (coord == NULL)
			return (print_error(7));
		manage_neighbors(vars, path, coord);
		free(coord);
		if (path->doable == 0)
			return (1);
	}
	return (-1);
}

static void	clear_utilities(t_pathfinder *path)
{
	free(path->queue.coord);
	free(path->reached);
}

int	check_path(t_vars *vars)
{
	t_pathfinder	path;
	int				flag_error;

	flag_error = 1;
	path.index = 0;
	path.doable = vars->coins + 1;
	path.reached = malloc(sizeof(int) * (cell_number(vars) * 2));
	if (!path.reached)
		return (print_error(7));
	if (queue_init(&path.queue, cell_number(vars)) == -1)
		return (print_error(7));
	add_node(vars->pos_x / 16, vars->pos_y / 16, &path, vars);
	if (bfs_algo(vars, &path) == -1)
		flag_error = -1;
	clear_utilities(&path);
	if (flag_error == -1)
		return (print_error(5));
	return (1);
}
