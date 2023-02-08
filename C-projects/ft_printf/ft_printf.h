/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:59:16 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:45:50 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_list3
{
	int		minuss_present;
	int		zero_present;
	int		dot_present;
	int		n;
	int		st;
	long	d;
	long	pad_amount;
	char	*a;
	char	*p;
	size_t	s;
}				t_print;

typedef struct	s_list2
{
	int		total_chars_printed;
	int		length_of_cs_string;
	int		length_of_cs;
	char	*cs;
}				t_list1;

typedef struct	s_list4
{
	char	c;
	int		(*f)(t_list1 *, va_list, t_print *);
}				t_function;

char			*ft_convert_str_ptr(unsigned long integer);
int				ft_printf(const char *str, ...);
int				ft_do_precentage(t_list1 *info, va_list va, t_print *print);
int				ft_do_int(t_list1 *info, va_list va, t_print *print);
int				ft_do_char(t_list1 *info, va_list va, t_print *print);
int				ft_do_ptr(t_list1 *info, va_list va, t_print *print);
int				ft_do_uni(t_list1 *info, va_list va, t_print *print);
int				ft_do_hex(t_list1 *info, va_list va, t_print *print);
int				ft_do_helx(t_list1 *info, va_list va, t_print *print);
int				ft_do_str(t_list1 *info, va_list va, t_print *print);
int				ft_do_s(t_list1 *info, va_list va, t_print *print);
int				ft_check(const char *s, t_list1 *info);
void			ft_init_print(t_print *print);
int				ft_hexlen(long nr);
char			*ft_convert_str_hex(long integer);
char			*ft_convert_str_helx(long integer);
int				ft_hex_zero(t_print *print, t_list1 *info);
int				ft_do_hex(t_list1 *info, va_list va, t_print *print);
int				ft_cs_dot(t_list1 *f, t_print *p, int i, va_list va);
int				ft_free_print(t_print *print);
int				ft_minuss(t_print *p, t_list1 *f);
int				ft_minuss_no_dot(t_print *p, t_list1 *f);
int				ft_minuss_dot(t_print *p, t_list1 *f, long l);
int				ft_no_minuss(t_print *p, t_list1 *f);
int				ft_no_minuss_no_dot(t_print *p, t_list1 *f);
int				ft_no_minuss_dot(t_print *p, t_list1 *f);
void			ft_get_pad(t_print *print);
int				ft_str_null_1(t_print *p, t_list1 *i);
void			ft_get_pad_str(t_print *print);
int				ft_str_dot(t_print *p, t_list1 *i);
int				ft_str_minuss_no_dot(t_print *p, t_list1 *i);
int				ft_str_dot(t_print *p, t_list1 *i);
int				ft_str_no_dot(t_print *p, t_list1 *i);
int				ft_str_dot_minuss(t_print *p, t_list1 *i);
int				ft_str_dot_no_minuss(t_print *p, t_list1 *i);
int				ft_str_no_dot_no_minuss(t_print *p, t_list1 *i);
int				ft_str_no_dot_minuss(t_print *p, t_list1 *i);
int				ft_no_minuss_no_dot_int(t_print *p, t_list1 *f);
int				ft_minuss_no_dot_int(t_print *p, t_list1 *f);
int				ft_no_minuss_dot_int(t_print *p, t_list1 *f);
int				ft_minuss_int(t_print *p, t_list1 *f);
int				ft_no_minuss_int(t_print *p, t_list1 *f);
int				ft_no_minuss_no_dot_int(t_print *p, t_list1 *f);
int				ft_minuss_dot_int(t_print *p, t_list1 *f, long l);
void			ft_cs_st(t_print *p, va_list va);
void			ft_con_ptr(t_print *print, char *tmp);
int             		ft_free_in(t_list1 *info, va_list va, t_print *p);
void			ft_get_pad_char(t_print *p);
void			ft_init_info(t_list1 *info);
int				ft_edge(t_list1 *info, t_print *p);
#endif
