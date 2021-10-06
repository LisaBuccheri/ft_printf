/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:03:15 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/06 18:02:32 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hexa(int len, int current_arg)
{
	int	nb_letter;

	nb_letter = 0;
	nb_letter += ft_put_hexa(nb_letter, current_arg);
	printf("\nnb :%d \n", nb_letter);
	len += (ft_nbrlen(current_arg) - nb_letter);
	return (len);
}

int	ft_print_hexa_letter(int n)
{
	if (n > 9 && n < 16)
	{
		if (n == 10)
			ft_putchar('a');
		if (n == 11)
			ft_putchar('b');		
		if (n == 12)
			ft_putchar('c');
		if (n == 13)
			ft_putchar('d');
		if (n == 14)
			ft_putchar('e');
		if (n == 15)
			ft_putchar('f');
		return (1);
	}
	return (0);
}
// reussir a incrementer une variable pour trouver le nombre de char imprimer
int	ft_put_hexa(int nb_let, int n)
{
	if (n > 9)
	{
		ft_put_hexa(nb_let, n / 16);
		n %= 16;
		if (ft_print_hexa_letter(n))
		{
			nb_let += 1;
			return (++nb_let);
		}
	}
	if (n == 0)
		return (++nb_let);
	ft_putchar(n + '0');
	return (++nb_let);
}
