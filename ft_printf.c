/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:25:02 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/04 16:57:47 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(char ch, int *sum, va_list ap)
{
	if (ch == 'c')
		ft_putchar(va_arg(ap, int), sum);
	else if (ch == 's')
		ft_putstr(va_arg(ap, char *), sum);
	else if (ch == 'd' || ch == 'i')
		ft_putnbr(va_arg(ap, int), sum);
	else if (ch == 'u')
		ft_put_unsigned(va_arg(ap, unsigned int), sum);
	else if (ch == 'x')
		ft_putnbr_hexa(va_arg(ap, unsigned int), 'l', sum);
	else if (ch == 'X')
		ft_putnbr_hexa(va_arg(ap, unsigned int), 'u', sum);
	else if (ch == 'p')
	{
		ft_putstr("0x", sum);
		ft_putnbr_hexa(va_arg(ap, unsigned long long), 'l', sum);
	}
	else if (ch == '%')
		ft_putchar('%', sum);
	else
		ft_putchar (ch, sum);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		sum;

	sum = 0;
	index = 0;
	va_start(ap, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			if (!format[index + 1])
				return (sum);
			print_args(format[index + 1], &sum, ap);
			index++;
		}
		else
			ft_putchar(format[index], &sum);
		index++;
	}
	va_end(ap);
	return (sum);
}
