/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:07:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 15:02:10 by asebrech         ###   ########.fr       */
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
	int		point;
	int		precision;
	char	type;
}				t_struct;

int			ft_printf(const char *format, ...);
int			ft_convert(const char *format, va_list args, t_struct *data);
int			ft_convert_mod(t_struct *data);
int			ft_convert_d(va_list args, t_struct *data);
int			ft_convert_u(va_list args, t_struct *data);
int			ft_convert_c(t_struct *data, va_list args);
void		ft_putnbr_base_fd(unsigned long nb, char *base, int fd, int *ret);
void		ft_init_struct(t_struct *data);
const char	*ft_parsing(const char *format, va_list args, t_struct *data);

#endif
