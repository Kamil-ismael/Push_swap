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

void    pb(t_stack *a, t_stack *b)
{
    t_node *tmp;

    if (a->size == 0)
        return;
    tmp = a->top;
    a->top = tmp->next;
    a->size--;

    tmp->next = b->top;
    b->top = tmp;
    b->size++;

    write(1, "pb\n", 3);
}

void    pa(t_stack *a, t_stack *b)
{
    t_node *tmp;

    if (b->size == 0)
        return;
    tmp = b->top;
    b->top = tmp->next;
    b->size--;

    tmp->next = a->top;
    a->top = tmp;
    a->size++;

    write(1, "pa\n", 3);
}

void ra(t_stack *a)
{
    t_node *f, *l;

	f = a->top;
    if (a->size < 2) 
		return;
    a->top = f->next;
    l = a->top;
    while (l->next) 
		l = l->next;
    l->next = f;
    f->next = NULL;
    write(1, "ra\n", 3);
}

void rra(t_stack *a)
{
    t_node *prev, *l;

	prev = a->top;
	l = a->top;
    if (a->size < 2) 
		return;
    while (l->next)
	{
		prev = l; 
		l = l->next;
	}
    prev->next = NULL;
    l->next = a->top;
    a->top = l;
    write(1, "rra\n", 4);
}