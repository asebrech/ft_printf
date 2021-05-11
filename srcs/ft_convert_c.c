/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:37:47 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 13:01:40 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	c_flag(t_struct *data, char c, char *str)
{
	str[0] = c;
	ft_memset(&str[1], ' ', data->width - 1);
}

int	ft_convert_c(t_struct *data, va_list args)
{
	int		ret;
	char	c;
	char	*str;

	c = va_arg(args, int);
	str = NULL;
	ret = 0;
	if (data->width > 1)
	{
		str = ft_calloc(data->width + 1, sizeof(char));
		if (!str)
			return (0);
		if (data->flag == '-')
			c_flag(data, c, str);
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
