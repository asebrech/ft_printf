/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:17:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/14 13:10:05 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_char(char c, t_struct *data)
{
	int	ret;

	ret = 0;
	if (data->flag == '-')
		ret = ft_putchar_fd(c, 1);
	if (data->width)
		data->width--;
	ret += data->width;
	while (data->width != 0)
	{
		if (data->flag == '0' && c == '%')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		data->width--;
	}
	if (data->flag != '-')
		ret += ft_putchar_fd(c, 1);
	return (ret);
}
