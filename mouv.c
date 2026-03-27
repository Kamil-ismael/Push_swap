/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toavandr <toavandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:46:11 by toavandr          #+#    #+#             */
/*   Updated: 2026/03/27 20:29:42 by toavandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_info *a, t_info *b)
{
    t_node *tmp;

    if (a->size_a == 0)
        return;
    tmp = a->stack_b;
    a->stack_b = tmp->next;
    a->size_a--;

    tmp->next = b->stack_b;
    b->stack_b = tmp;
    b->size_b++;

    write(1, "pb\n", 3);
}

void    pa(t_info *a, t_info *b)
{
    t_node *tmp;

    if (b->size_b == 0)
        return;
    tmp = b->stack_b;
    b->stack_b = tmp->next;
    b->size_b--;

    tmp->next = a->stack_a;
    a->stack_a = tmp;
    a->size_a++;

    write(1, "pa\n", 3);
}

void ra(t_info *a)
{
    t_node *f, *l;

	f = a->stack_a;
    if (a->size_a < 2) 
		return;
    a->stack_a = f->next;
    l = a->stack_a;
    while (l->next) 
		l = l->next;
    l->next = f;
    f->next = NULL;
    write(1, "ra\n", 3);
}

void rra(t_info *a)
{
    t_node *prev, *l;

	prev = a->stack_a;
	l = a->stack_a;
    if (a->size_a < 2) 
		return;
    while (l->next)
	{
		prev = l; 
		l = l->next;
	}
    prev->next = NULL;
    l->next = a->stack_a;
    a->stack_a = l;
    write(1, "rra\n", 4);
}