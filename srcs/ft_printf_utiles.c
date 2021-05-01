/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:07:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/01 13:05:00 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base_fd(long int nb, char *base, int fd)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > len_base)
	{
		ft_putnbr_base_fd(nb / len_base, base, fd);
		ft_putchar_fd(base[nb % len_base], fd);
	}
	else
		ft_putchar_fd(base[nb], fd);
}
