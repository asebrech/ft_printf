/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:53 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/04 21:14:21 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	data;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_init_struct(&data);
			format = ft_parsing(format, args, &data);
			ft_convert(format, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
}
