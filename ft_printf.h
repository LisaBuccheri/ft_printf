/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:09:24 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/07 14:57:40 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_put_un_int(unsigned int n);
int		ft_nbrlen(int n);
int		ft_un_int_len(unsigned int n);
int		ft_put_hexa_low(int len, unsigned long n);
int		ft_put_hexa_upp(int len, unsigned int n);
int		ft_print_hexa(char c, int len, unsigned int current_arg);
int		ft_print_c(int len, char current_arg);
int		ft_print_s(int len, char *current_arg);
int		ft_print_int(int len, int current_arg);
int		ft_print_p(int len, void *current_arg);
int		ft_print_un_int(int len, unsigned int current_arg);
int		ft_cast(const char c, va_list arg);
int		ft_printf(const char *str, ...);

#endif
