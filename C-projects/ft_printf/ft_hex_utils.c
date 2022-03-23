/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 14:55:49 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:40:15 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexlen(long nr)
{
	int	ret;

	ret = 0;
	if (nr == 0)
		return (1);
	if (nr == -2147483648)
		return (0);
	if (nr < 0)
	{
		nr = -nr;
		ret++;
	}
	while (nr >= 1)
	{
		ret++;
		nr = nr / 16;
	}
	return (ret);
}

char	*ft_convert_str_hex(long integer)
{
	char	*ptr;
	int		length_of_integer;
	long	remainer;

	if (integer == 0)
		return (ft_strdup("0"));
	if (integer < 0)
		integer = UINT_MAX + (integer + 1);
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

char	*ft_convert_str_helx(long integer)
{
	char	*helx;
	int		length_of_integer;
	long	remainer;

	if (integer == 0)
		return (ft_strdup("0"));
	if (integer < 0)
		integer = UINT_MAX + (integer + 1);
	length_of_integer = ft_hexlen(integer);
	helx = ft_calloc(length_of_integer + 1, sizeof(char));
	if (helx == NULL)
		return (NULL);
	while (integer && length_of_integer >= 0)
	{
		length_of_integer--;
		remainer = integer % 16;
		if (remainer < 10)
			helx[length_of_integer] = 48 + remainer;
		else
			helx[length_of_integer] = 55 + remainer;
		integer = integer / 16;
	}
	return (helx);
}

void	ft_get_pad(t_print *p)
{
	if (p->a[0] == '-')
		p->n = 1;
	if (p->pad_amount < 0)
		p->pad_amount = -p->pad_amount;
	if (p->pad_amount >= p->d)
		p->s = p->pad_amount;
	if (p->pad_amount <= p->d)
		p->s = p->d;
	if (p->s <= ft_strlen(p->a))
		p->s = ft_strlen(p->a);
	if (p->n == 1)
		p->p = ft_calloc(p->s + 2, sizeof(char));
	else
		p->p = ft_calloc(p->s + 1, sizeof(char));
	if (p->p == NULL)
		p->s = 0;
}

void	ft_get_pad_str(t_print *p)
{
	if (p->d < 0)
		p->d = ft_strlen(p->a);
	if (p->pad_amount < 0)
		p->pad_amount = -p->pad_amount;
	if (p->pad_amount >= p->d)
		p->s = p->pad_amount;
	if (p->pad_amount <= p->d)
		p->s = p->d;
	if (p->s <= ft_strlen(p->a))
		p->s = ft_strlen(p->a) + 1;
	if (p->n == 1)
		p->p = ft_calloc(p->s + 2, sizeof(char));
	else
		p->p = ft_calloc(p->s + 1, sizeof(char));
	if (p->p == NULL)
		p->s = 0;
}
