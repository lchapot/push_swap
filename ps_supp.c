/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/30 19:07:46 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_sa(Pile **pileA)
{
	// if (!pileA)
	// 	return (0);
	int	*tmp;
	int	*tmp2;
	
	tmp = *pileA;
	tmp2= *pileA->next;
	tmp->next = tmp2->next;
	tmp2->next = *pileA;
	*pileA = tmp2;	
	//si ca vient de ft_ss pas print//
	write(1, "sa\n", 3);
}

void	ft_sb(Pile **pileB)
{
	int	*tmp;
	int	*tmp2;
	
	tmp = *pileB;
	tmp2= *pileB->next;
	tmp->next = tmp2->next;
	tmp2->next = *pileB;
	*pileB = tmp2;	
	//si ca vient de ft_ss pas print//
	write(1, "sb\n", 3);
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

	ft_ra(Pile **pileA)
{
	int *tmp;
	int *tmp2;
	while (pileA->next)
		tmp = pileA->next;
	write(1, "ra\n", 3);
}

	ft_rb(Pile **pileB)
{
	write(1, "rb\n", 3);
}

	ft_rr(Pile **pileA, Pile **pileB)
{
	ft_rb(pileB);
	ft_ra(pileA);
	write(1, "rr\n", 3);
}

	ft_rra(Pile **pileA)
{
	tmp;
	tmp2;

	while(tmp->next->next)
		tmp = tmp->next;
	tmp->next = *pileA;
	*pileA = tmp2;
	write(1, "rra\n", 3);
}

	ft_rrb(Pile **pileB)
{
	write(1, "rrb\n", 3);
	
}

	ft_rrr(Pile **pileA, Pile **pileB)
{
	ft_rra(pileA);
	ft_rrb(pileB);
	write(1, "rrr\n", 3);
}