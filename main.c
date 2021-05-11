/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 18:48:00 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int				test;
int				test1;
char			c = '%';
char			*s = "This is the way";
int				d = -7567;
int				i = 22;
unsigned int	u = 7567;
unsigned int	x = 4294967295;
unsigned int	X = 4294967295;
char			*p = "test";

int	main(void)
{
	ft_printf("ft_printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n", c, s, d, i, u, x, X, p);
	printf("OR printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n\n", c, s, d, i, u, x, X, p);
	

	test = ft_printf("FT : %22s\n", s);
	test1 = printf("OR : %22s\n", s);

	ft_printf("FT : %d\n", test);
	ft_printf("OR : %d\n", test1);
}
