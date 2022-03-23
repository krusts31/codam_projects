/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:27:01 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:44:37 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cs_st(t_print *p, va_list va)
{
	p->pad_amount = va_arg(va, int);
	if (p->pad_amount < 0)
		p->minuss_present = 1;
}

int		ft_cs_dot(t_list1 *f, t_print *p, int i, va_list va)
{
	p->dot_present = 1;
	i++;
	if (f->cs[i] == '0')
	{
		p->zero_present = 1;
		i++;
	}
	if (f->cs[i] > '0' && f->cs[i] <= '9')
	{
		p->d = ft_atoi(f->cs + i);
		i += ft_intlen(p->d);
	}
	if (f->cs[i] == '*')
	{
		p->d = va_arg(va, int);
		if (p->d < 0)
			p->dot_present = 0;
		i++;
	}
	return (i);
}

char	*ft_convert_str_ptr(unsigned long integer)
{
	char	*ptr;
	int		length_of_integer;
	int		remainer;

	if (integer == 0)
		return (ft_strdup("0x0"));
	length_of_integer = ft_hexlen(integer);
	ptr = ft_calloc(length_of_integer + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (integer && length_of_integer >= 0)
	{
		length_of_integer--;
		remainer = integer % 16;
		if (remainer < 10)
			ptr[length_of_integer] = 48 + remainer;
		else
			ptr[length_of_integer] = 87 + remainer;
		integer = integer / 16;
	}
	return (ptr);
}

int		ft_check(const char *s, t_list1 *info)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = ft_strchr(s, '%');
	if (ptr == 0)
	{
		ft_putstr(s);
		info->total_chars_printed = info->total_chars_printed + ft_strlen(s);
		info->length_of_cs_string = info->length_of_cs_string + ft_strlen(s);
		return (-1);
	}
	else
	{
		while (s[index] != *ptr)
		{
			write(1, s + index, 1);
			index++;
		}
		info->total_chars_printed = info->total_chars_printed + index;
		info->length_of_cs_string = info->length_of_cs_string + index;
		return (index);
	}
	return (1);
}

void	ft_init_print(t_print *print)
{
	print->p = NULL;
	print->a = NULL;
	print->s = 0;
	print->minuss_present = 0;
	print->zero_present = 0;
	print->dot_present = 0;
	print->pad_amount = 0;
	print->d = 0;
	print->st = 0;
	print->n = 0;
	return ;
}
