/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:07:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/11 18:36:06 by asebrech         ###   ########.fr       */
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
int			ft_sort(const char *format, va_list args, t_struct *data);
int			ft_convert_char(char c, t_struct *data);
int			ft_convert_nbr(char *nbr, t_struct *data);
int			ft_convert_str(char *str, t_struct *data);
void		ft_putnbr_base_fd(unsigned long nb, char *base, int fd, int *ret);
char		*ft_itoa_base(long int nbr, char *base, int p);
void		ft_init_struct(t_struct *data);
const char	*ft_parsing(const char *format, va_list args, t_struct *data);

#endif
