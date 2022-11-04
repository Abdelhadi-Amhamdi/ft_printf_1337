/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:53:10 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/04 17:02:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	ft_putchar(char c, int *sum)
{
	write(1, &c, 1);
	*sum = *sum + 1;
}

void	ft_putstr(char *str, int *sum)
{
	int	index;

	index = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*sum = *sum + 6;
		return ;
	}
	while (str[index])
	{
		ft_putchar(str[index], sum);
		index++;
	}
}

void	ft_putnbr(int n, int *sum)
{
	unsigned int	nb;

	if (n < 0)
		ft_putchar('-', sum);
	nb = abs(n);
	if (nb > 9)
	{
		ft_putnbr(nb / 10, sum);
		ft_putchar((nb % 10) + 48, sum);
	}
	else
		ft_putchar((nb % 10) + 48, sum);
}

void	ft_put_unsigned(unsigned int nb, int *sum)
{
	if (nb > 9)
	{
		ft_put_unsigned((nb / 10), sum);
		ft_putchar(((nb % 10) + 48), sum);
	}
	else
		ft_putchar(((nb % 10) + 48), sum);
}
