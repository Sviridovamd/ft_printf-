/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:31:58 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 15:49:59 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		memory(t_parser *f, const char *format, int i, va_list ap)
{
	f->length = 0;
	f->end = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			start_create_struct(f);
			i += filling_struct(format + i, ap, f);
			work_with_type(f, ap);
		}
		else
		{
			write(1, &(format[i]), 1);
			i++;
		}
	}
	if (format[i] == '\n')
	{
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (f->length += i - f->end);
}

int		filling_struct(const char *format, va_list ap, t_parser *f)
{
	int		i;

	i = 1;
	while (!(ft_type(format[i])) && format[i + 1] != '\0')
	{
		if (format[i] == '-')
			f->flags->minus = 1;
		else if (format[i] == '0')
			f->flags->zero = 1;
		else if (ft_isdigit(format[i]))
			put_w(f, format, &i);
		else if (format[i] == '*')
			put_w_star(f, ap);
		else if (format[i] == '.')
		{
			put_p(f, format, ap, &i);
		}
		i++;
	}
	if (ft_type(format[i]))
		f->type = format[i];
	f->end += i + 1;
	return (i + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parser	*f;
	int			i;

	i = 0;
	va_start(ap, format);
	f = (t_parser *)malloc(sizeof(t_parser));
	if (!f)
		return (-1);
	f->flags = (t_flags *)malloc(sizeof(t_flags));
	if (!f->flags)
		return (-1);
	i = memory(f, format, i, ap);
	va_end(ap);
	free(f->flags);
	free(f);
	return (i);
}
