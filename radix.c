/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:03:19 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/06 19:13:22 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	radix()
{
	int	i;

	i = 0;
	
	return (0);
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
int decimaltobinaire(int nb)
{
	int tab[31];
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