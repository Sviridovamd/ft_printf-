/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:33 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 16:44:53 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_z_in_integer(t_parser *f, int digit)
{
	int		lg_digit;

	if (f->precision == 0 && digit == 0)
		lg_digit = 0;
	else
	{
		if (digit < 0)
			lg_digit = (len_num(digit) + 1);
		else
			lg_digit = len_num(digit) + 1;
	}
	if (f->precision - lg_digit > 0)
		return (f->precision - lg_digit);
	else if (f->flags->zero && !(f->flags->minus) && f->width - lg_digit > 0
		&& f->precision < 0)
	{
		if (digit >= 0)
			return (f->width - lg_digit);
		return (f->width - lg_digit - 1);
	}
	return (0);
}

int		count_s_in_integer(t_parser *f, int digit, int zeros)
{
	int lg_digit;

	if (f->precision == 0 && digit == 0)
		lg_digit = 0;
	else
	{
		if (digit < 0)
			lg_digit = (len_num(digit) + 2);
		else
			lg_digit = len_num(digit) + 1;
	}
	if (f->width - lg_digit - zeros > 0)
		return (f->width - lg_digit - zeros);
	return (0);
}

int		write_i_minus(t_parser *f, int digit, int zeros)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_itoa(digit);
	if (digit < 0)
	{
		ft_putchar_fd(num[j++], 1);
		i++;
	}
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

int		write_i(t_parser *f, int digit, int zeros)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_itoa(digit);
	if (digit < 0)
	{
		ft_putchar_fd(num[j++], 1);
		i++;
	}
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

void	write_integer(t_parser *f, int digit)
{
	int		zeros;
	int		spaces;
	int		i;

	zeros = count_z_in_integer(f, digit);
	spaces = count_s_in_integer(f, digit, zeros);
	i = 0;
	if (f->flags->minus)
	{
		i += write_i_minus(f, digit, zeros);
		write_spaces(spaces, &i);
	}
	else
	{
		write_spaces(spaces, &i);
		i += write_i(f, digit, zeros);
	}
	f->length += i;
}
