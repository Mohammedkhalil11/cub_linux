/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:39:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:52 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	invalid_item(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 1;
	while (++i < line_count(m))
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] != '1' && m->map[i][j] != '0'
				&& (m->map[i][j] != 'N' && m->map[i][j] != 'S'
				&& m->map[i][j] != 'E' && m->map[i][j] != 'W')
				&& m->map[i][j] != ' ' && m->map[i][j] != '\t')
				invalid_item_error();
		}
	}
}

int	p_check(t_main *m)
{
	int	i;
	int	j;
	int	count;

	i = map_frst_line(m);
	j = 1;
	count = 0;
	while (++i < line_count(m))
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'N' || m->map[i][j] == 'S'
				|| m->map[i][j] == 'E' || m->map[i][j] == 'W')
			{
				m->pos_y = i;
				m->pos_x = j;
				count++;
			}
		}
	}
	if (count != 1)
		duplicated_player_error();
	return (1);
}

void	check_check(t_main *m)
{
	if (m->fd == -1)
	{
		perror("error");
		exit(1);
	}
	m->str = NULL;
	m->str = ft_read_str(m->fd, m->str);
}

void	check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (ft_strncmp(&name[i], ".cub") != 0)
		arg_error();
}
