/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/06 16:58:24 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int				test;
char			c = 'Z';
char			*s = "This is the way";
int				d = 117;
int				i = 22;
unsigned int	u = 4294967295;
unsigned int	x = 4294967295;
unsigned int	X = 4294967295;
char			*p = "test";

int	main(void)
{
	//ft_printf("ft_printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n", c, s, d, i, u, x, X, p);
	//printf("OR printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n\n", c, s, d, i, u, x, X, p);
	
	
	test = ft_printf("%22.1d\n", d);
	printf("%d\n", test);
}
