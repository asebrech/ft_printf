/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:47:42 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/04 21:13:20 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print(const char *format, va_list args)
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
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd((unsigned long int)ptr, "0123456789abcdef", 1);
	}
}

void	ft_convert(const char *format, va_list args, t_struct *data)
{
	if (data->flag == 0 && data->width == 0 && data->precision == -1)
		ft_print(format, args);
}
