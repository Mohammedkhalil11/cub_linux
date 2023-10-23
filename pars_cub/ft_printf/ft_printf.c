/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:15:57 by iszitoun          #+#    #+#             */
/*   Updated: 2022/11/11 02:18:20 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_it(va_list(argm), char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(argm, int));
	else if (c == 's')
		count += ft_putstr(va_arg(argm, char *));
	else if (c == 'i' || c == 'd')
		count += ft_putnbr(va_arg(argm, int));
	else if (c == 'u')
		count += ft_put_unsigned_nbr(va_arg(argm, unsigned int));
	else if (c == 'x')
		count += ft_hexadicimal("0123456789abcdef", va_arg(argm, unsigned int));
	else if (c == 'X')
		count += ft_hexadicimal("0123456789ABCDEF", va_arg(argm, unsigned int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hexadicimal("0123456789abcdef", va_arg(argm, size_t));
	}
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	argm;
	int		count;
	int		i;

	va_start(argm, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			count += check_it(argm, s[++i]);
		else if (s[i] != '%')
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
// #include <stdio.h>
// int main()
// {
//     printf("\n%d", ft_printf(" %c %c %c ", '0', 0, '1'));
// }
