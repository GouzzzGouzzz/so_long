/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:58:30 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/31 17:17:26 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	put_string(t_vars *vars)
{
	char	*str_moves;
	char	*c_moves;
	void	*img;
	int		i;

	c_moves = ft_itoa(vars->moves);
	if (!c_moves)
		return ;
	str_moves = ft_strjoin("Moves: ", c_moves);
	free(c_moves);
	if (!str_moves)
		return ;
	img = mlx_xpm_file_to_image(vars->mlx, "./textures/bg_bonus.xpm", &i, &i);
	i = vars->map.lenght;
	while (i > 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img,
			i * 16, vars->map.height * 16);
		i--;
	}
	mlx_destroy_image(vars->mlx, img);
	mlx_string_put(vars->mlx, vars->win, 2, (vars->map.height + 0.75) * 16,
		200, str_moves);
	free(str_moves);
}

void	render_mvt(t_vars *vars, int old_x, int old_y)
{
	vars->moves++;
	if (vars->moves == -2147483648)
		vars->moves = 0;
	put_string(vars);
	place_tile(vars, old_x / 16, old_y / 16, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->pos_x, vars->pos_y);
}
