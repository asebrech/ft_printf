/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:53 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/12 10:19:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_struct(t_struct *data)
{
	data->flag = 0;
	data->width = 0;
	data->point = 0;
	data->precision = -1;
	data->type = 0;
}

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
