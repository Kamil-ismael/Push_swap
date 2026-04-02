/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 08:39:17 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/01 12:50:23 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info(t_info *info)
{
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->size_a = 0;
	info->size_b = 0;
	info->disorder = 0.0;
	info->bench_mode = 0;
	info->bench.op_sa = 0;
	info->bench.op_sb = 0;
	info->bench.op_ss = 0;
	info->bench.op_pa = 0;
	info->bench.op_pb = 0;
	info->bench.op_ra = 0;
	info->bench.op_rb = 0;
	info->bench.op_rr = 0;
	info->bench.op_rra = 0;
	info->bench.op_rrb = 0;
	info->bench.op_rrr = 0;
	info->bench.op_total = 0;
}

static int	is_sorted(t_info *info)
{
	t_node	*cur;

	cur = info->stack_a;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static int	parse_strategy(char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (1);
	if (ft_strcmp(flag, "--medium") == 0)
		return (2);
	if (ft_strcmp(flag, "--complex") == 0)
		return (3);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (4);
	return (0);
}

static int	is_flag(char *str)
{
	return (ft_strcmp(str, "--simple") == 0
		|| ft_strcmp(str, "--medium") == 0
		|| ft_strcmp(str, "--complex") == 0
		|| ft_strcmp(str, "--adaptive") == 0
		|| ft_strcmp(str, "--bench") == 0);
}

static void	run_strategy(t_info *info, int strategy)
{
	info->disorder = compute_disorder(info);
	if (strategy == 1)
		sort_simple(info);
	else if (strategy == 2)
		sort_medium(info);
	else if (strategy == 3)
		sort_complex(info);
	else
		sort_adaptive(info);
}

static int	parse_flags(t_info *info, int argc, char **argv, int *strategy)
{
	int	i;

	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			info->bench_mode = 1;
		else
			*strategy = parse_strategy(argv[i]);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		strategy;
	int		args_start;

	if (argc < 2)
		return (0);
	init_info(&info);
	strategy = 4;
	args_start = parse_flags(&info, argc, argv, &strategy);
	if (args_start >= argc)
		return (0);
	parse_args(&info, argc - args_start, argv + args_start);
	if (is_sorted(&info))
		return (0);
	run_strategy(&info, strategy);
	if (info.bench_mode)
		print_bench(&info, strategy);
	return (0);
}
