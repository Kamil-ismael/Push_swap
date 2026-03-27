/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toavandr <toavandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:52:06 by toavandr          #+#    #+#             */
/*   Updated: 2026/03/27 23:02:13 by toavandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void adaptive_sort(t_info *a, t_info *b)
{
    double d;

    d = compute_disorder(a);
    if (d < 0.2)
        simple_sort(a, b);
    else if (d < 0.5)
        medium_sort(a, b);
    else
        radix_sort(a, b);
}