/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:30:28 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 03:02:49 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_map *map_v)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	i = map_v->y_player / map_v->size_of_sq;
	j = map_v->x_player / map_v->size_of_sq;
	new_i = (map_v->y_player + ((sin(map_v->player_angle) \
		* map_v->move_speed))) / map_v->size_of_sq;
	new_j = (map_v->x_player + ((cos(map_v->player_angle) \
		* map_v->move_speed))) / map_v->size_of_sq;
	if (new_i < (map_v->map_height / map_v->size_of_sq_map)
		&& new_j < (map_v->map_width / map_v->size_of_sq_map))
	{
		if (map_v->map[new_i][new_j] == '\0' || map_v->map[new_i][j] == '1'
			|| map_v->map[i][new_j] == '1' || map_v->map[new_i][new_j] == '1')
			return ;
		else
		{
			map_v->y_player += (sin(map_v->player_angle) * map_v->move_speed);
			map_v->x_player += (cos(map_v->player_angle) * map_v->move_speed);
		}
	}
}

void	move_down(t_map *map_v)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	i = map_v->y_player / map_v->size_of_sq;
	j = map_v->x_player / map_v->size_of_sq;
	new_i = (map_v->y_player - ((sin(map_v->player_angle) \
		* map_v->move_speed))) / map_v->size_of_sq;
	new_j = (map_v->x_player - ((cos(map_v->player_angle) \
		* map_v->move_speed))) / map_v->size_of_sq;
	if (new_i < (map_v->map_height / map_v->size_of_sq_map)
		&& new_j < (map_v->map_width / map_v->size_of_sq_map))
	{
		if (map_v->map[new_i][new_j] == '\0' || map_v->map[new_i][j] == '1'
			|| map_v->map[i][new_j] == '1' || map_v->map[new_i][new_j] == '1')
			return ;
		else
		{
			map_v->y_player -= (sin(map_v->player_angle) * map_v->move_speed);
			map_v->x_player -= (cos(map_v->player_angle) * map_v->move_speed);
		}
	}
}

void	move_right(t_map *map_v)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	i = map_v->y_player / map_v->size_of_sq;
	j = map_v->x_player / map_v->size_of_sq;
	new_i = (map_v->y_player + ((sin(map_v->player_angle + M_PI_2) \
		* map_v->move_speed))) / map_v->size_of_sq;
	new_j = (map_v->x_player + ((cos(map_v->player_angle + M_PI_2) \
		* map_v->move_speed))) / map_v->size_of_sq;
	if (new_i < (map_v->map_height / map_v->size_of_sq_map)
		&& new_j < (map_v->map_width / map_v->size_of_sq_map))
	{
		if (map_v->map[new_i][new_j] == '\0' || map_v->map[new_i][j] == '1'
			|| map_v->map[i][new_j] == '1' || map_v->map[new_i][new_j] == '1')
			return ;
		else
		{
			map_v->y_player += (sin(map_v->player_angle + M_PI_2) \
				* map_v->move_speed);
			map_v->x_player += (cos(map_v->player_angle + M_PI_2) \
				* map_v->move_speed);
		}
	}
}

void	move_left(t_map *map_v)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	i = map_v->y_player / map_v->size_of_sq;
	j = map_v->x_player / map_v->size_of_sq;
	new_i = (map_v->y_player - ((sin(map_v->player_angle + M_PI_2) \
		* map_v->move_speed))) / map_v->size_of_sq;
	new_j = (map_v->x_player - ((cos(map_v->player_angle + M_PI_2) \
		* map_v->move_speed))) / map_v->size_of_sq;
	if (new_i < (map_v->map_height / map_v->size_of_sq_map)
		&& new_j < (map_v->map_width / map_v->size_of_sq_map))
	{
		if (map_v->map[new_i][new_j] == '\0' || map_v->map[new_i][j] == '1'
			|| map_v->map[i][new_j] == '1' || map_v->map[new_i][new_j] == '1')
			return ;
		else
		{
			map_v->y_player -= (sin(map_v->player_angle + M_PI_2) \
				* map_v->move_speed);
			map_v->x_player -= (cos(map_v->player_angle + M_PI_2) \
				* map_v->move_speed);
		}
	}
}

void	update_player_position(t_map *map_v)
{
	if (map_v->move_up == 1)
		move_up(map_v);
	else if (map_v->move_down == 1)
		move_down(map_v);
	else if (map_v->move_right == 1)
		move_right(map_v);
	else if (map_v->move_left == 1)
		move_left(map_v);
	else if (map_v->turn_left == 1)
	{
		map_v->player_angle -= map_v->rotation_speed;
		if (map_v->player_angle < MIN_ANGLE)
			map_v->player_angle += MAX_ANGLE;
	}
	else if (map_v->turn_right == 1)
	{
		map_v->player_angle += map_v->rotation_speed;
		if (map_v->player_angle >= MAX_ANGLE)
			map_v->player_angle -= MAX_ANGLE;
	}
}
