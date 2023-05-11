/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctuti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:50 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/15 16:37:27 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_pile	*ft_lstnew(int x, int i)
{
	t_pile	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (0);
	element->valeur = x;
	element->index = i;
	element->next = 0;
	return (element);
}

size_t	ft_lstsize(t_pile *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_pile	*ft_lstlast(t_pile *lst)
{
	t_pile	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	free_list(t_pile **lst)
{
	t_pile	*save;

	if (!*lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		*lst = save;
	}
}
