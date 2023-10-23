/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:18:43 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 03:02:49 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fetch_player_position(t_map *map_v)
{
	int	i;
	int	j;

	i = 0;
	while (map_v->map[i])
	{
		j = 0;
		while (map_v->map[i][j])
		{
			if (map_v->map[i][j] == 'N' || map_v->map[i][j] == 'S'
				|| map_v->map[i][j] == 'E' || map_v->map[i][j] == 'W')
			{
				map_v->x_player = j * map_v->size_of_sq + \
					(map_v->size_of_sq / 2);
				map_v->y_player = i * map_v->size_of_sq + \
					(map_v->size_of_sq / 2);
			}
			j++;
		}
		i++;
	}
}

void	render_ceil(t_map *vars, int k, double l)
{
	double	i;
	double	j;

	i = (double)k * vars->wall_width;
	while (i < vars->windows_width
		&& i < (double)((k + 1) * vars->wall_width) && i >= 0)
	{
		j = 0;
		while (j < (double)vars->windows_height && j < l && j >= 0)
		{
			my_mlx_pixel_put(vars->img, i, j, vars->ceil_color);
			j += 1;
		}
		i += 1;
	}
}

void	render_wall(t_map *vars, int k, double l, double wall_height)
{
	double	i;
	double	j;
	int		color;

	i = (double)k * vars->wall_width;
	while (i < vars->windows_width
		&& i < (double)((k + 1) * vars->wall_width) && i >= 0)
	{
		j = l;
		if (j < 0)
			j = 0;
		while (j < (double)vars->windows_height
			&& j < l + wall_height && j >= 0)
		{
			vars->y_offset_texture = (j - l) \
				* (vars->text_height / wall_height);
			color = get_color_texture(vars->text, vars->x_offset_texture,
					vars->y_offset_texture, vars);
			my_mlx_pixel_put(vars->img, i, j, color);
			j += 1;
		}
		i += 1;
	}
}

void	render_floor(t_map *vars, int k, double l, double wall_height)
{
	double	i;
	double	j;

	i = (double)k * vars->wall_width;
	while (i < vars->windows_width
		&& i < (double)((k + 1) * vars->wall_width) && i >= 0)
	{
		j = l + wall_height;
		while (j < (double)vars->windows_height && j >= 0)
		{
			my_mlx_pixel_put(vars->img, i, j, vars->floor_color);
			j += 1;
		}
		i += 1;
	}
}

void	render_3d_textures(t_map *vars, int k)
{
	double	wall_height;
	double	distance_player_from_wall_projection;
	double	l;

	distance_player_from_wall_projection = (vars->windows_width / 2) \
		/ (tan(vars->field_of_view / 2));
	wall_height = ((double)vars->size_of_sq \
		* distance_player_from_wall_projection) / vars->distance_of_ray;
	l = (vars->windows_height / 2) - (wall_height / 2);
	render_ceil(vars, k, l);
	render_wall(vars, k, l, wall_height);
	render_floor(vars, k, l, wall_height);
}
