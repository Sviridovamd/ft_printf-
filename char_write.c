/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:50:46 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 14:53:49 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			write_c_minus(char c, int zeros, int spaces)
{
	int i;

	i = 0;
	while (zeros--)
	{
		write(1, "0", 1);
		i++;
	}
	ft_putchar_fd(c, 1);
	i++;
	while (spaces--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int			write_c(char c, int zeros, int spaces)
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
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

void		char_write(t_parser *f, char c)
{
	int zeros;
	int spaces;
	int i;

	zeros = count_zero_str(f, 1);
	spaces = count_space_str(f, 1);
	i = 0;
	if (f->flags->minus)
		i = write_c_minus(c, zeros, spaces);
	else
		i = write_c(c, zeros, spaces);
	f->length += i;
}
