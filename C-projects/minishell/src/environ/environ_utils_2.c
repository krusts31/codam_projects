/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environ.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts/dkrecisz <codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 15:55:04 by alkrusts/dk   #+#    #+#                 */
/*   Updated: 2021/11/01 14:51:20 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environ.h"
#include <stdlib.h>

void	environ_modify_prep(t_environ **head, t_environ *prep)
{
	t_environ	*new;

	new = minishell_calloc(1, sizeof(t_environ));
	new->key = prep->key;
	new->value = prep->value;
	new->key_value = prep->key_value;
	environ_modify(head, new);
	free(new);
}
