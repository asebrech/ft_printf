/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:58:59 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/14 09:50:36 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_flag_m(t_struct *data, char *str, char *nbr)
{
	int	len_nbr;

	len_nbr = ft_strlen(nbr);
	if (nbr[0] == '-')
		len_nbr--;
	if (data->precision > len_nbr)
	{
		ft_memset(&str[0], '0', data->precision);
		if (nbr[0] != '-')
			ft_memcpy(&str[data->precision - len_nbr], nbr, len_nbr);
		else
		{
			ft_memset(&str[0], '-', 1);
			ft_memcpy(&str[data->precision - len_nbr + 1],
				&nbr[1], len_nbr);
		}
	}
	else
	{
		if (nbr[0] == '-')
			len_nbr++;
		ft_memcpy(&str[0], nbr, len_nbr);
	}
}

static void	d_noflag01(t_struct *data, char *str, char *nbr)
{
	int	len_nbr;
	int	len_str;

	len_nbr = ft_strlen(nbr);
	len_str = ft_strlen(str);
	if (data->flag == '0' && data->point != 2)
	{
		ft_memset(&str[0], '0', len_str);
		if (nbr[0] == '-')
		{
			ft_memset(&str[0], '-', 1);
			ft_memcpy(&str[len_str - len_nbr + 1], &nbr[1], len_nbr - 1);
		}
		else
			ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
	}
	else
		ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
}

static void	d_noflag(t_struct *data, char *str, char *nbr)
{
	int	len_nbr;
	int	len_str;

	len_nbr = ft_strlen(nbr);
	len_str = ft_strlen(str);
	if (nbr[0] != '-' && data->precision)
	{
		ft_memset(&str[len_str - data->precision], '0', data->precision);
		ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
	}
	else if (nbr[0] == '-' && data->precision)
	{
		if (data->precision == 1)
			ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
		else
		{
			ft_memset(&str[len_str - data->precision - 1], '-', 1);
			ft_memset(&str[len_str - data->precision], '0',
				data->precision - 1);
			ft_memcpy(&str[len_str - len_nbr + 1], &nbr[1], len_nbr - 1);
		}
	}
	else
		d_noflag01(data, str, nbr);
}

void	d_flag(t_struct *data, char *str, char *nbr)
{
	int	len_nbr;
	int	len_str;

	len_nbr = ft_strlen(nbr);
	len_str = ft_strlen(str);
	if (data->precision == 0)
		data->point = 2;
	if (data->precision <= -1)
		data->precision = 0;
	if (data->flag == '-')
		d_flag_m(data, str, nbr);
	else if (data->flag == '0' && !data->point)
	{
		ft_memset(&str[0], '0', len_str);
		if (nbr[0] == '-')
		{
			ft_memset(&str[0], '-', 1);
			ft_memcpy(&str[len_str - len_nbr + 1], &nbr[1], len_nbr - 1);
		}
		else
			ft_memcpy(&str[len_str - len_nbr], nbr, len_nbr);
	}
	else
		d_noflag(data, str, nbr);
}
