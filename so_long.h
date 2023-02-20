/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:16:37 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/12 13:00:00 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"

typedef struct queue{
	int		*coord;
	int		front;
	int		rear;
}			t_queue;

typedef struct pathfinder{
	int		*reached;
	int		index;
	int		doable;
	t_queue	queue;
}			t_pathfinder;

typedef struct map{
	char	**map;
	int		error_code;
	size_t	lenght;
	size_t	height;
}			t_map;

typedef struct game{
	void	*mlx;
	void	*win;
	void	*img;
	int		pos_x;
	int		pos_y;
	int		coins;
	int		moves;
	t_map	map;
}			t_vars;

int		create_map(t_map *arr, int fd, char *map_name);
int		check_all(t_map *arr);
int		check_movements(t_vars *vars, int mvt);
int		collect_and_finish(t_vars *vars);
int		close_window(int keycode, t_vars *vars);
int		on_destroy(t_vars *vars);
int		is_in_set(char c, char *set);
int		print_error(int code);
int		check_path(t_vars *vars);
int		queue_init(t_queue *list, int size);
int		queue_status(t_queue *list);
int		not_reached(t_pathfinder *path, int x, int y);
int		check_ext(char *map_name);
int		*dequeue(t_queue *list);
void	set_player_pos(t_vars *vars, int x, int y);
void	make_map(t_vars *vars);
void	place_tile(t_vars *vars, int x, int y, int init);
void	render_mvt(t_vars *vars, int old_x, int old_y);
void	clear_map(t_map *arr);
void	enqueue(int *elt, t_queue *list);
void	add_node(int x, int y, t_pathfinder *path, t_vars *vars);
#endif
