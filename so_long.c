/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:43:00 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 18:46:03 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_vars *vars)
{
	int	old_x;
	int	old_y;

	old_x = vars->pos_x;
	old_y = vars->pos_y;
	if (keycode == 115 && check_movements(vars, 4) > 0)
		vars->pos_y += 16;
	if (keycode == 119 && check_movements(vars, 3) > 0)
		vars->pos_y -= 16;
	if (keycode == 100 && check_movements(vars, 2) > 0)
		vars->pos_x += 16;
	if (keycode == 97 && check_movements(vars, 1) > 0)
		vars->pos_x -= 16;
	if (old_x != vars->pos_x || old_y != vars->pos_y)
		render_mvt(vars, old_x, old_y);
	if (collect_and_finish(vars) == 1)
		on_destroy(vars);
	return (0);
}

static int	init(t_vars *vars, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (print_error(6));
	vars->moves = 0;
	vars->coins = 0;
	vars->pos_x = -1;
	vars->pos_y = -1;
	make_map(vars);
	if (check_path(vars) == -1)
		return (-1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->pos_x, vars->pos_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map;
	int		i;
	int		j;
	int		fd;

	if (argc != 2)
		return (print_error(6));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(6));
	if (create_map(&map, fd, argv[1]) == -1)
		return (-1);
	vars.map = map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map.lenght * 16,
			map.height * 16, "so_long");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./textures/singe.xpm", &i, &j);
	if (init(&vars, argv[1]) == -1)
		on_destroy(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 17, 1L << 0, on_destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
