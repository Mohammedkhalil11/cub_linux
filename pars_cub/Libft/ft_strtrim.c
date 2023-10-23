/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:53 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/19 01:39:31 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_set2(char c, char *set, char *set2)
{
	int	i;

	i = 0;
	while (set[i] && set2[i])
	{
		if (c == set[i] || c == set2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;

	if (!s1 || !set)
		return (0);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_set(s1[first], set))
		first++;
	while (last > 0 && ft_set(s1[last], set))
		last--;
	if (last == -1)
		return (ft_substr(s1, first, 0));
	return (ft_substr(s1, first, (last - first + 1)));
}

char	*ft_strtrim2(char *s1, char *set, char *set2)
{
	int	first;
	int	last;

	if (!s1 || !set)
		return (0);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_set2(s1[first], set, set2))
		first++;
	while (last > 0 && ft_set2(s1[last], set, set2))
		last--;
	if (last == -1)
		return (ft_substr(s1, first, 0));
	return (ft_substr(s1, first, (last - first + 1)));
}
