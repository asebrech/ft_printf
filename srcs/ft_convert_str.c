/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:27:18 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/12 10:01:32 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	s_flag(char *str, t_struct *data, char *dst, int len_str)
{
	int	len_dst;

	len_dst = ft_strlen(dst);
	ft_memset(&dst[0], ' ', data->width);
	len_dst = ft_strlen(dst);
	if (data->flag == '-')
		ft_memcpy(&dst[0], str, len_str);
	else
		ft_memcpy(&dst[len_dst - len_str], str, len_str);
}

int	ft_convert_str(char *str, t_struct *data)
{
	char	*dst;
	int		ret;
	int		len_str;

	ret = 0;
	if (data->precision == -1 && data->point)
		data->precision = 0;
	if (data->point)
		str = ft_substr(str, 0, data->precision);
	len_str = ft_strlen(str);
	if (data->width > len_str)
	{
		dst = ft_calloc(data->width + 1, sizeof(char));
		if (!dst)
			return (0);
		s_flag(str, data, dst, len_str);
		ret = ft_putstr_fd(dst, 1);
		free(dst);
	}
	else
		ret = ft_putstr_fd(str, 1);
	return (ret);
}
