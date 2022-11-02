/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:25:02 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/02 18:22:46 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(char *string, ...)
{
    l_list *ls;
    lt->next;
    va_list ap;
    int index = 0;

    va_start(ap, string);
    while (string[index])
    {
        while (string[index])
        {
            if (string[index] == '%' && string[index + 1] == 'c')
            {
                ft_putchar(va_arg(ap , int));
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 's')
            {
                ft_putstr(va_arg(ap , char *));
                index++;
            }
            else if(string[index] == '%' && (string[index + 1] == 'd' || string[index + 1] == 'i'))
            {
                ft_putnbr(va_arg(ap , int));
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'x')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'l');
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'X')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'u');
                index++;
            }
               else if(string[index] == '%' && string[index + 1] == 'i')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'l');
                index++;
            }
            else if(string[index] == '%' && string[index + 1] == 'u')
            {
                ft_putnbr_Hexa(va_arg(ap , int), 'u');
                index++;
            }
            else
            {
                ft_putchar(string[index]);
            }
            index ++;
        }
    }
    va_end(ap);
    return 0;
}