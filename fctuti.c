/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctuti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:50 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 19:28:26 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

Pile	*ft_lstnew(int x, int index)
{
	Pile	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (0);
	element->valeur = x;
	element->index = index;
	element->next = 0;
	return (element);
}

size_t	ft_lstsize(Pile *lst)
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

Pile	*ft_lstlast(Pile *lst)
{
	Pile	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	free_list(Pile **lst)
{
	Pile	*save;

	if (!*lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		*lst = save;
	}
}
