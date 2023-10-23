/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:47:45 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 07:31:59 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_pixel(t_data *img2, int i, int j, t_map *map_v)
{
	char	*dst;
	int		x;
	int		y;

	x = (((map_v->x_player / map_v->size_of_sq) \
		* map_v->size_of_sq_map) - (map_v->map_size / 2)) + i;
	y = (((map_v->y_player / map_v->size_of_sq) \
		* map_v->size_of_sq_map) - (map_v->map_size / 2)) + j;
	if (x >= 0 && x < map_v->map_width \
	&& y >= 0 && y < map_v->map_height)
	{
		dst = img2->addr + \
		((y * img2->line_length) + \
			(x * (img2->bits_per_pixel / 8)));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	copy_map(t_data *img, t_data *img2, t_map *map_v)
{
	int	i;
	int	j;

	j = 0;
	while (j < map_v->map_size)
	{
		i = 0;
		while (i < map_v->map_size)
		{
			my_mlx_pixel_put(img, i, j, get_map_pixel(img2, i, j, map_v));
			i++;
		}
		j++;
	}
}

int	get_color_texture(t_tex *tex, int x, int y, t_map *map_v)
{
	char	*dst;

	if (x >= 0 && x < map_v->text_width \
	&& y >= 0 && y < map_v->text_height)
	{
		dst = tex[map_v->text_id].buffer + \
		((y * tex[map_v->text_id].line_length) + \
			(x * (tex[map_v->text_id].bits_per_pixel / 8)));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
