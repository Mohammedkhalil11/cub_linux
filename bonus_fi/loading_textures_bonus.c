/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyt_mkh7 <buyt_mkh7@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 04:37:49 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/22 22:05:56 by buyt_mkh7        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loading_north_text(t_map *map_v, t_main *m)
{
	map_v->text[0].text_wall = mlx_xpm_file_to_image(map_v->mlx->mlx,
			m->p->north_path, &map_v->canvas_width[0],
			&map_v->canvas_height[0]);
	if (!map_v->text[0].text_wall)
	{
		write(2, "Error: textures\n", 17);
		exit(1);
	}
	map_v->text[0].buffer = mlx_get_data_addr(map_v->text[0].text_wall,
			&map_v->text[0].bits_per_pixel, &map_v->text[0].line_length,
			&map_v->text[0].endian);
}

void	loading_south_text(t_map *map_v, t_main *m)
{
	map_v->text[1].text_wall = mlx_xpm_file_to_image(map_v->mlx->mlx,
			m->p->south_path, &map_v->canvas_width[1],
			&map_v->canvas_height[1]);
	if (!map_v->text[1].text_wall)
	{
		write(2, "Error: textures\n", 17);
		exit(1);
	}
	map_v->text[1].buffer = mlx_get_data_addr(map_v->text[1].text_wall,
			&map_v->text[1].bits_per_pixel, &map_v->text[1].line_length,
			&map_v->text[1].endian);
}

void	loading_west_text(t_map *map_v, t_main *m)
{
	map_v->text[2].text_wall = mlx_xpm_file_to_image(map_v->mlx->mlx,
			m->p->west_path, &map_v->canvas_width[2],
			&map_v->canvas_height[2]);
	if (!map_v->text[2].text_wall)
	{
		write(2, "Error: textures\n", 17);
		exit(1);
	}
	map_v->text[2].buffer = mlx_get_data_addr(map_v->text[2].text_wall,
			&map_v->text[2].bits_per_pixel, &map_v->text[2].line_length,
			&map_v->text[2].endian);
}

void	loading_east_text(t_map *map_v, t_main *m)
{
	map_v->text[3].text_wall = mlx_xpm_file_to_image(map_v->mlx->mlx,
			m->p->east_path, &map_v->canvas_width[3],
			&map_v->canvas_height[3]);
	if (!map_v->text[3].text_wall)
	{
		write(2, "Error: textures\n", 17);
		exit(1);
	}
	map_v->text[3].buffer = mlx_get_data_addr(map_v->text[3].text_wall,
			&map_v->text[3].bits_per_pixel, &map_v->text[3].line_length,
			&map_v->text[3].endian);
}

void	loading_all_textures(t_map *map_v, t_main *m)
{
	loading_north_text(map_v, m);
	loading_south_text(map_v, m);
	loading_west_text(map_v, m);
	loading_east_text(map_v, m);
	map_v->floor_color = m->c->floor;
	map_v->ceil_color = m->c->ceiling;
}
