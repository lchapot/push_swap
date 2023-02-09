/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:03:19 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/09 18:22:57 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	radix()
{
	int	i;

	i = 0;
	
	return (0);
}

long	ft_atoi(char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

void	indexation(int av, int ac)
{
	int	i;

	i = 0;
	while(i<ac)
	{
		compare and give a nbr between 0 and ac;
		i++;
	}
	nouvelle liste simplifiee -> go binaire;
}

int decimaltobinaire(int nb, t_list **pileA)
{
	int tab[get_max_bits(pileA)];
	int	i;
	int res;
	
	res = 0;
	i = 0;
	while (nb > 0)
	{
		tab[i] = nb%2;
		nb = nb/2;
		i++;
	}
	while (i-- > 0)
		res = res*10 + tab[i];
	return (res);	
}

res ->> stack A;

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

 void    radix_sort(Pile **pileA, Pile **pileB)
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

/* atoi;
on les transforme en 0 1 2 3 4 5 n (n = nbr de chiffres donnes), donc indexer puis remplacer;
passer en base 2;
trouver le plus grand nbr pour voir cb de fois on fait le tchik tchak
selon le nbr de digit = i;
put it in stack A;


faire les tchik tchak de 0 a i***; go B quand c 0 stay A qd c 1)
print les actions

*** >> and &;

*/