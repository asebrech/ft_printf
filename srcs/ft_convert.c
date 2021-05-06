/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:47:42 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/06 11:32:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_p(va_list args)
{
	void	*ptr;
	int		ret;
	char	*base_h;

	base_h = "0123456789abcdef";
	ptr = va_arg(args, void *);
	ret = ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd((unsigned long int)ptr, base_h, 1, &ret);
	return (ret);
}

static int	ft_print(const char *format, va_list args)
{
	int		ret;
	char	*base_h;
	char	*base_H;

	base_h = "0123456789abcdef";
	base_H = "0123456789ABCDEF";
	ret = 0;
	if (*format == '%')
		ret = ft_putchar_fd('%', 1);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &ret);
	else if (*format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, &ret);
	else if (*format == 'c')
		ret = ft_putchar_fd(va_arg(args, int), 1);
	else if (*format == 's')
		ret = ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'x')
		ft_putnbr_base_fd(va_arg(args, unsigned int), base_h, 1, &ret);
	else if (*format == 'X')
		ft_putnbr_base_fd(va_arg(args, unsigned int), base_H, 1, &ret);
	else if (*format == 'p')
		ret = ft_print_p(args);
	return (ret);
}

int	ft_convert(const char *format, va_list args, t_struct *data)
{
	int	ret;

	ret = 0;
	if (data->flag == 0 && data->width == 0 && data->precision == -1)
		ret = ft_print(format, args);
	else if (*format == '%')
		ret = ft_convert_mod(data);
	else if (*format == 'd' || *format == 'i')
		ret = ft_convert_d(args, data);
	return (ret);
}
