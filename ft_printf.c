/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:09:11 by lbuccher          #+#    #+#             */
/*   Updated: 2021/09/30 15:09:19 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
// #include <unistd.h>
// #include <stdarg.h>
#include "ft_printf.h"

int ft_cast(const char c, va_list arg)
{
    int i;
    int len;
    int nb;

    i = 0;
    len = 0;
    nb = 0;
    if (c == 'c')
    {
        char current_arg = va_arg(arg, int);
        ft_putchar(current_arg);
        len++;
    }
    if (c == 's')
    {
        char *current_arg = va_arg(arg, char*);
        if (!current_arg)
            return (write(1, "(null)", 6));
        while(current_arg[i])
        {
            ft_putchar(current_arg[i++]);
            len++;
        }
    }
    if (c == 'i' || c == 'd')
    {
        int current_arg = va_arg(arg, int);
        len += ft_nbrlen(current_arg);
        ft_putnbr(current_arg);
    }
    if (c == 'u')
    {
        unsigned int current_arg = va_arg(arg, int);
        len += ft_un_int_len(current_arg);
        ft_put_un_int(current_arg); // mettre le va arg en 2e paramettre dans les fonctions
    }
    return (len);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    int print_len;

    va_start(args, str);
    i = 0;
    print_len = 0;
    while (str[i])
    {
        if (str[i] != '%')
        {
            ft_putchar(str[i]);
            print_len++;
        }
        else if (str[i] == '%' && str[i+1] != '%')
            print_len += ft_cast(str[++i], args);
        else if(str[i] == '%' && str[i+1] == '%')
        {
            ft_putchar('%');
            i++;
            print_len++;
        }
        i++;
    }
    va_end(args);
    return (print_len);
}

// int main (void)
// {
//     // char c = 'B';
//     // char v = 'C';
//     // char *s = "HELLO";
//     // int n = 754;
//     // unsigned int d = -12;
//     printf("%d \n", printf(" %u ", -1));
//     // printf("%d \n", printf(" %d \t", 0));
//     // printf("%d \n", printf(" %d \t", 1));

//     ft_printf("%d \n", ft_printf(" %u ", -1));
//     // ft_printf("%d \n", ft_printf(" %d \t", 0));
//     // ft_printf("%d \n", ft_printf(" %d \t", 1));
//     return(0);
// }
