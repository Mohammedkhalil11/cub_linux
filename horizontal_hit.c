/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:03:56 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/21 01:01:17 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizantal_y_calculation(t_map *map_v, t_wall *wall_v)
{
	wall_v->y_intersect = floor(map_v->y_player / map_v->size_of_sq) \
		* map_v->size_of_sq;
	wall_v->ystep = map_v->size_of_sq;
	if (wall_v->is_facing_down)
		wall_v->y_intersect += map_v->size_of_sq;
	else
	{
		wall_v->y_intersect -= 0.000000005;
		wall_v->ystep *= -1;
	}
	wall_v->y_distance = (wall_v->y_intersect - map_v->y_player);
}

void	horizantal_x_calculation(t_map *map_v, double angle, t_wall *wall_v)
{
	wall_v->xstep = fabs(fabs(wall_v->ystep) / tan(angle));
	if (wall_v->is_facing_left)
	{
		wall_v->x_intersect = map_v->x_player \
			- fabs(wall_v->y_distance / tan(angle));
		wall_v->xstep *= -1;
	}
	else
		wall_v->x_intersect = map_v->x_player \
			+ fabs(wall_v->y_distance / tan(angle));
}

void	find_horizantal_wall_hit(t_map *map_v, t_wall *wall_v)
{
	wall_v->i = floor(wall_v->y_intersect / map_v->size_of_sq);
	wall_v->j = floor(wall_v->x_intersect / map_v->size_of_sq);
	while (wall_v->x_intersect > 0 && wall_v->y_intersect < map_v->map_width
		&& wall_v->y_intersect > 0 && wall_v->x_intersect < map_v->map_height)
	{
		if ((map_v->map[wall_v->i][wall_v->j]
			&& map_v->map[wall_v->i][wall_v->j] == '1')
			|| map_v->map[wall_v->i][wall_v->j] == '\0')
		{
			map_v->find_hort_intersept = 1;
			break ;
		}
		wall_v->y_intersect += wall_v->ystep;
		wall_v->x_intersect += wall_v->xstep;
		wall_v->i = floor(wall_v->y_intersect / map_v->size_of_sq);
		wall_v->j = floor(wall_v->x_intersect / map_v->size_of_sq);
	}
	map_v->hort_wall_hit_x = wall_v->x_intersect;
	map_v->hort_wall_hit_y = wall_v->y_intersect;
}

void	fetch_wall_hit_h(t_map *map_v, double angle)
{
	t_wall	wall_v;

	map_v->find_hort_intersept = 0;
	map_v->wall_hit_x = 0;
	map_v->wall_hit_y = 0;
	wall_v.is_facing_down = sin(angle) >= 0;
	wall_v.is_facing_left = cos(angle) < 0;
	horizantal_y_calculation(map_v, &wall_v);
	horizantal_x_calculation(map_v, angle, &wall_v);
	find_horizantal_wall_hit(map_v, &wall_v);
}
