/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:00:41 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/09 15:20:34 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_pos(t_vars *vars, int x, int y)
{
	vars->pos_x = x * 16;
	vars->pos_y = y * 16;
}

int	check_movements(t_vars *vars, int mvt)
{
	int	player_x;
	int	player_y;

	player_y = vars->pos_y / 16;
	player_x = vars->pos_x / 16;
	if (mvt == 1 && vars->map.map[player_y][player_x - 1] != '1')
		return (1);
	if (mvt == 2 && vars->map.map[player_y][player_x + 1] != '1')
		return (1);
	if (mvt == 4 && vars->map.map[player_y + 1][player_x] != '1')
		return (1);
	if (mvt == 3 && vars->map.map[player_y - 1][player_x] != '1')
		return (1);
	return (-1);
}

int	collect_and_finish(t_vars *vars)
{
	int	player_x;
	int	player_y;

	player_y = vars->pos_y / 16;
	player_x = vars->pos_x / 16;
	if (vars->map.map[player_y][player_x] == 'C')
	{
		vars->coins--;
		vars->map.map[player_y][player_x] = '0';
	}
	if (vars->coins <= 0 && vars->map.map[player_y][player_x] == 'E')
		return (1);
	return (0);
}
