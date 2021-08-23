/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:52:26 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 15:54:10 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		write_x_minus(int zeros, int spaces, char *str_hex)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (str_hex[j])
	{
		ft_putchar_fd(str_hex[j], 1);
		i++;
		j++;
	}
	while (spaces--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		write_x(int zeros, int spaces, char *str_hex)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
	while (str_hex[j])
	{
		ft_putchar_fd(str_hex[j], 1);
		i++;
		j++;
	}
	return (i);
}

int		count_zero_in_char(t_parser *f, char *str_hex, int for_pointer)
{
	int size;

	size = ft_strlen((const char *)str_hex);
	if (f->precision > size)
		return (f->precision - size);
	else if (!(f->flags->minus) && f->precision == -1 && f->flags->zero
		&& f->width > size + for_pointer)
		return (f->width - size - for_pointer);
	return (0);
}

int		count_spaces_in_char(t_parser *f, char *str_hex,
	int zeros, int for_pointer)
{
	int size;

	size = ft_strlen((const char *)str_hex);
	if (f->width > size + zeros + for_pointer)
		return (f->width - size - zeros - for_pointer);
	return (0);
}

void	hexa_write(t_parser *f, unsigned int digit)
{
	char	*str_hex;
	int		zeros;
	int		spaces;
	int		i;

	if (f->precision == 0 && digit == 0)
		str_hex = ft_strdup("");
	else
		str_hex = itoa_for_hex(digit, f);
	zeros = count_zero_in_char(f, str_hex, 0);
	spaces = count_spaces_in_char(f, str_hex, zeros, 0);
	if (f->flags->minus)
		i = write_x_minus(zeros, spaces, str_hex);
	else
		i = write_x(zeros, spaces, str_hex);
	f->length += i;
	free(str_hex);
}
