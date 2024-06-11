/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:38:29 by erwfonta          #+#    #+#             */
/*   Updated: 2024/06/11 15:20:16 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		retrn;

	retrn = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			retrn += printf_conditions(*format, args);
		}
		else
		{
			retrn += ft_putchar(*format);
		}
		format++;
	}
	return (retrn);
}

int	printf_conditions(char c, va_list args)
{
	if (c == 's')
	{
		return (ft_putstr(va_arg(args, char *)));
	}
	else if (c == 'c')
	{
		return (ft_putchar(va_arg(args, int)));
	}
	else if (c == 'd' || c == 'i')
	{
		return (ft_putnbr(va_arg(args, int)));
	}
	else if (c == 'u')
	{
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	}
	else
		return (printf_condition_sup(c, args));
	return (0);
}

int	printf_condition_sup(char c, va_list args)
{
	if (c == 'p')
	{
		return (ft_putptr(va_arg(args, void *)));
	}
	else if (c == 'x')
	{
		return (ft_putnbr_hex(va_arg(args, unsigned long), "0123456789abcdef"));
	}
	else if (c == 'X')
	{
		return (ft_putnbr_hex(va_arg(args, unsigned long), "0123456789ABCDEF"));
	}
	else if (c == '%')
	{
		return (ft_putchar('%'));
	}
	return (0);
}

int	main(void)
{
	long	c;

	c = LONG_MAX;
	printf(" ceci est le mien %d \n", ft_printf("%X", c));
	printf(" ceci est le vrai %d \n", printf("%X", c));
	return (0);
}
