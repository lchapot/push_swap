/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2022/11/21 18:43:40 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_sa(Pile **pileA)
{
	Pile	*tmp;
	Pile	*tmp2;
	
	tmp = *pileA;
	tmp2= pileA->next;
	tmp->next = tmp2->next;
	tmp2->next = *pileA;
	*pileA = tmp2;	
	write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(Pile **pileB)
{
	Pile	*tmp;
	Pile	*tmp2;
	
	tmp = *pileB;
	tmp2= pileB->next;
	tmp->next = tmp2->next;
	tmp2->next = *pileB;
	*pileB = tmp2;	
	write(1, "sb\n", 3);
	return (0);
}

	ft_ss(Pile **pileA, Pile **pileB)
{
	//if sb printsb if sa printsa if ss printss//
	ft_sb(pileB);
	ft_sa(pileA);
	write(1, "ss\n", 3);
}	

// 	ft_pa(Pile **pileA, Pile **pileB)
// {
// 	if (!pileB)
// 		return (0);
// 	write(1, "pa\n", 3);	
// }

// 	ft_pb(Pile **pileA, Pile **pileB)
// {
// 	if (!pileA)
// 		return (0);
// 	write(1, "pb\n", 3);
// }

int	ft_ra(Pile **pileA)
{
	Pile *tmp;
	Pile *tmp2;
	
	tmp = *pileA;
	tmp->next= NULL;
	while (tmp->next)
		tmp = tmp->next;
	write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(Pile **pileB)
{
	int	i;

	i = 0;
	write(1, "rb\n", 3);
	return (0);
}

	ft_rr(Pile **pileA, Pile **pileB)
{
	ft_rb(pileB);
	ft_ra(pileA);
	write(1, "rr\n", 3);
}

int	ft_rra(Pile **pileA)
{
	Pile *tmp;
	Pile *tmp2;

	tmp = *pileA;
	while(tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pileA;
	*pileA = tmp2;
	write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(Pile **pileB)
{
	Pile *tmp;
	Pile *tmp2;
	
	tmp = *pileB;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pileB;
	*pile B = tmp2->next;
	write(1, 'rrb\n', 4);
	return (0);
}

	ft_rrr(Pile **pileA, Pile **pileB)
{
	ft_rra(pileA);
	ft_rrb(pileB);
	write(1, "rrr\n", 4);
}