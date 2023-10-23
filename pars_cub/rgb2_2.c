/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:15:45 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:05:14 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cc_skip(t_main *m, t_cc1 *f)
{
	while (m->c->ceiling_color[f->i] == ' ' || m->c->ceiling_color[f->i] == '\t'
		|| m->c->ceiling_color[f->i] == ',')
		f->i++;
}

int	cc_first(t_main *m, t_cc1 *f)
{
	if (m->c->ceiling_color[f->i] >= '0' && m->c->ceiling_color[f->i] <= '9')
	{
		f->r = ft_atoi(&m->c->ceiling_color[f->i]);
		while (m->c->ceiling_color[f->i] != ',')
			f->i++;
		if (!(m->c->ceiling_color[f->i + 1] >= '0'
				&& m->c->ceiling_color[f->i + 1] <= '9')
			&& m->c->ceiling_color[f->i + 1] != ' '
			&& m->c->ceiling_color[f->i + 1] != '\t'
			&& m->c->ceiling_color[f->i + 1] != ',')
			return (0);
	}
	return (1);
}

int	cc_second(t_main *m, t_cc1 *f)
{
	if (m->c->ceiling_color[f->i] >= '0' && m->c->ceiling_color[f->i] <= '9')
	{
		f->g = ft_atoi(&m->c->ceiling_color[f->i]);
		while (m->c->ceiling_color[f->i] != ',')
			f->i++;
		if (!(m->c->ceiling_color[f->i + 1] >= '0'
				&& m->c->ceiling_color[f->i + 1] <= '9')
			&& m->c->ceiling_color[f->i + 1] != ' '
			&& m->c->ceiling_color[f->i + 1] != '\t'
			&& m->c->ceiling_color[f->i + 1] != ',')
			return (0);
	}
	return (1);
}

int	cc_third(t_main *m, t_cc1 *f)
{
	if (m->c->ceiling_color[f->i] >= '0' && m->c->ceiling_color[f->i] <= '9')
	{
		f->b = ft_atoi(&m->c->ceiling_color[f->i]);
		while (ft_isdigit(m->c->ceiling_color[f->i]))
			f->i++;
		if (m->c->ceiling_color[f->i + 1]
			|| !white_space(m->c->ceiling_color[f->i]))
			return (0);
	}
	return (1);
}

int	cc_do_all(t_main *m, t_cc1 *f)
{
	if (!cc_first(m, f))
		return (0);
	cc_skip(m, f);
	if (!cc_second(m, f))
		return (0);
	cc_skip(m, f);
	if (!cc_third(m, f))
		return (0);
	return (1);
}
