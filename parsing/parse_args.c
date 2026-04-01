/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:36:05 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/01 12:26:34 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node   *create_node(int value)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        error_exit();
    node->value = value;
    node->index = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

static void     append_to_stack(t_info *info, int value)
{
    t_node  *new;
    t_node  *last;

    new = create_node(value);
    if (!info->stack_a)
    {
        info->stack_a = new;
        return ;
    }
    last = info->stack_a;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
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

