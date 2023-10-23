/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb1_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:45:16 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:05:07 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fc_skip(t_main *m, t_fc1 *f)
{
	while (m->c->floor_color[f->i] == ' ' || m->c->floor_color[f->i] == '\t'
		|| m->c->floor_color[f->i] == ',')
		f->i++;
}

int	fc_first(t_main *m, t_fc1 *f)
{
	if (m->c->floor_color[f->i] >= '0' && m->c->floor_color[f->i] <= '9')
	{
		f->r = ft_atoi(&m->c->floor_color[f->i]);
		while (m->c->floor_color[f->i] != ',')
			f->i++;
		if (!(m->c->floor_color[f->i + 1] >= '0'
				&& m->c->floor_color[f->i + 1] <= '9')
			&& m->c->floor_color[f->i + 1] != ' '
			&& m->c->floor_color[f->i + 1] != '\t'
			&& m->c->floor_color[f->i + 1] != ',')
			return (0);
	}
	return (1);
}

int	fc_second(t_main *m, t_fc1 *f)
{
	if (m->c->floor_color[f->i] >= '0' && m->c->floor_color[f->i] <= '9')
	{
		f->g = ft_atoi(&m->c->floor_color[f->i]);
		while (m->c->floor_color[f->i] != ',')
			f->i++;
		if (!(m->c->floor_color[f->i + 1] >= '0'
				&& m->c->floor_color[f->i + 1] <= '9')
			&& m->c->floor_color[f->i + 1] != ' '
			&& m->c->floor_color[f->i + 1] != '\t'
			&& m->c->floor_color[f->i + 1] != ',')
			return (0);
	}
	return (1);
}

int	fc_third(t_main *m, t_fc1 *f)
{
	if (m->c->floor_color[f->i] >= '0' && m->c->floor_color[f->i] <= '9')
	{
		f->b = ft_atoi(&m->c->floor_color[f->i]);
		while (ft_isdigit(m->c->floor_color[f->i]))
			f->i++;
		if (m->c->floor_color[f->i + 1]
			|| !white_space(m->c->floor_color[f->i]))
			return (0);
	}
	return (1);
}

int	fc_do_all(t_main *m, t_fc1 *f)
{
	if (!fc_first(m, f))
		return (0);
	fc_skip(m, f);
	if (!fc_second(m, f))
		return (0);
	fc_skip(m, f);
	if (!fc_third(m, f))
		return (0);
	return (1);
}
