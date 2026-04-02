/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:16:22 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 13:34:13 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_name(int strategy)
{
	if (strategy == 1)
		return ("Simple O(n^2)");
	if (strategy == 2)
		return ("Medium O(n*sqrt(n))");
	if (strategy == 3)
		return ("Complex O(n log n)");
	return ("Adaptive");
}

static void	print_disorder(double disorder)
{
	int	percent;
	int	decimal;

	percent = (int)(disorder * 10000);
	decimal = percent % 100;
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_op(char *label, int count, char *sep)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(sep, 2);
}

static void	print_op_counts(t_info *info)
{
	t_bench	*b;

	b = &info->bench;
	print_op("sa: ", b->op_sa, " | ");
	print_op("sb: ", b->op_sb, " | ");
	print_op("ss: ", b->op_ss, "\n");
	print_op("pa: ", b->op_pa, " | ");
	print_op("pb: ", b->op_pb, "\n");
	print_op("ra: ", b->op_ra, " | ");
	print_op("rb: ", b->op_rb, " | ");
	print_op("rr: ", b->op_rr, "\n");
	print_op("rra: ", b->op_rra, " | ");
	print_op("rrb: ", b->op_rrb, " | ");
	print_op("rrr: ", b->op_rrr, "\n");
}

void	print_bench(t_info *info, int strategy)
{
	print_disorder(info->disorder);
	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd(get_strategy_name(strategy), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(info->bench.op_total, 2);
	ft_putchar_fd('\n', 2);
	print_op_counts(info);
}
