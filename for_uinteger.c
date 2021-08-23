/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_uinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:30:36 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 15:31:24 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		len_unum(unsigned int i)
{
	int	l;

	l = 0;
	while (i / 10)
	{
		i /= 10;
		l++;
	}
	return (l);
}

char	*ft_urevstring(char *str)
{
	int				i;
	int				size;
	char			c;

	i = 0;
	size = ft_strlen((const char *)str) - 1;
	while (i < size)
	{
		c = str[i];
		str[i++] = str[size];
		str[size--] = c;
	}
	return (str);
}

int		ft_usize(unsigned int num)
{
	int				si;

	si = 0;
	if (num < 0)
	{
		num = -num;
		si++;
	}
	if (num == 0)
		return (si += 1);
	while (num > 0)
	{
		num /= 10;
		si++;
	}
	return (si);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	size;
	char			*numstr;

	numstr = NULL;
	size = ft_usize(n);
	numstr = ft_unum_str(n, size);
	if (!numstr)
		return (0);
	return (ft_urevstring(numstr));
}

char	*ft_unum_str(unsigned int n, unsigned int size)
{
	char			*dest;
	int				i;
	unsigned int	num;

	dest = NULL;
	dest = (char *)malloc(sizeof(char) * 1 + size);
	if (!dest)
		return (NULL);
	if (n < 0)
		num = n * -1;
	else
		num = n;
	i = 0;
	while (num > 0)
	{
		dest[i++] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		dest[i++] = '-';
	else if (n == 0)
		dest[i++] = '0';
	dest[i] = '\0';
	return (dest);
}
