/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uinteger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:36 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 16:46:03 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		write_u_minus(t_parser *f, unsigned int digit, int zeros)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_uitoa(digit);
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (num[j] && (f->precision || digit != 0))
	{
		ft_putchar_fd(num[j], 1);
		i++;
		j++;
	}
	return (i);
}

int		write_u(t_parser *f, unsigned int digit, int zeros)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_uitoa(digit);
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (num[j] && (f->precision || digit != 0))
	{
		ft_putchar_fd(num[j], 1);
		i++;
		j++;
	}
	free(num);
	return (i);
}

int		count_z_in_uinteger(t_parser *f, unsigned int digit)
{
	int		lg_digit;

	if (f->precision == 0 && digit == 0)
		lg_digit = 0;
	else
		lg_digit = len_unum(digit) + 1;
	if (f->precision - lg_digit > 0)
		return (f->precision - lg_digit);
	else if (f->flags->zero && !(f->flags->minus) &&
		f->width - lg_digit > 0 && f->precision < 0)
		return (f->width - lg_digit);
	return (0);
}

int		count_s_in_uinteger(t_parser *f, unsigned int digit, int zeros)
{
	int		lg_digit;

	if (f->precision == 0 && digit == 0)
		lg_digit = 0;
	else
		lg_digit = len_unum(digit) + 1;
	if (f->width - lg_digit - zeros > 0)
		return (f->width - lg_digit - zeros);
	return (0);
}

void	write_uinteger(t_parser *f, unsigned int digit)
{
	int		zeros;
	int		spaces;
	int		i;

	zeros = count_z_in_uinteger(f, digit);
	spaces = count_s_in_uinteger(f, digit, zeros);
	i = 0;
	if (f->flags->minus)
	{
		i += write_u_minus(f, digit, zeros);
		write_spaces(spaces, &i);
	}
	else
	{
		write_spaces(spaces, &i);
		i += write_u(f, digit, zeros);
	}
	f->length += i;
}
