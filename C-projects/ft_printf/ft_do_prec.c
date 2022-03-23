/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_%.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 10:29:53 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/06 08:24:40 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_precentage1(t_print *p)
{
	if (p->p == NULL)
		return (0);
	if (p->pad_amount != 0)
		ft_memset(p->p, ' ', p->pad_amount);
	if (p->zero_present == 1 && p->minuss_present != 1)
			ft_memset(p->p, '0', p->pad_amount);
	if (p->minuss_present == 1)
		ft_memset(p->p, '%', 1);
	else
		ft_memset(p->p + (p->s - 1), '%', 1);
	return (1);
}

static int	ft_continue_precentage(t_list1 *info, t_print *p)
{
	ft_get_pad_char(p);
	if (!ft_continue_precentage1(p))
		return (0);
	if (ft_strlen(p->p))
	{
		ft_putstr(p->p);
		info->total_chars_printed += ft_strlen(p->p);
	}
	else
	{
		write(1, "%", 1);
		info->total_chars_printed += 1;
	}
	return (1);
}

int			ft_do_precentage(t_list1 *info, va_list va, t_print *p)
{
	size_t	index;

	index = 0;
	ft_init_print(p);
	while (info->cs[index] != '\0')
	{
		if (info->cs[index] == '-')
			p->minuss_present = 1;
		if (info->cs[index] == '0')
			p->zero_present = 1;
		if (info->cs[index] == '*')
			ft_cs_st(p, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			p->pad_amount = ft_atoi(info->cs + index);
			index += (ft_intlen(p->pad_amount) - 1);
		}
		index++;
	}
	if (!ft_continue_precentage(info, p))
		return (0);
	return (1);
}
