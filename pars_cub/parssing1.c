/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:35:27 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:49 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	items_check(t_main *m)
{
	if (m->map[0] == NULL)
		exit (1);
	line_undef(m);
	map_check_first(m);
	check_sides(m);
	map_check_last(m);
	around_floor(m);
	invalid_item(m);
	if (((dir_path(m) == NULL) && m->p->count_paths != 4) || (!m->p->north_path
			||!m->p->south_path || !m->p->west_path || !m->p->east_path))
		path_error();
	else if ((floor_ceiling(m) == NULL && m->c->count_rgb != 2))
		color_error();
	m->c->ceiling = merge_ceiling_color(m);
	m->c->floor = merge_floor_color(m);
	if (m->c->floor == -1 || m->c->ceiling == -1)
		color_error();
	p_check(m);
}

int	line_count(t_main *m)
{
	int	i;

	i = 0;
	if (!m->map)
		return (0);
	while (m->map[i])
		i++;
	i--;
	return (i);
}

int	line_len(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j])
		j++;
	if (s[j - 1] == 32 || s[j - 1] == '\t')
	{
		j--;
		while (s[j] == 32 || s[j] == '\t')
			j--;
	}
	return (j);
}

int	map_check_first(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 0;
	if (!m->map || !*m->map)
		return (0);
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1' && m->map[i][j] != ' ' && m->map[i][j] != '\t')
			horinzontal_error();
		j++;
	}
	return (j);
}

int	map_check_last(t_main *m)
{
	int	i;
	int	j;

	j = 0;
	if (!m->map || !*m->map)
		return (0);
	i = line_count(m);
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1' && m->map[i][j] != ' ' && m->map[i][j] != '\t')
			horinzontal_error();
		j++;
	}
	return (j);
}
