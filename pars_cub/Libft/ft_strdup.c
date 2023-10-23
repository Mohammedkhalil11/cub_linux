/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:28:17 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/19 22:37:46 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*loc;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	i = 0;
	loc = malloc(sizeof(char) * (slen + 1));
	if (!(loc))
		return (NULL);
	while (src[i])
	{
		loc[i] = src[i];
		i++;
	}
	loc[i] = '\0';
	return (loc);
}
