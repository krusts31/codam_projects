/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_hex_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 21:19:52 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:51:59 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_no_minuss_dot(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->a);
	if (p->pad_amount > (long)ft_strlen(p->a) && p->pad_amount > p->d)
		ft_memset(p->p, ' ', p->s - (p->n + 1));
	if ((long)ft_strlen(p->a) < p->d)
	{
		ft_memset(p->p + (p->s - p->d), '0', (p->d - (l - p->n)) + p->n); //this p->n does not make sense
		if (p->n == 1 && p->s - p->d != 0)
			ft_memmove(p->p + ((p->s - p->d) - p->n), "-", 1);
		if (p->n == 1 && p->s - p->d == 0)
			ft_memmove(p->p + (p->s - p->d), "-", 1);
		if (p->n == 1 && p->pad_amount < p->d)
			ft_memmove(p->p + (p->s - l - 1) + 1, p->a + 1, l - 1);
		else
			ft_memmove(p->p + (p->s - (l + p->n)), p->a + p->n, l - p->n); // merge if with else
	}
	else
		ft_memmove(p->p + (p->s - l), p->a, l);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int	ft_minuss_no_dot(t_print *p, t_list1 *f)
{
	if (p->zero_present == 0 && p->pad_amount - p->n > 0)
			ft_memset(p->p + p->n, ' ', p->pad_amount - p->n);
	if (p->zero_present == 1 && p->pad_amount - p->n > 0)
		ft_memset(p->p + p->n, '0', p->pad_amount - p->n);
	ft_memmove(p->p + p->n, p->a + p->n, ft_strlen(p->a) - p->n);
	if (p->n == 1)
		ft_memmove(p->p, "-", 1);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int	ft_minuss_dot(t_print *p, t_list1 *f, long l)
{
	if (p->pad_amount > (long)ft_strlen(p->a) && p->pad_amount > p->d)
		ft_memset(p->p + p->n, ' ', p->s - p->n);
	if ((long)ft_strlen(p->a) < p->d)
	{
		ft_memset(p->p + p->n, '0', (p->d));
		if (p->n == 1)
		{
			ft_memmove(p->p, "-", 1);
			ft_memmove(p->p + (p->d - (l + p->n)) + 1, p->a + 1, l - 1);
		}
		else
			ft_memmove(p->p + (p->d - l), p->a, l);
	}
	else
	{
		ft_memmove(p->p + p->n, p->a + p->n, ft_strlen(p->a) - p->n);
		if (p->n == 1)
			ft_memmove(p->p, "-", 1);
	}
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int	ft_no_minuss_no_dot(t_print *p, t_list1 *f)
{
	long	l;

	l = (long)ft_strlen(p->a);
	if (p->zero_present == 0)
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->p, ' ', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->p + (p->s - l), "-", 1);
	}
	else
	{
		if ((long)p->pad_amount - l > 0)
			ft_memset(p->p + p->n, '0', (p->pad_amount - l));
		if (p->n == 1)
			ft_memmove(p->p, "-", 1);
	}
	ft_memmove(p->p + (p->s - l) + p->n, p->a + p->n, l - p->n);
	ft_putstr(p->p);
	f->total_chars_printed += ft_strlen(p->p);
	return (1);
}

int	ft_free_print(t_print *pi)
{
	if (pi != NULL)
	{
		free(pi->p);
		free(pi->a);
	}
	free(pi);
	return (0);
}
