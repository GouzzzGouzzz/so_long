/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:54:52 by nmorandi          #+#    #+#             */
/*   Updated: 2023/02/07 16:08:29 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	queue_init(t_queue *list, int size)
{
	list->rear = 0;
	list->front = 0;
	list->coord = malloc(sizeof(int) * (size * 2));
	if (!list->coord)
		return (-1);
	return (0);
}

void	enqueue(int *elt, t_queue *list)
{
	if (!elt)
		return ;
	list->coord[list->rear] = elt[0];
	list->coord[list->rear + 1] = elt[1];
	list->rear += 2;
}

int	*dequeue(t_queue *list)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	if (!coord)
		return (NULL);
	coord[0] = list->coord[list->front];
	coord[1] = list->coord[list->front + 1];
	list->front += 2;
	return (coord);
}

int	queue_status(t_queue *list)
{
	if (list->rear == list->front)
		return (1);
	return (0);
}
