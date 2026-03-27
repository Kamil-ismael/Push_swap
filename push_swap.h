/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toavandr <toavandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:48:22 by toavandr          #+#    #+#             */
/*   Updated: 2026/03/26 22:18:08 by toavandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

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

void    pb(t_info *a, t_info *b);
void    pa(t_info *a, t_info *b);
void    ra(t_info *a);
void    rra(t_info *a);
void    medium_sort(t_info *a, t_info *b);
void    adaptive_sort(t_info *a, t_info *b);

#endif