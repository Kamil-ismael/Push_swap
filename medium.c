/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toavandr <toavandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:24:53 by toavandr          #+#    #+#             */
/*   Updated: 2026/03/27 22:59:16 by toavandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void medium_sort(t_info *a, t_info *b)
{
    int size;
    int chunk;
    int limit;
    int i;

    size = a->size_a;
    chunk = sqrt(size);
    limit = chunk;
    i = 0;
    while (a->size_a)
    {
        if (a->stack_a->index <= i)
        {
            pb(a, b);
            i++;
        }
        else if (a->stack_a->index <= limit)
        {
            pb(a, b);
            i++;
            limit += chunk;
        }
        else
            ra(a);
    }
    while (b->size_b)
        pa(a, b);
}