/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:03:19 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/17 17:22:37 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	indexing(t_pile *lst)
{
	t_pile	*travel;
	t_pile	*stay;

	stay = lst;
	while (lst)
	{
		travel = stay;
		lst->index = 0;
		while (travel)
		{
			if (lst->valeur > travel->valeur)
				lst->index += 1;
			travel = travel->next;
		}
		lst = lst->next;
	}
}

int	find_index(t_pile *stack, int x)
{
	int		i;
	t_pile	*travel;

	i = 0;
	travel = stack;
	while (travel && travel->index != x)
	{
		i++;
		travel = travel->next;
	}
	return (i);
}

int	get_max_bits(t_pile **stack)
{
	t_pile	*head;
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

void	radix_sort(t_pile **pileA, t_pile **pileB)
{
	t_pile	*stay_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	stay_a = *pileA;
	size = ft_lstsize(stay_a);
	max_bits = get_max_bits(pileA);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			stay_a = *pileA;
			if (!((stay_a->index >> i) & 1))
				push_stack(pileB, pileA, 'b');
			else
				rotate_stack(pileA, 'a');
		}
		while (ft_lstsize(*pileB) != 0)
			push_stack(pileA, pileB, 'a');
		i++;
	}
}
