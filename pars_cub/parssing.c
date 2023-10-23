/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:38 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:46 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	where_to_stop(t_main *m)
{
	int	i;

	i = 0;
	while (m->str[i])
	{
		if (m->str[i] == '\n')
		{
			while (white_space(m->str[i]))
				i++;
			if (m->str[i] == '1')
				return (i);
		}
		i++;
	}
	return (0);
}

void	new_line_inside(t_main *m)
{
	int	i;
	int	last;

	i = ft_strlen(m->str);
	last = where_to_stop(m);
	while (i >= last)
	{
		if (m->str[i] == '\n' && m->str[i - 1] == '\n')
			empty_line_inside();
		i--;
	}
}

int	map_first_line(t_main *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_frst_line(t_main *m)
{
	int	i;
	int	j;

	i = map_first_line(m) + 1;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j] && (m->map[i][j] == ' ' || m->map[i][j] == '\t'))
			j++;
		if (m->map[i][j] == '1' || m->map[i][j] == 32 || m->map[i][j] == '\t')
		{
			while ((m->map[i][j] == '1' || m->map[i][j] == 32 ||
				m->map[i][j] == '\t') && m->map[i][j])
			{
				j++;
				if (!m->map[i][j] || m->map[i][j] == '\n')
					return (i);
			}
			horinzontal_error();
		}
		i++;
	}
	return (0);
}
