/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:03:19 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:05:03 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_vars_rgb(t_rgb	*r, t_main *m)
{
	r->i = 4;
	r->j = 0;
	r->f = 0;
	r->c = 0;
	m->c = my_malloc(sizeof(t_colors));
	m->c->ceiling_color = my_malloc(sizeof(char) * 100);
	m->c->floor_color = my_malloc(sizeof(char) * 100);
}

void	fill_floor_rgb(t_main *m, t_rgb *r)
{
	r->j++;
	while (m->map[r->i][r->j] && (m->map[r->i][r->j] == ' '
			|| m->map[r->i][r->j] == '\t'))
		r->j++;
	while (m->map[r->i][r->j] && m->map[r->i][r->j] != '\n')
	{
		m->c->floor_color[r->f] = m->map[r->i][r->j];
		r->f++;
		r->j++;
	}
	m->c->floor_color[r->f] = '\0';
	m->c->count_rgb++;
}

void	fill_ceiling_rgb(t_main *m, t_rgb *r)
{
	r->j++;
	while (m->map[r->i][r->j] && (m->map[r->i][r->j] == ' '
			|| m->map[r->i][r->j] == '\t'))
		r->j++;
	while (m->map[r->i][r->j] && m->map[r->i][r->j] != '\n')
	{
		m->c->ceiling_color[r->c] = m->map[r->i][r->j];
		r->c++;
		r->j++;
	}
	m->c->ceiling_color[r->c] = '\0';
	m->c->count_rgb++;
}

void	first_rgb(t_main *m, t_rgb *r)
{
	r->j = 0;
	while (m->map[r->i][r->j] && (m->map[r->i][r->j] == ' '
		|| m->map[r->i][r->j] == '\t'))
	{
		r->j++;
		if (m->map[r->i][r->j] == '\n')
			r->i++;
		if (m->map[r->i][r->j] == 'F')
			fill_floor_rgb(m, r);
		else if (m->map[r->i][r->j] == 'C')
			fill_ceiling_rgb(m, r);
	}
}

char	*floor_ceiling(t_main *m)
{
	t_rgb	*r;

	r = my_malloc(sizeof(t_rgb));
	init_vars_rgb(r, m);
	while (m->map[r->i] && r->i < map_frst_line(m))
	{
		first_rgb(m, r);
		if (m->map[r->i][r->j] == 'F')
			fill_floor_rgb(m, r);
		else if (m->map[r->i][r->j] == 'C')
			fill_ceiling_rgb(m, r);
		r->i++;
	}
	return (m->c->ceiling_color);
}
