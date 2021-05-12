/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:17:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/12 13:43:05 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	mod_flag(char c, t_struct *data, char *str, int ret)
{
	if (data->flag)
	{
		if (data->flag == '-')
		{
			ft_memset(&str[0], ' ', data->width);
			if (c)
				str[0] = c;
		}
		else if (data->flag == '0' && c == '%')
		{
			ft_memset(&str[0], '0', data->width);
			ft_memset(&str[data->width - 1], c, 1);
		}
	}
	else if (!data->flag)
	{
		ft_memset(&str[0], ' ', data->width);
		if (c)
			ft_memset(&str[data->width - 1], c, 1);
	}	
	ret += ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}

int	ft_convert_char(char c, t_struct *data)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = 0;
	if (c == 0)
	{
		data->width--;
		ret++;
	}
	if (data->width)
	{
		str = ft_calloc(data->width + 1, sizeof(char));
		if (!str)
			return (0);
		ret = mod_flag(c, data, str, ret);
	}
	else
		ret = ft_putchar_fd(c, 1);
	return (ret);
}
