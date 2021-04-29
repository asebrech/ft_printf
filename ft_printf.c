/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:05:36 by asebrech          #+#    #+#             */
/*   Updated: 2021/04/29 18:36:14 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (format)
	{
		if(*format == '%')
		{
			ft_convchr(format, args);
			format++;
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
}
