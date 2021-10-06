/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:09:24 by lbuccher          #+#    #+#             */
/*   Updated: 2021/10/06 15:16:59 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_nbrlen(int n);
int     ft_un_int_len(unsigned int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_put_un_int(unsigned int n);
int		ft_cast(const char c, va_list arg);
int		ft_printf(const char *str, ...);

#endif
