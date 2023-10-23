/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_component.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:20:57 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 17:14:46 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	distance_between_two_hits(t_map *map_v)
{
	map_v->distance_v = sqrt(pow((map_v->vert_wall_hit_x - map_v->x_player), 2)
			+ pow((map_v->vert_wall_hit_y - map_v->y_player), 2));
	map_v->distance_h = sqrt(pow((map_v->hort_wall_hit_x - map_v->x_player), 2)
			+ pow((map_v->hort_wall_hit_y - map_v->y_player), 2));
	if (map_v->distance_v > map_v->distance_h)
	{
		map_v->distance_of_ray = map_v->distance_h;
		return (0);
	}
	else
	{
		map_v->distance_of_ray = map_v->distance_v;
		return (1);
	}
}

void	normalize_angle(double ray_angle)
{
	while (ray_angle < MIN_ANGLE)
		ray_angle += MAX_ANGLE;
	while (ray_angle > MAX_ANGLE)
		ray_angle -= MAX_ANGLE;
}

void	select_vertical_texture(t_map *map_v, double ray_angle)
{
	map_v->wall_hit_x = map_v->vert_wall_hit_x;
	map_v->wall_hit_y = map_v->vert_wall_hit_y;
	if (cos(ray_angle) < 0)
	{
		map_v->text_id = 2;
		map_v->text_width = map_v->canvas_width[2];
		map_v->text_height = map_v->canvas_height[2];
	}
	else
	{
		map_v->text_id = 3;
		map_v->text_width = map_v->canvas_width[3];
		map_v->text_height = map_v->canvas_height[3];
	}
	map_v->x_offset_texture = (int)map_v->wall_hit_y % (map_v->text_height);
}

void	select_horizontal_texture(t_map *map_v, double ray_angle)
{
	map_v->wall_hit_x = map_v->hort_wall_hit_x;
	map_v->wall_hit_y = map_v->hort_wall_hit_y;
	if (sin(ray_angle) < 0)
	{
		map_v->text_id = 0;
		map_v->text_height = map_v->canvas_height[0];
		map_v->text_width = map_v->canvas_width[0];
	}
	else
	{
		map_v->text_id = 1;
		map_v->text_height = map_v->canvas_height[1];
		map_v->text_width = map_v->canvas_width[1];
	}
	map_v->x_offset_texture = (int)map_v->wall_hit_x % (map_v->text_width);
}

void	render_all_component(t_map *map_v)
{
	double	ray_angle;
	int		i;

	i = 0;
	ray_angle = map_v->player_angle - (map_v->field_of_view / 2);
	while (i < map_v->num_rays)
	{
		normalize_angle(ray_angle);
		fetch_wall_hit_h(map_v, ray_angle);
		fetch_wall_hit_v(map_v, ray_angle);
		if (distance_between_two_hits(map_v) == 1)
			select_vertical_texture(map_v, ray_angle);
		else
			select_horizontal_texture(map_v, ray_angle);
		map_v->distance_of_ray = map_v->distance_of_ray \
			* cos(ray_angle - map_v->player_angle);
		render_3d_textures(map_v, i);
		ray_angle += map_v->field_of_view / map_v->num_rays;
		i++;
	}
}
