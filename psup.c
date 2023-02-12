/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 19:35:54 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ss(Pile *stack_a, Pile *stack_b)
{
	if (swap_stack(stack_a, 's') == -1 || swap_stack(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rrr(Pile **stack_a, Pile **stack_b)
{
	if (reverse_rotate_stack(stack_a, 's') == -1
		|| reverse_rotate_stack(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	rr(Pile **stack_a, Pile **stack_b)
{
	if ((rotate_stack(stack_a, 's') == -1)
		|| (rotate_stack(stack_b, 's') == -1))
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	swap_stack(Pile *stack, char c)
{
	int		tmp_valeur;
	int		tmp_index;
	Pile	*tmp_next;

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

int	rotate_stack(Pile **stack, char c)
{
	int		tmp;
	int		tmp_index;
	Pile	*prev;

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

int	reverse_rotate_stack(Pile **stack, char c)
{
	Pile	*last_node;
	Pile	*before_last_node;

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

int	push_stack(Pile **stack1, Pile **stack2, char c)
{
	Pile	*new;

	if (ft_lstsize(*stack2) == 0)
		return (-1);
	new = ft_lstnew((*stack2)->valeur, (*stack2)->index);
	new->next = *stack1;
	*stack1 = new;
	delete_node(stack2, (*stack2)->valeur);
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
	return (1);
}
