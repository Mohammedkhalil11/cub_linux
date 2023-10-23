/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:54:41 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:32 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sides_error(void)
{
	ft_printf("\nERROR: Check your map's *VERTICAL WALLS* !!!\n");
	exit(1);
}

void	path_error(void)
{
	ft_printf("ERROR:\n \tPath is invalid or Missing!\n");
	exit(1);
}

void	color_error(void)
{
	ft_printf("ERROR:\n \tColor is invalid or Missing!\n");
	exit (1);
}

void	empty_line_inside(void)
{
	ft_printf("ERROR:\n \tEmpty line inside map!\n");
	exit (1);
}

void	undefined_line_error(void)
{
	ft_printf("ERROR:\n \tUndefined line on map file!\n");
	exit (1);
}
