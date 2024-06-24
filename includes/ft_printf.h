/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwfonta <erwfonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:21:39 by erwfonta          #+#    #+#             */
/*   Updated: 2024/06/12 14:55:04 by erwfonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int	printf_conditions(char c, va_list args);
int	printf_condition_sup(char c, va_list args);

int	ft_putnbr(long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putptr(void *ptr);
int	ft_putnbr_hex(unsigned long nbr, char *base);

#endif
