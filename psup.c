/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/21 15:40:43 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	push_stack(t_pile **stack_a, t_pile **stack_b, char c)
{
	t_pile	*new;

	if (ft_lstsize(*stack_b) == 0)
		return (-1);
	new = ft_lstnew((*stack_b)->valeur, (*stack_b)->index);
	new->next = *stack_a;
	*stack_a = new;
	delete_node(stack_b, (*stack_b)->valeur);
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
	return (1);
}

int	rotate_stack(t_pile **stack, char c)
{
	int		tmp;
	int		tmp_index;
	t_pile	*prev;

	if (ft_lstsize(*stack) <= 1)
		return (-1);
	tmp = (*stack)->valeur;
	tmp_index = (*stack)->index;
	prev = (*stack);
	(*stack) = (*stack)->next;
	free(prev);
	insert_last(stack, tmp, tmp_index);
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
	return (1);
}

int	swap_stack(t_pile *stack, char c)
{
	int		tmp_valeur;
	int		tmp_index;
	t_pile	*tmp_next;

	if (ft_lstsize(stack) <= 1)
		return (-1);
	tmp_valeur = stack->valeur;
	tmp_index = stack->index;
	tmp_next = stack->next;
	stack->valeur = tmp_next->valeur;
	stack->index = tmp_next->index;
	stack = stack->next;
	stack->valeur = tmp_valeur;
	stack->index = tmp_index;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
	return (1);
}

int	reverse_rotate_stack(t_pile **stack, char c)
{
	t_pile	*last_node;
	t_pile	*before_last_node;

	if (ft_lstsize(*stack) <= 1)
		return (-1);
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	before_last_node = find_prev_elem(*stack, last_node->valeur);
	before_last_node->next = NULL;
	*stack = last_node;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	return (1);
}
