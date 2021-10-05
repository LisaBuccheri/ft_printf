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
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_nbrlen(int n)
{
	int i;

	i = 0;
    if (n < 0)
    {
        i++;
        n *= -1;
    }
	while (n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			n %= 10;
		}
		ft_putchar(n + '0');
	}
    return (ft_nbrlen(n));
}

int ft_put_un_int(unsigned int n)
{
    if (n < 0)
        write(1, "4294967295", 10);
    if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
    return (ft_nbrlen(n));
}

int ft_cast(const char c, va_list arg)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (c == 'c')
    {
        char current_arg = va_arg(arg, int);
        ft_putchar(current_arg);
        len++;
    }
    if (c == 's')
    {
        char *current_arg = va_arg(arg, char*);
        while(current_arg[i])
        {
            ft_putchar(current_arg[i++]);
            len++;
        }
    }
    if (c == 'i' || c == 'd')
    {
        int current_arg = va_arg(arg, int);
        len += ft_putnbr(current_arg);
    }
    if (c == 'u')
    {
        int current_arg = va_arg(arg, int);
        len += ft_put_un_int(current_arg);
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
        if (str[i] == '%' && str[i+1] != '%' && str[i+1] != ' ')
            print_len += ft_cast(str[++i], args);
        else if(str[i] == '%' && str[i+1] == '%')
            ft_putchar('%');
        i++;
    }
    va_end(args);
    return (print_len);
}

int main (void)
{
    char c = 'B';
    char v = 'C';
    char *s = "HELLO";
    int n = 754;
    unsigned int d = -17;
    printf("salut %u toi\n", d);
    ft_printf("salut %u toi\n", d);
    return(0);
}
