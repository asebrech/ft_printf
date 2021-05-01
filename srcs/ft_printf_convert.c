/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:23:08 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/01 15:45:17 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
void	ft_convert(const char *format, va_list args)
{
	void	*ptr;

	if (*format == '%')
		ft_putchar_fd('%', 1);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'x')
		ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789abcdef", 1);
	else if (*format == 'X')
		ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	else if (*format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			ft_putstr_fd("(nil)", 1);
		else
		{
			ft_putstr_fd("0x", 1);
			ft_putnbr_base_fd((long int)ptr, "0123456789abcdef",1);
		}
	}
}
