/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:45:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/04 21:04:14 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static const char	*ft_preci(const char *format, va_list args, t_struct *data)
{
	format++;
	if (*format >= '0' && *format <= '9')
	{
		data->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	else if (*format == '*')
	{
		data->precision = va_arg(args, int);
		format++;
	}
	return (format);
}

static const char	*ft_flag(const char *format, t_struct *data)
{
	if (*format == '0')
	{
		data->flag = *format;
		format++;
		if (*format == '-')
		{
			data->flag = *format;
			format++;
		}
	}
	else if (*format == '-')
	{
		data->flag = *format;
		format++;
		if (*format == '0')
			format++;
	}
	return (format);
}

#include <stdio.h>


const char	*ft_parsing(const char *format, va_list args, t_struct *data)
{
	if (*format == '-' || *format == '0')
	{
		format = ft_flag(format, data);
	}
	if (*format >= '0' && *format <= '9')
	{
		data->width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	else if (*format == '*')
	{
		data->width = va_arg(args, int);
		format++;
	}
	if (*format == '.')
		format = ft_preci(format, args, data);
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x'
		|| *format == 'X' || *format == '%')
		data->type = *format;

	printf(" f %c\n", data->flag);
	printf(" f %d\n", data->width);
	printf(" f %d\n", data->precision);
	printf(" f %c\n", data->type);

	return (format);
}
