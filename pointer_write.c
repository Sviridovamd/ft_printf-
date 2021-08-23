/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:27 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 17:26:27 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			write_p_minus(int zeros, int spaces, char *str_pointer)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putstr_fd("0x", 1);
	while (str_pointer[j])
	{
		ft_putchar_fd(str_pointer[j], 1);
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

int			write_p(int zeros, int spaces, char *str_pointer)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	while (spaces--)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd("0x", 1);
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	while (str_pointer[j])
	{
		ft_putchar_fd(str_pointer[j], 1);
		i++;
		j++;
	}
	return (i);
}

void		pointer_write(t_parser *f, unsigned long long int pointer)
{
	char	*str_pointer;
	int		zeros;
	int		spaces;
	int		i;

	if (f->precision == 0 && pointer == 0)
		str_pointer = ft_strdup("");
	else
		str_pointer = itoa_for_hex(pointer, f);
	zeros = count_zero_in_char(f, str_pointer, 2);
	spaces = count_spaces_in_char(f, str_pointer, zeros, 2);
	if (f->flags->minus)
		i = write_p_minus(zeros, spaces, str_pointer);
	else
		i = write_p(zeros, spaces, str_pointer);
	free(str_pointer);
	f->length += i;
}
