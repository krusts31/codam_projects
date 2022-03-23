/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_do_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:56:05 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:37:48 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_str(t_list1 *info, va_list va, t_print *p)
{
	p->a = va_arg(va, char *);
	if (p->a == NULL)
		p->a = ft_strdup("(null)");
	else
		p->a = ft_strdup(p->a);
	if (p->a == NULL)
		return (0);
	ft_get_pad_str(p);
	if (p->s == 0 || p->a == NULL)
		return (0);
	if (p->dot_present == 0)
		return (ft_str_no_dot(p, info));
	else
		return (ft_str_dot(p, info));
}

int			ft_do_str(t_list1 *info, va_list va, t_print *p)
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
		if (info->cs[index] == '.')
			index = ft_cs_dot(info, p, index, va);
		if (info->cs[index] == '*')
			ft_cs_st(p, va);
		if (info->cs[index] > '0' && info->cs[index] <= '9')
		{
			p->pad_amount = ft_atoi(info->cs + index);
			index += (ft_intlen(p->pad_amount) - 1);
		}
		index++;
	}
	if (!ft_continue_str(info, va, p))
		return (0);
	return (1);
}
