/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:00 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/21 01:01:27 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical_x_calculation(t_map *map_v, t_wall *wall_v)
{
	wall_v->x_intersect = floor(map_v->x_player / map_v->size_of_sq) \
		* map_v->size_of_sq;
	wall_v->xstep = map_v->size_of_sq;
	if (wall_v->is_facing_right)
		wall_v->x_intersect += map_v->size_of_sq;
	if (!wall_v->is_facing_right)
	{
		wall_v->x_intersect -= 0.000000005;
		wall_v->xstep *= -1;
	}
	wall_v->x_distance = (wall_v->x_intersect - map_v->x_player);
}

void	vertical_y_calculation(t_map *map_v, t_wall *wall_v, double angle)
{
	if (wall_v->is_facing_up)
	wall_v->y_intersect = map_v->y_player \
		- fabs(fabs(wall_v->x_distance) * tan(angle));
	else
		wall_v->y_intersect = map_v->y_player \
			+ fabs(fabs(wall_v->x_distance) * tan(angle));
	wall_v->ystep = fabs(fabs(wall_v->xstep) * tan(angle));
	if (wall_v->is_facing_up)
		wall_v->ystep *= -1;
}

void	find_vertical_wall_hit(t_map *map_v, t_wall *wall_v)
{
	wall_v->i = floor(wall_v->y_intersect / map_v->size_of_sq);
	wall_v->j = floor(wall_v->x_intersect / map_v->size_of_sq);
	while (wall_v->x_intersect > 0 && wall_v->y_intersect < map_v->map_width
		&& wall_v-> y_intersect > 0 && wall_v->x_intersect < map_v->map_height)
	{
		if ((map_v->map[wall_v->i][wall_v->j]
			&& (map_v->map[wall_v->i][wall_v->j] == '1'))
			|| map_v->map[wall_v->i][wall_v->j] == '\0')
		{
			map_v->find_vert_intersept = 1;
			break ;
		}
		wall_v->y_intersect += wall_v->ystep;
		wall_v->x_intersect += wall_v->xstep;
		wall_v->i = floor(wall_v->y_intersect / map_v->size_of_sq);
		wall_v->j = floor(wall_v->x_intersect / map_v->size_of_sq);
	}
	map_v->vert_wall_hit_x = wall_v->x_intersect;
	map_v->vert_wall_hit_y = wall_v->y_intersect;
}

void	fetch_wall_hit_v(t_map *map_v, double angle)
{
	t_wall	wall_v;

	map_v->find_vert_intersept = 0;
	map_v->wall_hit_x = 0;
	map_v->wall_hit_y = 0;
	wall_v.y_intersect = 0;
	wall_v.is_facing_up = sin(angle) < 0;
	wall_v.is_facing_right = cos(angle) > 0;
	vertical_x_calculation(map_v, &wall_v);
	vertical_y_calculation(map_v, &wall_v, angle);
	find_vertical_wall_hit(map_v, &wall_v);
}
