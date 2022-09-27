/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:51 by lchapot           #+#    #+#             */
/*   Updated: 2022/09/27 14:43:06 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_creapile(Pile **p_pile, int X)
{
	Pile *pnew = malloc(sizeof *pnew);
	if (pnew != NULL)
	{
		pnew->valeur = X;
		pnew->previous = *p_pile;
		*p_pile = pnew;
	}
}
// ajout dun elmt pnew en haut de la pile p_pile

int	pile_rmv(Pile **p_pile)
{
	int ret;
	ret = -1;
if (*p_pile != NULL)
{
	Pile *tmp = (*p_pile)->previous; //avant dernier elmt stocke ici
	ret = (*p_pile)->valeur;
	free(*p_pile), *p_pile = NULL;
	*p_pile = tmp;
}
return (ret);
}
//retrait du dernier elmt de p_pile

void	pileclear(Pile **p_pile)
{
	while (*p_pile != NULL)
		pile_rmv(p_pile);
}
//vide tte la pile

int	pile_peek(Pile *p_pile)
{
	int ret = -1;
	
	if (p_pile != NULL)
	{
		ret = p_pile->valeur;
	}
	return ret;
}

//donne la valeur du sommet, -1 si c vide;