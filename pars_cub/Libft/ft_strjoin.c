/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:28:35 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/19 22:37:46 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	x = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!x)
		return (0);
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[j])
		x[i++] = s2[j++];
	x[i] = '\0';
	return (x);
}
