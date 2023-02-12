/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:10:13 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 17:13:53 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_2(Pile **stack, char c)
{
	Pile	*after;
	Pile	*head;

	head = *stack;
	after = head->next;
	if (head->index > after->index)
		swap_stack(*stack, c);
}

void	sort_3(Pile **stack, char c)
{
	Pile	*after;
	Pile	*head;

	sort_2(stack, 'a');
	while (is_sort(*stack))
	{
		head = *stack;
		after = head->next;
		if (head->index > after->index)
			swap_stack(*stack, c);
		else
			reverse_rotate_stack(stack, c);
	}
}

void	sort_4(Pile **stack_a, Pile **stack_b, int x)
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

void	sort_5(Pile **stack_a, Pile **stack_b)
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

void	sort_small(Pile **stack_a, Pile **stack_b)
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
