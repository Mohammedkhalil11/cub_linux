/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:24:39 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:13:26 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*loc;
	size_t	x;

	if (size > SIZE_MAX || count > SIZE_MAX)
		return (0);
	x = count * size;
	loc = my_malloc(x);
	if (!loc)
		return (0);
	ft_bzero(loc, x);
	return (loc);
}
