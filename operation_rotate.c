/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:28:39 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 10:33:51 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = ft_lstlast_ps(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

static void	rrotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast_ps(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	ra(t_info *info)
{
	rotate(&info->stack_a);
	write(1, "ra\n", 3);
	info->bench.op_ra++;
	info->bench.op_total++;
}

void	rb(t_info *info)
{
	rotate(&info->stack_b);
	write(1, "rb\n", 3);
	info->bench.op_rb++;
	info->bench.op_total++;
}

void	rr(t_info *info)
{
	rotate(&info->stack_a);
	rotate(&info->stack_b);
	write(1, "rr\n", 3);
	info->bench.op_rr++;
	info->bench.op_total++;
}

void	rra(t_info *info)
{
	rrotate(&info->stack_a);
	write(1, "rra\n", 4);
	info->bench.op_rra++;
	info->bench.op_total++;
}

void	rrb(t_info *info)
{
	rrotate(&info->stack_b);
	write(1, "rrb\n", 4);
	info->bench.op_rrb++;
	info->bench.op_total++;
}

void	rrr(t_info *info)
{
	rrotate(&info->stack_a);
	rrotate(&info->stack_b);
	write(1, "rrr\n", 4);
	info->bench.op_rrr++;
	info->bench.op_total++;
}