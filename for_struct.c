/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:25:35 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 16:32:46 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_w(t_parser *f, const char *format, int *i)
{
	f->width = ft_atoi(format + *i);
	*i += len_num(f->width);
	if (f->width < 0)
	{
		f->flags->minus = 1;
		f->width = f->width * (-1);
	}
}

void	put_w_star(t_parser *f, va_list ap)
{
	f->width = va_arg(ap, int);
	if (f->width < 0)
	{
		f->flags->minus = 1;
		f->width = f->width * (-1);
	}
}

void	put_p(t_parser *f, const char *format, va_list ap, int *i)
{
	f->precision = 0;
	*i = *i + 1;
	if (ft_isdigit(format[*i]) || format[*i] == '-')
	{
		f->precision = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]) || format[*i] == '-')
			*i = *i + 1;
		*i = *i - 1;
	}
	else if (format[*i] == '*')
	{
		f->precision = va_arg(ap, int);
	}
	else
		*i = *i - 1;
	if (f->precision < 0)
		f->precision = -1;
}

void	write_spaces(int spaces, int *i)
{
	while (spaces--)
	{
		write(1, " ", 1);
		*i = 1 + *i;
	}
}
