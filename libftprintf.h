/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:23 by wmadison          #+#    #+#             */
/*   Updated: 2021/01/11 17:07:15 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_flags
{
	int			minus;
	int			zero;
}				t_flags;

typedef struct	s_parser
{
	t_flags		*flags;
	int			width;
	int			precision;
	char		type;
	int			length;
	int			end;
}				t_parser;

int				ft_printf(const char *format, ...);
int				len_num(int i);
void			string_write(t_parser *f, char *format);
int				count_zero_str(t_parser *f, int len);
int				count_space_str(t_parser *f, int len);
int				filling_struct(const char *format, va_list ap, t_parser *f);
void			work_with_type(t_parser *f, va_list ap);
void			char_write(t_parser *f, char c);
void			write_integer(t_parser *f, int digit);
int				count_s_in_uinteger(t_parser *f, unsigned int digit, int zeros);
void			write_uinteger(t_parser *f, unsigned int digit);
int				ft_type(char c);
void			hexa_write(t_parser *f, unsigned int digit);
void			pointer_write(t_parser *f, unsigned long long int pointer);
int				count_zero_in_char(t_parser *f, char *str_hex, int for_pointer);
int				count_spaces_in_char(t_parser *f, char *str_hex,
	int zeros, int for_pointer);
int				ft_size_base(unsigned long long int digit, int len);
char			*itoa_for_hex(unsigned long long int digit, t_parser *f);
int				len_unum(unsigned int i);
char			*ft_urevstring(char *str);
int				ft_usize(unsigned int num);
char			*ft_uitoa(unsigned int n);
char			*ft_unum_str(unsigned int n, unsigned int size);
void			start_create_struct(t_parser *f);
void			put_w(t_parser *f, const char *format, int *i);
void			put_w_star(t_parser *f, va_list ap);
void			put_p(t_parser *f, const char *format, va_list ap, int *i);
void			write_spaces(int spaces, int *i);
#endif
