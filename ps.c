/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:51 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/30 19:01:31 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_alreadysorted(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] > str[i+1])
			return (0);
		i++;
	}
	return (1);
}

// char	**ft_ajoutpile(Pile **p_pile, int X, Pile *pnew)
// {
// 	if (pnew != NULL)
// 	{
// 		pnew->valeur = X;
// 		// pnew->previous = *p_pile;
// 		*p_pile = pnew;
// 	} 
// 	return (pnew);
// }

void	ft_pileclear(Pile **p_pile)
{
	while (*p_pile != NULL)
		pile_rmv(p_pile);
	free(p_pile), p_pile = NULL;
}

char	*ft_creapile(int argv, char **av)
{
	Pile *pnew = malloc(sizeof *pnew);
	while (av[argv])
	{
		pnew = ft_ajoutpile(pnew, av[argv], pnew);
		argv--;
	}
	return(pnew);
}

int	ft_doublon(char **av, int tmp, int start)
{
	while (av[start])
	{
		if (av[start] == tmp)
			return (1);
		start++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	tmp;
	int	i;
	Pile **pileA;
	Pile **pileB;
	char *str;

	tmp = 0;
	i = 0;
	str = malloc(sizeof(int) * ac+ 1);
	pileA = malloc(sizeof(Pile));
	pileB = malloc(sizeof(Pile));
	if(!pileA || !pileB)
		return (0);
	while (av[i])
	{
		tmp = av[i];
		if(ft_doublon(**av, tmp, i+1) == 1)
		{
			write(2, "Error\n", 6);
			ft_pileclear(pileA);
			ft_pileclear(pileB);
			return (0);
		}
		if (ft_atoi(str[i]) >= -2147483648 && ft_atoi(str[i]) <= 2147483647)
			i++;
		else
			return (0);
		i++;
	}
	str[i+1] = '\0';
	if (ft_alreadysorted(str) == 0)
	{
		printf("\n%s\n", "@@@@@ already sorted @@@@@");
		return (0);
	}
	pileA = ft_creapile(ac, str);
	*pileB = NULL;
	ft_algo(pileA, pileB);
	ft_pileclear(pileA);
	ft_pileclear(pileB);	
	return (0);
}

/*
Step 1 : Parsing, put numbers in the stack A if no errors are detected

Step 2 : Check if the numbers in A are all sorted. If so, end the program without printing anything. It’d be preferable to write a function A_is_sorted()

Step 3 : If the size of A ≤ 5, call function sort_small_stack(). Else, call function sort_big_stack()


4 5 9 7
->
4
5
9
7
pb pb sa pa pa ->
4
5
7
9
*/