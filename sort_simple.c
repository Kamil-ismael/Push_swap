/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:48:07 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 10:49:43 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_info *info)
{
	t_node	*cur;
	int		min_val;
	int		pos;
	int		min_pos;

	cur = info->stack_a;
	min_val = cur->value;
	pos = 0;
	min_pos = 0;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

static void	bring_to_top(t_info *info, int pos)
{
	int	size;

	size = info->size_a;
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(info);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(info);
	}
}

void	sort_simple(t_info *info)
{
	int	pos;

	while (info->stack_a)
	{
		pos = find_min_pos(info);
		bring_to_top(info, pos);
		pb(info);
	}
	while (info->stack_b)
		pa(info);
}