/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:03:15 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/07 14:32:08 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_p(int len, void *current_arg)
{
	unsigned long	arg;

	arg = (unsigned long)current_arg;
	write(1, "0x", 2);
	len = ft_put_hexa_low(len, arg);
	len += 2;
	return (len);
}

int	ft_print_hexa(char c, int len, unsigned int current_arg)
{
	if (c == 'x')
		len = ft_put_hexa_low(len, current_arg);
	else if (c == 'X')
		len = ft_put_hexa_upp(len, current_arg);
	return (len);
}

int	ft_put_hexa_upp(int nb_len, unsigned int n)
{
	nb_len++;
	if (n > 9 && n < 16)
	{
		if (n == 10)
			ft_putchar('A');
		else if (n == 11)
			ft_putchar('B');
		else if (n == 12)
			ft_putchar('C');
		else if (n == 13)
			ft_putchar('D');
		else if (n == 14)
			ft_putchar('E');
		else if (n == 15)
			ft_putchar('F');
	}
	else if (n > 9)
	{
		nb_len = ft_put_hexa_upp(nb_len, n / 16);
		ft_put_hexa_upp(nb_len, n %= 16);
	}
	else
		ft_putchar(n + '0');
	return (nb_len);
}

int	ft_put_hexa_low(int nb_len, unsigned long n)
{
	nb_len++;
	if (n > 9 && n < 16)
	{
		if (n == 10)
			ft_putchar('a');
		else if (n == 11)
			ft_putchar('b');
		else if (n == 12)
			ft_putchar('c');
		else if (n == 13)
			ft_putchar('d');
		else if (n == 14)
			ft_putchar('e');
		else if (n == 15)
			ft_putchar('f');
	}
	else if (n > 9)
	{
		nb_len = ft_put_hexa_low(nb_len, n / 16);
		ft_put_hexa_low(nb_len, n % 16);
	}
	else
		ft_putchar(n + '0');
	return (nb_len);
}
