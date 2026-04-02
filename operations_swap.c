/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:57:09 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 14:08:26 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}
void	sa(t_info *info)
{
	swap(&info->stack_a);
	write(1, "sa\n", 3);
	info->bench.op_sa++;
	info->bench.op_total++;
}

void	sb(t_info *info)
{
	swap(&info->stack_b);
	write(1, "sb\n", 3);
	info->bench.op_sb++;
	info->bench.op_total++;
}

void	ss(t_info *info)
{
	swap(&info->stack_a);
	swap(&info->stack_b);
	write(1, "ss\n", 3);
	info->bench.op_ss++;
	info->bench.op_total++;
}
