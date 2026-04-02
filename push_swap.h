/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:38:51 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 14:12:47 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"  

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_bench
{
	int		op_sa;
	int		op_sb;
	int		op_ss;
	int		op_pa;
	int		op_pb;
	int		op_ra;
	int		op_rb;
	int		op_rr;
	int		op_rra;
	int		op_rrb;
	int		op_rrr;
	int		op_total;
}	t_bench;

typedef struct s_info
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	double	disorder;
	int		bench_mode;
	t_bench	bench;
}	t_info;

int		is_valid_number(char *str);
int		has_duplicate(t_node *stack, int value);
long	ft_atol(const char *str);
void	error_exit(void);
void	parse_args(t_info *info, int argc, char **argv);
t_node	*ft_lstnew_ps(int value);
t_node	*ft_lstlast_ps(t_node *lst);
void	ft_lstadd_back_ps(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);
int		ft_strcmp(const char *s1, const char *s2);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
double	compute_disorder(t_info *info);
void	sort_simple(t_info *info);
void	sort_medium(t_info *info);
void	sort_complex(t_info *info);
void	sort_adaptive(t_info *info);
void	print_bench(t_info *info, int strategy);

#endif
