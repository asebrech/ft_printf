/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:07:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/04/30 00:07:09 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convchr(const char *format, va_list args)
{
	if (*format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format =='c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format =='s')
		ft_putstr_fd(va_arg(args, char *), 1);
}
