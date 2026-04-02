/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:15:00 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 10:15:16 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_info *info)
{
	t_node	*tmp;

	if (!info->stack_a)
		return ;
	tmp = info->stack_a;
	info->stack_a = tmp->next;
	if (info->stack_a)
		info->stack_a->prev = NULL;
	tmp->next = info->stack_b;
	tmp->prev = NULL;
	if (info->stack_b)
		info->stack_b->prev = tmp;
	info->stack_b = tmp;
	info->size_a--;
	info->size_b++;
	write(1, "pb\n", 3);
	info->bench.op_pb++;
	info->bench.op_total++;
}

void	pa(t_info *info)
{
	t_node	*tmp;

	if (!info->stack_b)
		return ;
	tmp = info->stack_b;
	info->stack_b = tmp->next;
	if (info->stack_b)
		info->stack_b->prev = NULL;
	tmp->next = info->stack_a;
	tmp->prev = NULL;
	if (info->stack_a)
		info->stack_a->prev = tmp;
	info->stack_a = tmp;
	info->size_b--;
	info->size_a++;
	write(1, "pa\n", 3);
	info->bench.op_pa++;
	info->bench.op_total++;
}