/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:21:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:05:18 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	lock_ccf(t_cc *f)
{
	if (f->lock == 0)
	{
		f->count++;
		f->lock = 1;
	}
}

void	skip_ws_ccf(t_cc *f, char c)
{
	while (c == ' ' || c == '\t')
		f->i++;
}

char	*ceiling_color_final(char *str)
{
	t_cc	*f;

	f = my_malloc(sizeof(t_cc));
	init_var_ccf(f, str);
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
			lock_ccf(f);
			f->ceiling[f->j] = str[f->i];
			f->i++;
			f->j++;
		}
		fill_ceiling_f(f, str, f->ceiling);
	}
	if (f->count != 3 || f->count1 != 2)
		return (NULL);
	f->ceiling[f->j] = '\0';
	return (f->ceiling);
}

void	init_var_mcc(t_cc1 *f, t_main *m)
{
	f->i = 0;
	f->r = -1;
	f->g = -1;
	f->b = -1;
	m->c->ceiling_color = ceiling_color_final(m->c->ceiling_color);
}

int	merge_ceiling_color(t_main *m)
{
	t_cc1	*f;

	f = my_malloc(sizeof(t_cc1));
	init_var_mcc(f, m);
	if (m->c->ceiling_color == NULL)
		return (-1);
	while (m->c->ceiling_color[f->i])
	{
		if (!cc_do_all(m, f))
			return (-1);
		if (f->i == ft_strlen2(ft_strtrim2(m->c->ceiling_color, " ", "\t")))
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
