/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:45:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/04 16:48:28 by asebrech         ###   ########.fr       */
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

static const char *ft_flag(const char *format, t_struct *data)
{
	if (*format == '0' && (*format + 1) != '-')
		data->flag = *format;
	else if (*format == '0' && (*format + 1) == '-')
	{
		format++;
		data->flag = *format;
	}
	else if (*format == '-' && (*format + 1) != '0')
		data->flag = *format;
	else if (*format == '-' && (*format + 1) == '0')
	{
		data->flag = *format;
		format++;
	}
	return (format);
}

#include <stdio.h>
void	printest(t_struct *data)
{
	printf("%c\n", data->flag);
	printf("%d\n", data->width);
	printf("%d\n", data->precision);
	printf("%c\n", data->type);
	
}

const char	*ft_parsing(const char *format, va_list args, t_struct *data)
{
	if (*format == '-' || *format == '0')
	{
		format = ft_flag(format, data);
		format++;
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
		printest(data);
	return (format);
}
