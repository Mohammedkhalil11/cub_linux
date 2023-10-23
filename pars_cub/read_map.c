/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:29:52 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:59 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		bsread;

	buff = my_malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bsread = 1;
	while (bsread != 0)
	{
		bsread = read(fd, buff, BUFFER_SIZE);
		if (bsread == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bsread] = '\0';
		str = ft_strjoin1(str, buff);
	}
	free(buff);
	return (str);
}

void	init_var_fcf(t_fc	*f, char *str)
{
	f->i = 0;
	f->j = 0;
	f->lock = 0;
	f->count = 0;
	f->count1 = 0;
	f->floor = my_malloc(sizeof(char) * ft_strlen(str) * 10);
}

void	fill_floor_f(t_fc *f, char *str, char *floor)
{
	if (str[f->i] == ',' || str[f->i] == ' ' || str[f->i] == '\t')
	{
		if (str[f->i] == ',')
			f->count1++;
		floor[f->j] = str[f->i];
		f->i++;
		f->j++;
	}
}

void	init_var_ccf(t_cc	*f, char *str)
{
	f->i = 0;
	f->j = 0;
	f->lock = 0;
	f->count = 0;
	f->count1 = 0;
	f->ceiling = my_malloc(sizeof(char) * ft_strlen(str) * 10);
}

void	fill_ceiling_f(t_cc *f, char *str, char *ceiling)
{
	if (str[f->i] == ',' || str[f->i] == ' ' || str[f->i] == '\t')
	{
		if (str[f->i] == ',')
			f->count1++;
		ceiling[f->j] = str[f->i];
		f->i++;
		f->j++;
	}
}
