/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:59:14 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/13 16:16:23 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_alloc(t_struct *data, char *nbr)
{
	char	*str;

	str = NULL;
	if (data->width > data->precision)
	{
		str = ft_calloc(data->width + 1, sizeof(char));
		ft_memset(&str[0], ' ', data->width);
	}
	else
	{
		if (nbr[0] == '-')
		{
			str = ft_calloc(data->precision + 2, sizeof(char));
			ft_memset(&str[0], '0', data->precision + 1);
		}
		else
		{
			str = ft_calloc(data->precision + 1, sizeof(char));
			ft_memset(&str[0], '0', data->precision);
		}
	}
	if (!str)
		return (NULL);
	return (str);
}

static int	no_convert(char *nbr, t_struct *data)
{
	int	ret;

	ret = 0;
	if (!(data->precision == 0 && nbr[0] == '0' && nbr[1] == '\0'))
		ret = ft_putstr_fd(nbr, 1);
	else if (data->width)
		ret = ft_putchar_fd(' ', 1);
	return (ret);
}

int	ft_convert_nbr(char *nbr, t_struct *data)
{
	int		ret;
	int		len_nbr;
	char	*str;

	str = NULL;
	ret = 0;
	len_nbr = ft_strlen(nbr);
	if (nbr[0] == '-')
		len_nbr--;
	if ((data->width > 0 || data->precision > -1)
		&& (data->width > len_nbr || data->precision > len_nbr))
	{
		if (data->precision == 0 && nbr[0] == '0' && nbr[1] == '\0')
			ft_memset(&nbr[0], ' ', len_nbr);
		str = ft_alloc(data, nbr);
		d_flag(data, str, nbr);
		ret = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		ret = no_convert(nbr, data);
	free(nbr);
	return (ret);
}
