/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:26:47 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/06 16:03:34 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	mod_flag(char *str, t_struct *data)
{
	if (data->flag == '-')
	{
		str[0] = '%';
		ft_memset(&str[1], ' ', data->width - 1);
	}
	else if (data->flag == '0')
	{
		ft_memset(&str[0], '0', data->width - 1);
		ft_memset(&str[data->width - 1], '%', 1);
	}
}

int	ft_convert_mod(t_struct *data)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = 0;
	if (data->width > 0)
	{
		str = ft_calloc(data->width + 1, sizeof(char));
		if (!str)
			return (0);
		if (data->flag)
			mod_flag(str, data);
		else if (!data->flag)
		{
			ft_memset(&str[0], ' ', data->width - 1);
			ft_memset(&str[data->width - 1], '%', 1);
		}	
		ret = ft_putstr_fd(str, 1);
	}
	else
		ret = ft_putchar_fd('%', 1);
	free(str);
	return (ret);
}
