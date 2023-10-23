/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyt_mkh7 <buyt_mkh7@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:08:39 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/22 22:13:12 by buyt_mkh7        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_walls(t_map *map_v, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < map_v->size_of_sq_map)
	{
		j = 0;
		while (j < map_v->size_of_sq_map)
		{
			if (i == map_v->size_of_sq_map - 1
				|| j == map_v->size_of_sq_map - 1)
				my_mlx_pixel_put(img, map_v->x, j + map_v->y, 0x00000000);
			else
				my_mlx_pixel_put(img, map_v->x, j + map_v->y, 0x00FF0000);
			j++;
		}
		i++;
		map_v->x++;
	}
	map_v->last_position = j;
}

void	draw_floor(t_map *map_v, t_data *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < map_v->size_of_sq_map)
	{
		j = 0;
		while (j < map_v->size_of_sq_map)
		{
			if (i == map_v->size_of_sq_map - 1
				|| j == map_v->size_of_sq_map - 1)
				my_mlx_pixel_put(img, map_v->x, j + map_v->y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(img, map_v->x, j + map_v->y, 0x00000000);
			j++;
		}
	i++;
	map_v->x++;
	}
	map_v->last_position = j;
}

void	map_rendring(char *map, t_map *map_v, t_data *img)
{
	int	l;

	l = 0;
	while (map[l])
	{
		if (map[l] != '1')
			draw_floor(map_v, img);
		else
			draw_walls(map_v, img);
		l++;
	}
	map_v->x = 0;
	map_v->y += map_v->last_position;
}

void	render_player(t_map *map_v, t_data *img)
{
	int			k;
	int			l;
	double		x;
	double		y;

	x = map_v->map_size / 2;
	y = map_v->map_size / 2;
	k = 0;
	while (k < 4)
	{
		l = 0;
		while (l < 4)
		{
			my_mlx_pixel_put(img, x - 2 + k,
				y - 2 + l, 0x0000F0A5);
			l++;
		}
		k++;
	}
}

int	creat_map(t_map *map_v, t_data *img)
{
	int		k;

	map_v->img2.img = mlx_new_image(map_v->mlx->mlx,
			map_v->map_width, map_v->map_height);
	map_v->img2.addr = mlx_get_data_addr(map_v->img2.img,
			&map_v->img2.bits_per_pixel,
			&map_v->img2.line_length, &map_v->img2.endian);
	k = 0;
	while (map_v->map[k])
	{
		map_rendring(map_v->map[k], map_v, &map_v->img2);
		k++;
	}
	copy_map(img, &map_v->img2, map_v);
	render_player(map_v, img);
	mlx_destroy_image(map_v->mlx->mlx, map_v->img2.img);
	return (1);
}
