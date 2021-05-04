/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:07:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/04 15:51:13 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct s_struct
{
	char	flag;
	int		width;
	int		precision;
	char	type;
}				t_struct;

void		ft_printf(const char *format, ...);
void		ft_convert(const char *format, va_list args);
void		ft_putnbr_base_fd(unsigned long int nb, char *base, int fd);
void		ft_init_struct(t_struct *data);
const char	*ft_parsing(const char *format, va_list args, t_struct *data);

#endif
