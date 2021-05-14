/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:27:18 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/14 10:37:01 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_flag(char *str, t_struct *data, char *dst, int len_str)
{
	int	ret;
	int	len_dst;

	ret = 0;
	len_dst = ft_strlen(dst);
	ft_memset(&dst[0], ' ', data->width);
	len_dst = ft_strlen(dst);
	if (data->flag == '-')
		ft_memcpy(&dst[0], str, len_str);
	else
		ft_memcpy(&dst[len_dst - len_str], str, len_str);
	ret = ft_putstr_fd(dst, 1);
	free(dst);
	return (ret);
}

int	ft_convert_str(char *str, t_struct *data)
{
	char	*dst;
	int		ret;
	int		len_str;

	if (str == NULL)
		str = "(null)";
	dst = NULL;
	ret = 0;
	if (data->precision == -1 && !data->point)
		data->precision = 0;
	if (data->point)
		str = ft_substr(str, 0, data->precision);
	len_str = ft_strlen(str);
	if (data->width > len_str)
	{
		dst = ft_calloc(data->width + 1, sizeof(char));
		if (!dst)
			return (0);
		ret = s_flag(str, data, dst, len_str);
	}
	else
		ret = ft_putstr_fd(str, 1);
	if (data->point)
		free(str);
	return (ret);
}
