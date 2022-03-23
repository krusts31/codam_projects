/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_utils_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 13:46:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:47:12 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_con_dot_no_min(t_print *p, long s)
{
	if (p->pad_amount != 0 && p->d != 0)
	{
		if (p->pad_amount - s >= 0)
			ft_memmove(p->p + (p->pad_amount - s), p->a, s);
		else
			ft_memmove(p->p, p->a, s);
	}
	else
		ft_memmove(p->p, p->a, s);
}

int			ft_str_dot_no_minuss(t_print *p, t_list1 *i)
{
	long	s;

	s = (long)ft_strlen(p->a);
	if (p->pad_amount - p->d >= 0)
	{
		if (p->d <= s)
			ft_memmove(p->p + (p->pad_amount - p->d), p->a, p->d);
		else
			ft_memmove(p->p + (p->pad_amount - s), p->a, s);
	}
	else
	{
		ft_memset(p->p, ' ', p->pad_amount);
		if (p->d <= s)
			ft_memmove(p->p, p->a, p->d);
		else
			ft_con_dot_no_min(p, s);
	}
	ft_putstr(p->p);
	i->total_chars_printed += ft_strlen(p->p);
	return (1);
}
