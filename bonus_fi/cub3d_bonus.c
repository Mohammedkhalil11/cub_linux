/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:43:19 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/21 00:47:32 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../cub3d.h"

int	init_main(t_main *m, char **av)
{
	m->count = 1;
	m->fd = open(av[1], O_RDWR);
	check_check(m);
	new_line_inside(m);
	if (!m->str)
		return (0);
	create_map(m);
	items_check(m);
	return (1);
}

void	initialize_player_angle(t_map *map_v)
{
	int	i;
	int	j;

	i = map_v->y_player / map_v->size_of_sq;
	j = map_v->x_player / map_v->size_of_sq;
	if (map_v->map[i][j] == 'N')
		map_v->player_angle = 1.5 * M_PI;
	else if (map_v->map[i][j] == 'S')
		map_v->player_angle = 0.5 * M_PI;
	else if (map_v->map[i][j] == 'E')
		map_v->player_angle = 0;
	else if (map_v->map[i][j] == 'W')
		map_v->player_angle = M_PI;
}

void	initialize_vars(t_map *map_v, t_main *m)
{	
	map_v->map = get_map(m);
	map_v->x = 0;
	map_v->y = 0;
	map_v->move_up = 0;
	map_v->move_down = 0;
	map_v->move_left = 0;
	map_v->move_right = 0;
	map_v->turn_left = 0;
	map_v->turn_right = 0;
	map_v->x_player = 0;
	map_v->y_player = 0;
	map_v->move_speed = 40;
	map_v->size_of_sq = 650;
	map_v->size_of_sq_map = 10;
	map_v->rotation_speed = (M_PI / 180);
	map_v->field_of_view = M_PI / 3;
	map_v->tab = line_count_dy(map_v->map);
	map_v->map_height = ((map_v->tab[1]) * map_v->size_of_sq);
	map_v->map_width = ((map_v->tab[0]) * map_v->size_of_sq);
	map_v->windows_height = 1000;
	map_v->windows_width = 1000;
	map_v->wall_width = 1;
	map_v->num_rays = map_v->windows_width / map_v->wall_width;
	map_v->map = resize_map(map_v->map, map_v->tab);
}

int	main(int ac, char **av)
{
	t_map	map_v;
	t_mlx	mlx;
	t_data	img;
	t_main	*m;

	if (ac != 2)
		exit(1);
	check_name(av[1]);
	m = my_malloc(sizeof(t_main));
	if (!init_main(m, av))
		return (0);
	map_v.map_size = 150;
	initialize_vars(&map_v, m);
	init_game(&map_v, &img, &mlx);
	loading_all_textures(&map_v, m);
	render_all_component(&map_v);
	map_v.prev_x = -1;
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, key_hook, &map_v);
	mlx_hook(mlx.win, 3, 1L << 1, key_reales, &map_v);
	mlx_hook(mlx.win, 6, (1L << 6), handle_mouse_move, &map_v);
	mlx_loop_hook(map_v.mlx->mlx, update_map, &map_v);
	mlx_loop(mlx.mlx);
}
