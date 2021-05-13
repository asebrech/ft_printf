/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:43:52 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/13 10:15:24 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd, int *ret)
{
	*ret = *ret + 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		*ret = *ret + 1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, ret);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
