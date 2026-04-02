/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:17:31 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 11:17:47 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes(t_info *info)
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

static int	get_max_bits(t_info *info)
{
	int		max;
	int		bits;
	t_node	*cur;

	max = 0;
	cur = info->stack_a;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	sort_complex(t_info *info)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	assign_indexes(info);
	max_bits = get_max_bits(info);
	bit = 0;
	while (bit < max_bits)
	{
		size = info->size_a;
		i = 0;
		while (i < size)
		{
			if ((info->stack_a->index >> bit) & 1)
				ra(info);
			else
				pb(info);
			i++;
		}
		while (info->stack_b)
			pa(info);
		bit++;
	}
}
