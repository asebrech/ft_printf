/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:07:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/06 16:51:57 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_struct(t_struct *data)
{
	data->flag = 0;
	data->width = 0;
	data->point = 0;
	data->precision = -1;
	data->type = 0;
}

void	ft_putnbr_base_fd(unsigned long nb, char *base, int fd, int *ret)
{
	unsigned int	len_base;

	*ret = *ret + 1;
	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		ft_putnbr_base_fd(nb / len_base, base, fd, ret);
		ft_putchar_fd(base[nb % len_base], fd);
	}
	else
	{
		ft_putchar_fd(base[nb], fd);
	}
}
