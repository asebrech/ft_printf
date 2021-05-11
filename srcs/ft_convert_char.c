/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:17:09 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 15:17:12 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	mod_flag(char c, t_struct *data, char *str)
{
	if (data->flag == '-')
	{
		str[0] = c;
		ft_memset(&str[1], ' ', data->width - 1);
	}
	else if (data->flag == '0' && c == '%')
	{
		ft_memset(&str[0], '0', data->width - 1);
		ft_memset(&str[data->width - 1], c, 1);
	}
}

int	ft_convert_char(char c, t_struct *data)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = 0;
	if (data->width > 1)
	{
		str = ft_calloc(data->width + 1, sizeof(char));
		if (!str)
			return (0);
		if (data->flag)
			mod_flag(c, data, str);
		else if (!data->flag)
		{
			ft_memset(&str[0], ' ', data->width - 1);
			ft_memset(&str[data->width - 1], c, 1);
		}	
		ret = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		ret = ft_putchar_fd(c, 1);
	return (ret);
}
