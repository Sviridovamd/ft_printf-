/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:18:58 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 15:24:52 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int			len_num(int i)
{
	int		l;

	l = 0;
	while (i / 10)
	{
		i /= 10;
		l++;
	}
	return (l);
}

void		start_create_struct(t_parser *f)
{
	f->flags->minus = 0;
	f->flags->zero = 0;
	f->width = -1;
	f->precision = -1;
	f->type = -1;
}

void		work_with_type(t_parser *f, va_list ap)
{
	if (f->type == 's')
		string_write(f, va_arg(ap, char *));
	if (f->type == 'c')
		char_write(f, va_arg(ap, int));
	if (f->type == 'd' || f->type == 'i')
		write_integer(f, va_arg(ap, int));
	if (f->type == '%')
		char_write(f, '%');
	if (f->type == 'u')
		write_uinteger(f, va_arg(ap, unsigned int));
	if (f->type == 'x')
		hexa_write(f, va_arg(ap, unsigned int));
	if (f->type == 'X')
		hexa_write(f, va_arg(ap, unsigned int));
	if (f->type == 'p')
		pointer_write(f, va_arg(ap, unsigned long long int));
}
