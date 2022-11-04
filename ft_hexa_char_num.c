/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_char_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:39:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/04 16:54:50 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_hexa(unsigned long nb, char t, int *sum)
{
	if (nb < 16 && nb > 9)
	{
		if (t == 'u')
			ft_putchar("abcdef"[(nb % 10)] - 32, sum);
		else if (t == 'l')
			ft_putchar("abcdef"[(nb % 10)], sum);
	}
	else
		ft_putnbr(nb, sum);
}

void	ft_putnbr_hexa(unsigned long nb, char t, int *sum)
{
	if (nb > 15)
	{
		ft_putnbr_hexa(nb / 16, t, sum);
		ft_putchar_hexa((nb % 16), t, sum);
	}
	else if (nb < 16 && nb > 9)
		ft_putchar_hexa(nb, t, sum);
	else
		ft_putchar_hexa(nb, t, sum);
}
