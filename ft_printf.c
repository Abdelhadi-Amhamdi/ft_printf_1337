/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:25:02 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/02 22:09:27 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    va_list ap;
    int index = 0;
    int sum ;

    sum = 0;

    va_start(ap, string);
    while (string[index])
    {
        while (string[index])
        {
            if (string[index] == '%' && string[index + 1] == 'c')
            {
                ft_putchar(va_arg(ap , int), &sum);
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 's')
            {
                ft_putstr(va_arg(ap , char *) , &sum);
                index++;
            }
            else if(string[index] == '%' && (string[index + 1] == 'd' || string[index + 1] == 'i'))
            {
                ft_putnbr(va_arg(ap , int) , &sum);
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'x')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'l', &sum);
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'X')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'u', &sum);;
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'u')
            {
                ft_putnbr(va_arg(ap , int) , &sum);
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'p')
            {
                ft_putmem(va_arg(ap , char *), &sum);
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == '%')
            {
                ft_putchar('%', &sum);
                index++;
            }
            else
            {
                ft_putchar(string[index], &sum);
            }
            index ++;
        }
    }
    va_end(ap);
    return (sum);
}