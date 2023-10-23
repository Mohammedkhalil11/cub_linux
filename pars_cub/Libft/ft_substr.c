/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:30:01 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/19 22:43:45 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;
	size_t	y;

	if (!s)
		return (0);
	i = 0;
	y = ft_strlen(s);
	if (len > y - start && y >= start)
		len = y - start;
	if (start >= y)
		len = 0;
	x = my_malloc (sizeof(char) * (len + 1));
	if (!x)
		return (0);
	if (len == 0 || start > y)
	{
		x[i] = '\0';
		return (x);
	}
	while (s[start] && i < len)
		x[i++] = s[start++];
	x[i] = '\0';
	return (x);
}
