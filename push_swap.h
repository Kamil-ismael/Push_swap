/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:38:51 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/03/31 12:29:47 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_info
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     size_a;
    int     size_b;
    int     op_total;
    int     op_sa;
    double  disorder;
}   t_info;

int		is_valid_number(char *str);
long	ft_atol(const char *str);
int		has_duplicate(t_node *stack, int value);
void	parse_args(t_info *info, int argc, char **argv);
void	add_back(t_node **stack, int value);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	error_exit(void);

t_node	*ft_lstnew_ps(int value);
t_node	*ft_lstlast_ps(t_node *lst);
void	ft_lstadd_back_ps(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);

void init_info(t_info *info);
int is_sorted(t_node *stack);
void free_all(t_info *info);
void sort(t_info *info);

#endif
