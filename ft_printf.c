/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:09:11 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/07 14:56:31 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_cast(const char c, va_list arg)
{
	int	len;
	int	nb;

	len = 0;
	nb = 0;
	if (c == 'c')
		len += ft_print_c(len, va_arg(arg, int ));
	else if (c == 's')
		len += ft_print_s(len, va_arg(arg, char *));
	else if (c == 'i' || c == 'd')
		len += ft_print_int(len, va_arg(arg, int ));
	else if (c == 'u')
		len += ft_print_un_int(len, va_arg(arg, int ));
	else if (c == 'x' || c == 'X')
		len += ft_print_hexa(c, len, va_arg(arg, unsigned int ));
	else if (c == 'p')
		len += ft_print_p(len, va_arg(arg, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	va_start(args, str);
	i = -1;
	print_len = 0;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			print_len++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
			print_len += ft_cast(str[++i], args);
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
			print_len++;
		}
	}
	va_end(args);
	return (print_len);
}

// int main (void)
// {
//     int n = -156;
//     int resultMod = n % 16;
//     int resultDiv = n / 16; 
//     printf("%d\n", printf(" %p %p\n", LONG_MIN, LONG_MAX));
//     ft_printf("%d\n", ft_printf(" %p %p\n", LONG_MIN, LONG_MAX));
//      printf("%d\n", printf(" %p %p\n", ULONG_MAX, -ULONG_MAX));
//     ft_printf("%d\n", ft_printf(" %p %p\n", ULONG_MAX, -ULONG_MAX));
//     return(0);
// }
