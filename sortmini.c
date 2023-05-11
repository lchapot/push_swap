/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:13 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/20 17:59:54 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_2(t_pile **stack, char c)
{
	t_pile	*after;
	t_pile	*head;

	head = *stack;
	after = head->next;
	if (head->index > after->index)
		swap_stack(*stack, c);
}

void	sort_3(t_pile **stack, char c)
{
	t_pile	*after;
	t_pile	*head;

	while (notsort(*stack))
	{
		head = *stack;
		after = head->next;
		if (head->index > after->index)
			swap_stack(*stack, c);
		else
			reverse_rotate_stack(stack, c);
	}
}

void	sort_4(t_pile **stack_a, t_pile **stack_b, int x)
{
	if (find_index(*stack_a, x) < 2)
	{
		while ((*stack_a)->index != x)
			rotate_stack(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != x)
			reverse_rotate_stack(stack_a, 'a');
	}
	push_stack(stack_b, stack_a, 'b');
	sort_3(stack_a, 'a');
	push_stack(stack_a, stack_b, 'a');
}

void	sort_5(t_pile **stack_a, t_pile **stack_b)
{
	if (find_index(*stack_a, 0) < 3)
	{
		while ((*stack_a)->index != 0)
			rotate_stack(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			reverse_rotate_stack(stack_a, 'a');
	}
	push_stack(stack_b, stack_a, 'b');
	sort_4(stack_a, stack_b, 1);
	push_stack(stack_a, stack_b, 'a');
}

void	sortmini(t_pile **stack_a, t_pile **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_2(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b, 0);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}
