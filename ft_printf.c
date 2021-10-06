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
    int len;
    int nb;

    len = 0;
    nb = 0;
    if (c == 'c')
        len += ft_print_c(len, va_arg(arg, int));
    if (c == 's')
        len += ft_print_s(len, va_arg(arg, char*));
    if (c == 'i' || c == 'd')
        len += ft_print_int(len, va_arg(arg, int));
    if (c == 'u')
        len += ft_print_un_int(len, va_arg(arg, int));
    if (c == 'x' || c == 'X')
        len += ft_print_hexa(len, va_arg(arg, int));
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
//     int n = 285426;
//     int resultMod = n % 16;
//     int resultDiv = n / 16;
    
//     printf("%d\n", printf(" %x \n", n));
//     ft_printf("%d\n", ft_printf(" %x \n", n));
//     //printf("\n nb print: %d \n", printf(" %s", s));
//     // printf("%d \n", printf(" %c \t", c));
//     // printf("%d \n", printf(" %c \t", v));

//     // ft_printf("\n nb print: %d \n", ft_printf(" %s", s));
//     // ft_printf("%d \n", ft_printf(" %c \t", c));
//     // ft_printf("%d \n", ft_printf(" %c \t", v));
//     // ft_printf("%d \n", ft_printf(" %% \t"));
//     return(0);
// }
