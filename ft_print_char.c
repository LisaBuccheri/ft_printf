/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:25:28 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/07 14:29:42 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_c(int len, char current_arg)
{
	ft_putchar(current_arg);
	len++;
	return (len);
}

int	ft_print_s(int len, char *current_arg)
{
	int	i;

	i = 0;
	if (!current_arg)
		return (write(1, "(null)", 6));
	while (current_arg[i])
	{
		ft_putchar(current_arg[i++]);
		len++;
	}
	return (len);
}
