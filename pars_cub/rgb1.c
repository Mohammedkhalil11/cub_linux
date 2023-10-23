/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:00:49 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:05:10 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	lock_fcf(t_fc *f)
{
	if (f->lock == 0)
	{
		f->count++;
		f->lock = 1;
	}
}

void	skip_ws_fcf(t_fc *f, char c)
{
	while (c == ' ' || c == '\t')
		f->i++;
}

char	*floor_color_final(char *str)
{
	t_fc	*f;

	f = my_malloc(sizeof(t_fc));
	init_var_fcf(f, str);
	while (str[f->i])
	{
		f->lock = 0;
		if (!ft_isdigit(str[f->i]) && str[f->i] != ' '
			&& str[f->i] != '\t' && str[f->i] != ',')
			return (NULL);
		while (str[f->i] == ' ' || str[f->i] == '\t')
			f->i++;
		while (ft_isdigit(str[f->i]))
		{
			lock_fcf(f);
			f->floor[f->j] = str[f->i];
			f->i++;
			f->j++;
		}
		fill_floor_f(f, str, f->floor);
	}
	if (f->count != 3 || f->count1 != 2)
		return (NULL);
	f->floor[f->j] = '\0';
	return (f->floor);
}

void	init_var_mfc(t_fc1 *f, t_main *m)
{
	f->i = 0;
	f->r = -1;
	f->g = -1;
	f->b = -1;
	m->c->floor_color = floor_color_final(m->c->floor_color);
}

int	merge_floor_color(t_main *m)
{
	t_fc1	*f;

	f = my_malloc(sizeof(t_fc1));
	init_var_mfc(f, m);
	if (m->c->floor_color == NULL)
		return (-1);
	while (m->c->floor_color[f->i])
	{
		if (!fc_do_all(m, f))
			return (-1);
		if (f->i == ft_strlen2(ft_strtrim2(m->c->floor_color, " ", "\t")))
		{
			if (f->r == -1 || f->g == -1 || f->b == -1
				|| f->r >= 256 || f->g >= 256
				|| f->b >= 256)
				return (-1);
			return ((f->r << 16) | (f->g << 8) | f->b);
		}
		f->i++;
	}
	if (f->r == -1 || f->g == -1 || f->b == -1)
		return (-1);
	return (0);
}
