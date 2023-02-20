/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:58:30 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/30 19:56:36 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		clear_map(&vars->map);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	on_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	clear_map(&vars->map);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

void	render_mvt(t_vars *vars, int old_x, int old_y)
{
	vars->moves++;
	if (vars->moves == -2147483648)
		vars->moves = 0;
	ft_printf("Moves: %d\n", vars->moves);
	place_tile(vars, old_x / 16, old_y / 16, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->pos_x, vars->pos_y);
}
