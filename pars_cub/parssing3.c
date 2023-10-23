/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:46:59 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:56 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_sides(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (white_space(m->map[i][j]))
			j++;
		if ((m->map[i][j] != '1') || m->map[i][line_len(m->map[i]) - 1] != '1')
			sides_error();
		i++;
	}
}

int	white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\0' || c == '\t')
		return (1);
	return (0);
}

void	around_floor(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 1;
	while (m->map[i])
	{
		j = 1;
		while (m->map[i][j])
		{
			if ((m->map[i][j] == '0' || m->map[i][j] == 'N'
				|| m->map[i][j] == 'W' || m->map[i][j] == 'S'
				|| m->map[i][j] == 'E') && (white_space(m->map[i + 1][j])
				|| white_space(m->map[i - 1][j])
				|| white_space(m->map[i][j + 1])
				|| white_space(m->map[i][j - 1])))
				void_next_floor();
			j++;
		}
		i++;
	}
}

void	line_undef(t_main *m)
{
	int	i;
	int	j;
	int	count;
	int	frst_line;

	i = 0;
	j = 0;
	count = 0;
	frst_line = map_frst_line(m);
	while (m->map[i] && i < frst_line)
	{
		while (m->map[i][j] && m->map[i][j] != '\n')
		{
			if (!white_space(m->map[i][j]))
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count != 6)
		undefined_line_error();
}
