/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:08 by erwfonta          #+#    #+#             */
/*   Updated: 2024/06/11 15:19:12 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count += 1;
		count += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		digit = n + 48;
		write(1, &digit, 1);
		count += 1;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		digit = n + 48;
		write(1, &digit, 1);
		count += 1;
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = ft_putstr("0x");
	count += ft_putnbr_hex(address, "0123456789abcdef");
	return (count);
}

int	ft_putnbr_hex(long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16, base);
		count += ft_putnbr_hex(nbr % 16, base);
	}
	else
	{
		count += ft_putchar(base[nbr]);
	}
	return (count);
}
