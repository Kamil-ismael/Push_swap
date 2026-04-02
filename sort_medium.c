/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:00:00 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 14:00:00 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes_med(t_info *info)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = info->stack_a;
	while (i)
	{
		rank = 0;
		j = info->stack_a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

static int	chunk_size(int size)
{
	if (size <= 20)
		return (4);
	if (size <= 50)
		return (7);
	if (size <= 100)
		return (11);
	return (17);
}

static int	find_best_pos_in_a(t_info *info, int target)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_diff;
	int		diff;

	cur = info->stack_a;
	pos = 0;
	best_pos = -1;
	best_diff = info->size_a + 1;
	while (cur)
	{
		if (cur->index == target)
		{
			diff = pos;
			if (pos > info->size_a / 2)
				diff = info->size_a - pos;
			if (diff < best_diff)
			{
				best_diff = diff;
				best_pos = pos;
			}
		}
		pos++;
		cur = cur->next;
	}
	return (best_pos);
}

static void	push_chunk_to_b(t_info *info, int min_idx, int max_idx)
{
	int		pushed;
	int		total;
	int		i;
	int		pos;

	total = max_idx - min_idx + 1;
	pushed = 0;
	while (pushed < total)
	{
		i = min_idx + pushed;
		pos = find_best_pos_in_a(info, i);
		if (pos == -1)
		{
			pushed++;
			continue ;
		}
		if (pos <= info->size_a / 2)
			while (pos-- > 0)
				ra(info);
		else
		{
			pos = info->size_a - pos;
			while (pos-- > 0)
				rra(info);
		}
		pb(info);
		pushed++;
	}
}

static int	find_max_index_in_b(t_info *info)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		max_pos;

	cur = info->stack_b;
	max = cur->index;
	pos = 0;
	max_pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

static void	push_sorted_to_a(t_info *info)
{
	int	pos;
	int	size;

	while (info->stack_b)
	{
		pos = find_max_index_in_b(info);
		size = info->size_b;
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(info);
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				rrb(info);
		}
		pa(info);
	}
}

void	sort_medium(t_info *info)
{
	int	csize;
	int	pushed;
	int	min_idx;
	int	max_idx;

	assign_indexes_med(info);
	csize = chunk_size(info->size_a);
	pushed = 0;
	while (info->stack_a)
	{
		min_idx = pushed;
		max_idx = pushed + csize - 1;
		if (max_idx >= info->size_a + pushed)
			max_idx = info->size_a + pushed - 1;
		push_chunk_to_b(info, min_idx, max_idx);
		pushed += csize;
	}
	push_sorted_to_a(info);
}
