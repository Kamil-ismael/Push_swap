/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:58:43 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 14:20:46 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_ps(int value)
{
	t_node	*new;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_node	*ft_lstlast_ps(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	new_node->prev = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = ft_lstlast_ps(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
