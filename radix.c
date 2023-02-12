/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:03:19 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 17:18:05 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	indexing(Pile *list)
{
	Pile	*travel;
	Pile	*head;

	head = list;
	while (list)
	{
		travel = head;
		list->index = 0;
		while (travel)
		{
			if (list->valeur > travel->valeur)
				list->index += 1;
			travel = travel->next;
		}
		list = list->next;
	}
}

int	find_index(Pile *stack, int x)
{
	int		i;
	Pile	*travel;

	i = 0;
	travel = stack;
	while (travel && travel->index != x)
	{
		i++;
		travel = travel->next;
	}
	return (i);
}

int	get_max_bits(Pile **stack)
{
	Pile	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(Pile **pileA, Pile **pileB)
{
	Pile	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *pileA;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(pileA);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *pileA;
			if (!((head_a->index >> i) & 1))
				push_stack(pileB, pileA, 'b');
			else
				rotate_stack(pileA, 'a');
		}
		while (ft_lstsize(*pileB) != 0)
			push_stack(pileA, pileB, 'a');
		i++;
	}
}
