/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:43:11 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/14 19:05:46 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_xpm(char *str, int x_off, int y_off, t_vars *vars)
{
	void	*img;
	int		x_img;
	int		y_img;

	img = mlx_xpm_file_to_image(vars->mlx, str, &x_img, &y_img);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x_off, y_off);
	mlx_destroy_image(vars->mlx, img);
}

void	place_tile(t_vars *vars, int x, int y, int init)
{
	char	*img_path;

	if (vars->map.map[y][x] == '0')
		img_path = "./textures/floor.xpm";
	else if (vars->map.map[y][x] == 'E')
		img_path = "./textures/exit.xpm";
	else if (vars->map.map[y][x] == 'P')
	{
		img_path = "./textures/spawn.xpm";
		if (init)
			set_player_pos(vars, x, y);
	}
	else if (vars->map.map[y][x] == 'C')
	{
		img_path = "./textures/coins.xpm";
		if (init)
			vars->coins++;
	}
	else
		img_path = "./textures/wall.xpm";
	place_xpm(img_path, x * 16, y * 16, vars);
}

void	make_map(t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (j < vars->map.height)
	{
		while (i < vars->map.lenght)
		{
			place_tile(vars, i, j, 1);
			i++;
		}
		i = 0;
		j++;
	}
}
