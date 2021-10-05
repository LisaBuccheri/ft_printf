/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:09:24 by lbuccher          #+#    #+#             */
/*   Updated: 2021/09/30 15:09:27 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s);
int     ft_nbrlen(int n);
void	ft_putchar(char c);
int     ft_putnbr(int n);
int     ft_put_un_int(unsigned int n);
int     ft_cast(const char c, va_list arg);
int     ft_printf(const char *str, ...);