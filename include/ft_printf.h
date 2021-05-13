/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:16:51 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/13 16:03:24 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
void		d_flag(t_struct *data, char *str, char *nbr);
char		*ft_itoa_base(long int nbr, char *base, int p);
const char	*ft_parsing(const char *format, va_list args, t_struct *data);
#endif
