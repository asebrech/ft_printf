/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:06:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/13 11:31:45 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				test;
int				test1;
char			c = '%';
char			*s = "This is the way";
int				d = 0;
int				i = 22;
unsigned int	u = 7567;
unsigned int	x = 4294967294;
unsigned int	X = 4294967294;
char			*p = "test";

int	main(void)
{
	//test = ft_printf("ft_printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n", c, s, d, i, u, x, X, p);
	//test1 = printf("OR printf :: c : %c / s : %s / d: %d i: %i / u : %u / x : %x / X : %X / %% : %% / p : %p\n", c, s, d, i, u, x, X, p);
	

	test = ft_printf("FT : %*.*d\n", 2, -2, 8);
	  test1 = printf("OR : %*.*d\n", 2, -2, 8);
	 //test1 = printf(", %*.*d, \n", 1, 0, d);

	printf("FT : %d\n", test);
	printf("OR : %d\n", test1);
}
