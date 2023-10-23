/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:08:33 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:25 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	for_north(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'N' && m->map[dir->i][dir->j + 1] == 'O')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->north_path[dir->n] = m->map[dir->i][dir->j];
			dir->n++;
			dir->j++;
		}
		m->p->north_path[dir->n] = '\0';
		m->p->count_paths++;
	}
}

void	for_south(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'S' && m->map[dir->i][dir->j + 1] == 'O')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->south_path[dir->s] = m->map[dir->i][dir->j];
			dir->s++;
			dir->j++;
		}
		m->p->south_path[dir->s] = '\0';
		m->p->count_paths++;
	}
}

void	for_west(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'W' && m->map[dir->i][dir->j + 1] == 'E')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->west_path[dir->w] = m->map[dir->i][dir->j];
			dir->w++;
			dir->j++;
		}
		m->p->west_path[dir->w] = '\0';
		m->p->count_paths++;
	}
}

void	for_east(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'E' && m->map[dir->i][dir->j + 1] == 'A')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->east_path[dir->e] = m->map[dir->i][dir->j];
			dir->e++;
			dir->j++;
		}
		m->p->east_path[dir->e] = '\0';
		m->p->count_paths++;
	}
}
