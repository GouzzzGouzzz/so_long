/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:52:28 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/11 15:46:37 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_node(int x, int y, t_pathfinder *path, t_vars *vars)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	if (!coord)
		return ;
	coord[0] = x;
	coord[1] = y;
	enqueue(coord, &path->queue);
	free(coord);
	path->reached[path->index] = x;
	path->reached[path->index + 1] = y;
	path->index += 2;
	if (vars->map.map[y][x] == 'C' || vars->map.map[y][x] == 'E')
		path->doable--;
}

int	not_reached(t_pathfinder *path, int x, int y)
{
	int	i;

	i = 0;
	while (i < path->index)
	{
		if (path->reached[i] == x && path->reached[i + 1] == y)
			return (-1);
		i += 2;
	}
	return (1);
}
