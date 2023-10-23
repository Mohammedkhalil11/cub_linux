/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:48:59 by mokhalil          #+#    #+#             */
/*   Updated: 2023/10/20 03:12:24 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*line_count_dy(char **m)
{
	int	*i;
	int	j;

	i = my_malloc(sizeof(int) * 2);
	i[0] = 0;
	if (!m)
		return (0);
	j = line_len(m[i[0]]);
	while (m[i[0]])
	{
		i[1] = line_len(m[i[0]]);
		if (j > i[1])
			i[1] = j;
		else
			j = i[1];
		i[0]++;
	}
	return (i);
}

char	**get_map(t_main *m)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = map_frst_line(m);
	map = (char **)my_malloc(sizeof(char *) * (line_count(m) - i + 2));
	while (m->map[i])
	{
		map[k] = my_malloc(line_len(m->map[i]) + 1);
		j = 0;
		while (j < line_len(m->map[i]))
		{
			map[k][j] = m->map[i][j];
			j++;
		}
		map[k][j] = '\0';
		k++;
		i++;
	}
	map[k] = NULL;
	return (map);
}

void	fill_new_string(int dimension, char **map1, char **map, int i)
{
	int	j;

	map1[i] = my_malloc (dimension + 1);
	j = 0;
	while (map[i][j])
	{
		map1[i][j] = map[i][j];
		j++;
	}
	while (j < dimension)
	{
		map1[i][j] = '\0';
		j++;
	}
}

char	**resize_map(char **map, int *dimensions)
{
	char	**map1;
	int		i;

	map1 = my_malloc(sizeof(char *) * (dimensions[0] + 1));
	i = 0;
	while (map[i])
	{
		map1[i] = 0;
		if (line_len(map[i]) < dimensions[1])
			fill_new_string(dimensions[1], map1, map, i);
		else
			map1[i] = map[i];
		i++;
	}
	map1[i] = NULL;
	return (map1);
}
