/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:02:56 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 19:34:46 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	insert_last(Pile**lst, int val, int index)
{
	Pile	*node;
	Pile	*last;

	node = ft_lstnew(val, index);
	last = ft_lstlast(*lst);
	last->next = node;
	node->next = NULL;
}

void	delete_node(Pile**lst, int val)
{
	Pile	*prev;
	Pile	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	prev = (*lst);
	if (prev->valeur == val)
	{
		*lst = (*lst)->next;
		free(prev);
		return ;
	}
	while (tmp->valeur != val && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->valeur == val)
	{
		prev->next = tmp->next;
		free(tmp);
	}
}

Pile	*find_prev_elem(Pile*lst, int val)
{
	Pile	*search;
	Pile	*before;

	if (!lst)
		return (NULL);
	before = lst;
	search = lst->next;
	while (before->valeur != val && search->valeur != val && search)
	{
		before = search;
		search = search->next;
	}
	if (search->valeur == val || before->valeur == val)
		return (before);
	return (NULL);
}

Pile	*init_list(int ac, char **av)
{
	Pile	*stack;
	int		i;

	stack = ft_lstnew(ft_atoi(av[1]), 0);
	i = 2;
	while (i < ac)
	{
		insert_last(&stack, ft_atoi(av[i]), 0);
		i++;
	}
	indexing(stack);
	return (stack);
}
