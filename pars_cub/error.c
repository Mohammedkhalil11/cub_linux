/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhalil <mokhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:38 by iszitoun          #+#    #+#             */
/*   Updated: 2023/10/20 03:04:29 by mokhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horinzontal_error(void)
{
	ft_printf("ERROR:\n Check your map's Horizantal Walls!\n");
	exit(1);
}

void	arg_error(void)
{
	ft_printf("ERROR:\n The second argument should be ****.cub!\n");
	exit(1);
}

void	invalid_item_error(void)
{
	ft_printf("ERROR:\n You entered an Invalid symbole in your map!\n");
	exit(1);
}

void	duplicated_player_error(void)
{
	ft_printf("ERROR:\n Player's symbole (duplicated or missing)!\n");
	exit(1);
}

void	void_next_floor(void)
{
	ft_printf("ERROR:\n Void inside the map!\n");
	exit(1);
}
