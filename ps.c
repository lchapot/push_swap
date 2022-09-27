/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:51 by lchapot           #+#    #+#             */
/*   Updated: 2022/09/27 18:20:43 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	**ft_ajoutpile(Pile **p_pile, int X, Pile *pnew)
{
	if (pnew != NULL)
	{
		pnew->valeur = X;
		pnew->previous = *p_pile;
		*p_pile = pnew;
	}
	return (pnew);
}

void	ft_pileclear(Pile **p_pile)
{
	while (*p_pile != NULL)
		pile_rmv(p_pile);
	free(p_pile), p_pile = NULL;
}

char	*ft_creapile(char **argc, int argv)
{
	Pile *pnew = malloc(sizeof *pnew);
	while (argc[argv])
	{
		pnew = ft_ajoutpile(pnew, argc[argv], pnew);
		argv--;
	}
	return(pnew);
}

int	ft_doublon(char **argc, int tmp, int start)
{
	while (argc[start])
	{
		if (argc[start] == tmp)
			return (1);
		start++;
	}
	return (0);
}

int	main(int argv, char **argc)
{
	int	tmp;
	int	i;
	Pile **pileA;
	Pile **pileB;
	
	tmp = 0;
	i = 0;
	while (argc[i])
	{
		tmp = argc[i];
		if((int)argc[i]%1 != 0 || ft_doublon(**argc, tmp, i+1) == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	pileA = ft_creapile(argc, argv);
	pileB = ft_creapile(NULL, 0);
	ft_algo(pileA, pileB);
	ft_pileclear(pileA);
	ft_pileclear(pileB);	
	return (0);
}




/*
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

int	pile_peek(Pile *p_pile)
{
	int ret = -1;
	
	if (p_pile != NULL)
	{
		ret = p_pile->valeur;
	}
	return ret;
}
valeur au sommet:::;;;;
*/