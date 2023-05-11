/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:02:56 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/17 18:33:44 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	insert_last(t_pile**lst, int val, int index)
{
	t_pile	*node;
	t_pile	*last;

	node = ft_lstnew(val, index);
	last = ft_lstlast(*lst);
	last->next = node;
	node->next = NULL;
}

void	delete_node(t_pile**lst, int val)
{
	t_pile	*prev;
	t_pile	*tmp;

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

t_pile	*find_prev_elem(t_pile*lst, int val)
{
	t_pile	*search;
	t_pile	*before;

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

t_pile	*init_list(int ac, char **av)
{
	t_pile	*stack;
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
