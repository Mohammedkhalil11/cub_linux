/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:27:54 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:13:50 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static void	free_all(char **str)
{
	while (*str)
		free(*str++);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		x;
	int		l;

	i = 0;
	l = -1;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (words_count((char *)s, c) + 1));
	if (!ptr)
		return (NULL);
	while (++l < words_count((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		x = i;
		while (s[i] != c && s[i])
			i++;
		ptr[l] = ft_substr(s, x, i - x);
		if (!ptr[l])
			return (free_all(ptr), NULL);
	}
	return (ptr[l] = NULL, ptr);
}
