/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_paths_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:08:33 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:21 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dir_var_init(t_dir *dir)
{
	dir->i = 0;
	dir->j = 0;
	dir->n = 0;
	dir->s = 0;
	dir->w = 0;
	dir->e = 0;
}

void	allocat_dir(t_main *m)
{
	m->p->north_path = my_malloc(sizeof(char) * 100);
	m->p->south_path = my_malloc(sizeof(char) * 100);
	m->p->west_path = my_malloc(sizeof(char) * 100);
	m->p->east_path = my_malloc(sizeof(char) * 100);
}

void	call_dir(t_main *m, t_dir *dir)
{
	for_north(m, dir);
	for_south(m, dir);
	for_west(m, dir);
	for_east(m, dir);
}

char	*dir_path(t_main *m)
{
	t_dir	*dir;

	dir = my_malloc(sizeof(t_dir));
	m->p = my_malloc(sizeof(t_paths));
	allocat_dir(m);
	dir_var_init(dir);
	while (m->map[dir->i] && dir->i < map_frst_line(m))
	{
		dir->j = 0;
		while (m->map[dir->i][dir->j] == ' ' || m->map[dir->i][dir->j] == '\t')
		{
			dir->j++;
			if (m->map[dir->i][dir->j] == '\n')
				dir->i++;
			call_dir(m, dir);
		}
		call_dir(m, dir);
		dir->i++;
	}
	return (NULL);
}
