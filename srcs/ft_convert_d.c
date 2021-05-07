/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:29:26 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/07 16:39:50 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			str = ft_calloc(data->precision + 1, sizeof(char));
			ft_memset(&str[0], '0', data->precision);
	}
	if (!str)
		return (NULL);
	return (str);
}

static void	d_flag(t_struct *data, char *str, char *nbr)
{
	int	len_nbr;
	int	len_str;

	len_nbr = ft_strlen(nbr);
	len_str = ft_strlen(str);
	if (data->precision == -1)
		data->precision = 0;
	if (data->flag == '-')
	{
		if (data->precision > len_nbr)
		{
			ft_memset(&str[0], '0', data->precision);
			ft_memcpy(&str[data->precision - len_nbr], nbr, len_nbr);
		}
		else
			ft_memcpy(&str[0], nbr, len_nbr);
	}
	else if (data->flag == '0')
	{
		if (data->precision >= len_nbr)
		{
			ft_memset(&str[len_str - data->precision], '0', data->precision);
			if (nbr[0] == '-')
			{
				if (data->precision > data->width)
					ft_memset(&str[0], '-', 1);
				else
					ft_memset(&str[len_str - data->precision - 1], '-', 1);
				ft_memcpy(&str[len_str - len_nbr + 1], &nbr[1], len_nbr - 1);
			}
			else
				ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
		}
		else
			ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
	}
	else if (!data->flag)
	{
		if (nbr[0] != '-')
		{
			ft_memset(&str[len_str - data->precision], '0', data->precision);
			ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
		}
		else if (nbr[0] == '-')
		{
			ft_memset(&str[0], '-', 1);
			ft_memset(&str[len_str - data->precision + 1], '0', data->precision - 1);
			ft_memcpy(&str[len_str - len_nbr + 1], &nbr[1], len_nbr - 1);
		}
	}	
}

int	ft_convert_d(va_list args, t_struct *data)
{
	int		ret;
	int		len_nbr;
	char	*str;
	char	*nbr;

	nbr = ft_itoa(va_arg(args, int));
	str = NULL;
	len_nbr = ft_strlen(nbr);
	ret = 0;
	if ((data->width > 0 || data->precision > -1)
		&& (data->width > len_nbr || data->precision > len_nbr))
	{
		str = ft_alloc(data, nbr);
		if (data->precision == 0 && nbr[0] == '0' && nbr[1] == '\0')
		ft_memset(&nbr[0], ' ', len_nbr);
		d_flag(data, str, nbr);
		ret = ft_putstr_fd(str, 1);
		free(str);
	}
	else
		if (!(data->precision == 0 && nbr[0] == '0' && nbr[1] == '\0'))
			ret = ft_putstr_fd(nbr, 1);
	return (ret);
}
