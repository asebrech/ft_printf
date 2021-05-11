/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:53 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 18:36:50 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;
	t_struct	data;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_init_struct(&data);
			format = ft_parsing(format, args, &data);
			ret += ft_sort(format, args, &data);
		}
		else
			ret += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}
