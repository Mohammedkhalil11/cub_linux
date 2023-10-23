/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:28:44 by iszitoun          #+#    #+#             */
/*   Updated: 2022/10/27 20:40:36 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	z;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		z = ft_strlen(src) + dstsize;
	else
		z = ft_strlen(src) + ft_strlen(dst);
	i = 0;
	j = ft_strlen(dst);
	if (dstsize != 0)
	{
		while (src[i] && dstsize - 1 > j)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	return (z);
}
