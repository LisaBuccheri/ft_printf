/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:27:04 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/07 14:33:31 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
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
}

int	ft_print_int(int len, int current_arg)
{
	len += ft_nbrlen(current_arg);
	ft_putnbr(current_arg);
	return (len);
}

void	ft_put_un_int(unsigned int n)
{
	if (n < 0)
		write(1, "4294967295", 10);
	if (n > 9)
	{
		ft_put_un_int(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

int	ft_print_un_int(int len, unsigned int current_arg)
{
	len += ft_un_int_len(current_arg);
	ft_put_un_int(current_arg);
	return (len);
}
