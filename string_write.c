/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:30 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 17:16:41 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_zero_str(t_parser *f, int len)
{
	if (f->flags-> zero && !(f->flags->minus) && f->width > len)
		return (f->width - len);
	return (0);
}

int		count_space_str(t_parser *f, int len)
{
	if (f->flags->minus)
	{
		if (f->width > len)
			return (f->width - len);
	}
	else
	{
		if (!(f->flags->zero) && (f->width > len))
			return (f->width - len);
	}
	return (0);
}

int		write_s_minus(int zeros, int spaces, char *format, int lg)
{
	int i;

	i = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (*format && lg--)
	{
		ft_putchar_fd(*format, 1);
		format++;
		i++;
	}
	while (spaces--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		write_s(int zeros, int spaces, char *format, int lg)
{
	int i;

	i = 0;
	{
		while (spaces--)
		{
			write(1, " ", 1);
			i++;
		}
		while (zeros--)
		{
			write(1, "0", 1);
			i++;
		}
		while (*format && lg--)
		{
			ft_putchar_fd(*format, 1);
			format++;
			i++;
		}
	}
	return (i);
}

void	string_write(t_parser *f, char *format)
{
	int	lg;
	int	zeros;
	int	spaces;
	int	i;

	if (!format)
		format = "(null)";
	if (f->precision >= 0 && f->precision < ft_strlen((const char *)format))
		lg = f->precision;
	else
		lg = ft_strlen((const char *)format);
	zeros = count_zero_str(f, lg);
	spaces = count_space_str(f, lg);
	if (f->flags->minus)
		i = write_s_minus(zeros, spaces, format, lg);
	else
		i = write_s(zeros, spaces, format, lg);
	f->length += i;
}
