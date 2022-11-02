/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:40 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/02 18:08:35 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libc.h"

#define ABS(nb) (nb < 0 ? -nb : nb)
#define ALPH(nb) (nb == 10 ? 'a' : nb == 11 ? 'b' : nb == 12 ? 'c' : nb == 13 ? 'd' : nb == 14 ? 'e' : 'f')

void ft_putstr(char *str);
int ft_printf(char *string, ...);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putnbr_Hexa(int nb, char t);
void ft_putchar_hexa(int nb, char t);

#endif