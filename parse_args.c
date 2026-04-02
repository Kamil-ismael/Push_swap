/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:36:05 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 10:34:46 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_to_stack(t_info *info, int value)
{
	t_node	*new;

	new = ft_lstnew_ps(value);
	if (!new)
		error_exit();
	ft_lstadd_back_ps(&info->stack_a, new);
}

void            parse_args(t_info *info, int argc, char **argv)
{
    int     i;
    long    val;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            error_exit();
        val = ft_atol(argv[i]);
        if (val < INT_MIN || val > INT_MAX)
            error_exit();
        if (has_duplicate(info->stack_a, (int)val))
            error_exit();
        append_to_stack(info, (int)val);
        info->size_a++;
        i++;
    }
}

