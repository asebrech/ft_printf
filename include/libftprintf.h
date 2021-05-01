/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:07:35 by asebrech          #+#    #+#             */
/*   Updated: 2021/05/01 13:05:16 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

void	ft_printf(const char *format, ...);
void	ft_convert(const char *format, va_list args);
void	ft_putnbr_base_fd(long int nb, char *base, int fd);

#endif
