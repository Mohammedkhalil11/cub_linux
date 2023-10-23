/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:12:54 by iszitoun          #+#    #+#             */
/*   Updated: 2022/11/11 02:15:31 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(long n)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		sign = 1;
	}
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10) + sign);
	else
		return (ft_putchar(n + '0') + sign);
}

int	ft_put_unsigned_nbr(unsigned int n)
{
	return (ft_putnbr(n));
}

int	ft_hexadicimal(char *s, size_t i)
{
	if (i >= 16)
		return (ft_hexadicimal(s, i / 16) + ft_hexadicimal(s, i % 16));
	else
		return (ft_putchar(s[i]));
}
