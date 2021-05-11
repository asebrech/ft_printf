/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:07:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 18:47:21 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base_fd(unsigned long nb, char *base, int fd, int *ret)
{
	unsigned int	len_base;

	*ret = *ret + 1;
	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		ft_putnbr_base_fd(nb / len_base, base, fd, ret);
		ft_putchar_fd(base[nb % len_base], fd);
	}
	else
	{
		ft_putchar_fd(base[nb], fd);
	}
}

static int	ft_nbrlen(long int nbr, int len_base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= len_base;
		len++;
	}
	return (len);
}

static void	ft_alloc(long int nbr, char *base, int len_nbr, char *str)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		len_nbr--;
		str[len_nbr] = base[nbr % len_base];
		nbr /= len_base;
	}
}

char	*ft_itoa_base(long int nbr, char *base, int p)
{
	char	*str;
	char	*ptr;
	int		len_nbr;
	int		len_base;

	len_base = ft_strlen(base);
	len_nbr = ft_nbrlen(nbr, len_base);
	ptr = "0x";
	str = malloc(sizeof(char) * len_nbr + 1);
	if (!str)
		return (NULL);
	str[len_nbr] = '\0';
	ft_alloc(nbr, base, len_nbr, str);
	if (p)
		str = ft_strjoin(ptr, str);
	return (str);
}
