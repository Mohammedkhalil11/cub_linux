/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:18:54 by iszitoun          #+#    #+#             */
/*   Updated: 2022/11/11 02:19:18 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	check_it(va_list(argm), char c);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_put_unsigned_nbr(unsigned int n);
int	ft_hexadicimal(char *s, size_t i);
int	adonly(char *s, size_t i);

#endif
