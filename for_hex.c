/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:58:39 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 15:17:12 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_size_base(unsigned long long int digit, int len)
{
	int count;

	if (!len)
		return (0);
	if (digit == 0)
		return (1);
	count = 0;
	while (digit)
	{
		digit /= len;
		count++;
	}
	return (count);
}

char		*itoa_for_hex(unsigned long long int digit, t_parser *f)
{
	char	*string_x;
	char	*string_xx;
	int		size;
	char	*tmp;

	string_x = "0123456789abcdef";
	string_xx = "0123456789ABCDEF";
	size = ft_size_base(digit, 16);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmp[size] = '\0';
	if (f->type == 'x' || f->type == 'p')
		while (size--)
		{
			tmp[size] = string_x[digit % 16];
			digit /= 16;
		}
	else if (f->type == 'X')
		while (size--)
		{
			tmp[size] = string_xx[digit % 16];
			digit /= 16;
		}
	return (tmp);
}
