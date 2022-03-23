/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 17:41:03 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/12/25 13:48:42 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_function g_var[10] = {
	{'d', &ft_do_int},
	{'c', &ft_do_char},
	{'s', &ft_do_str},
	{'p', &ft_do_ptr},
	{'i', &ft_do_int},
	{'u', &ft_do_uni},
	{'x', &ft_do_hex},
	{'X', &ft_do_helx},
	{'%', &ft_do_precentage},
	{'\0', NULL}
};

static int	find_my_purpuse(t_list1 *info, va_list va, t_print **print)
{
	int		i;
	info->length_of_cs = 0;
	*print = ft_calloc(sizeof(t_print), 1);
	if (*print == NULL)
		return (0);
	while (info->cs[info->length_of_cs] != '\0')
	{
		info->length_of_cs++;
		i = 0;
		while (g_var[i].c != '\0')
		{
			if (g_var[i].c == info->cs[info->length_of_cs])
			{
				if (!g_var[i].f(info, va, *print))
					return (0);
				return (1);
			}
			i++;
		}
	}
	return (1);
}

static int	ft_chop(const char *s, t_list1 *info)
{
	int		x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
		if (ft_strchr("cspdiuxX%", s[x]))
		{
			info->cs = ft_calloc(x + 2, sizeof(char));
			if (info->cs == NULL)
				return (0);
			ft_memmove(info->cs, s, x + 1);
			return (1);
		}
	}
	return (1);
}

static int	ft_find(const char *s, t_list1 *info)
{
	while (s[info->length_of_cs_string] != '\0')
	{
		if (s[info->length_of_cs_string] == '%')
		{
			if (!ft_chop(&s[info->length_of_cs_string], info))
				return (0);
			info->length_of_cs_string = info->length_of_cs_string +
				ft_strlen(info->cs);
			return (1);
		}
		else
		{
			ft_putchar(s[info->length_of_cs_string]);
			info->total_chars_printed = info->total_chars_printed + 1;
			info->length_of_cs_string = info->length_of_cs_string + 1;
		}
	}
	return (1);
}

int			ft_printf(const char *str, ...)
{
	t_list1 *info;
	va_list	va;
	t_print	*print;
	size_t	ret;

	va_start(va, str);
	print = NULL; 
	info = ft_calloc(sizeof(t_list1), 1);
	if (info == NULL)
		return (ft_free_in(info, va, print));
	ft_init_info(info);
	while (str[info->length_of_cs_string] != '\0')
	{
		if (!ft_find(str, info))
			return (ft_free_in(info, va, print));
		if (info->cs != NULL)
		{
			if (!find_my_purpuse(info, va, &print))
				return (ft_free_in(info, va, print));
			free(info->cs);
			info->cs = NULL;
			ft_free_print(print);
			print = NULL;
		}
	}
	ret = info->total_chars_printed;
	ft_free_in(info, va, print);
	return (ret);
}
