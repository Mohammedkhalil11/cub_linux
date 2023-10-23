/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyt_mkh7 <buyt_mkh7@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:54:43 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/22 22:15:58 by buyt_mkh7        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_game(t_map *map_v, t_data *img, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	img->img = mlx_new_image(mlx->mlx,
			map_v->windows_width, map_v->windows_height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	mlx->win = mlx_new_window(mlx->mlx,
			map_v->windows_width, map_v->windows_height, "la fac");
	fetch_player_position(map_v);
	initialize_player_angle(map_v);
	map_v->mlx = mlx;
	map_v->img = img;
}

int	handle_mouse_move(int x, int y, t_map *map_v)
{
	int	delta_x;

	(void)y;
	if (map_v->prev_x != -1)
	{
		delta_x = x - map_v->prev_x;
		map_v->player_angle += delta_x * 0.0075;
		if (map_v->player_angle < 0)
			map_v->player_angle += 2 * M_PI;
		else if (map_v->player_angle >= 2 * M_PI)
			map_v->player_angle -= 2 * M_PI;
	}
	map_v->prev_x = x;
	update_map(map_v);
	return (0);
}
