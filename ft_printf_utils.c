

#include "ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int n)
{
    unsigned int nb;

    if (n < 0)
        ft_putchar('-');
    nb = ABS(n);
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putchar((nb % 10) + 48);
    }
    else
        ft_putchar((nb % 10) + 48);
}

void ft_putchar_hexa(int nb, char t)
{
    if (nb < 16 && nb > 9)
    {
        if (t == 'u')
            ft_putchar(ALPH(nb % 16) - 32);
        else if (t == 'l')
            ft_putchar(ALPH(nb % 16));
    }
    else
        ft_putnbr(nb);
}

void ft_putnbr_Hexa(int nb, char t)
{
    if (nb > 15)
    {
        ft_putnbr_Hexa(nb / 16, t);
        ft_putchar_hexa((nb % 16), t);
    }
    else if (nb < 16 && nb > 9)
        ft_putchar_hexa(nb , t);
    else
        ft_putnbr(nb);
}