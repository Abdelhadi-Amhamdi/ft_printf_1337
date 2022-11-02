/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:39:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/02 22:05:23 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c, int *sum)
{
    write(1, &c, 1);
    *sum = *sum + 1;
}

void ft_putstr(char *str, int *sum)
{
    int index;

    index = 0;
    while (str[index])
    {
        ft_putchar(str[index] , sum);
        index++;
    }
}

void ft_putnbr(int n, int *sum)
{
    unsigned int nb;

    if (n < 0)
        ft_putchar('-' , sum);
    nb = ABS(n);
    if (nb > 9)
    {
        ft_putnbr(nb / 10, sum);
        ft_putchar((nb % 10) + 48, sum);
    }
    else
        ft_putchar((nb % 10) + 48, sum);
}

void ft_putchar_hexa(int nb, char t, int *sum)
{
    if (nb < 16 && nb > 9)
    {
        if (t == 'u')
            ft_putchar(ALPHA(nb % 16) - 32, sum);
        else if (t == 'l')
            ft_putchar(ALPHA(nb % 16), sum);
    }
    else
        ft_putnbr(nb, sum);
}

void ft_putnbr_Hexa(int nb, char t, int *sum)
{
    if (nb > 15)
    {
        ft_putnbr_Hexa(nb / 16, t, sum);
        ft_putchar_hexa((nb % 16), t, sum);
    }
    else if (nb < 16 && nb > 9)
        ft_putchar_hexa(nb , t, sum);
    else
        ft_putchar_hexa(nb, t, sum);
}

void ft_putmem(void *ptr, int *sum)
{
    ft_putstr("0x" , sum);
    ft_putnbr_Hexa((unsigned long int)ptr, 'l', sum);
}
