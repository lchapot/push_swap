/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/11 13:48:00 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_sa(Pile **pileA, Pile **pileB)
{
	if (!pileA || !pileB)
		return (0);
	write(1, "sa\n", 3);
}

void	ft_sb(Pile **pileA, Pile **pileB)
{
	if (!pileA || !pileB)
		return (0);
	else
	
	write(1, "sb\n", 3);
}

	ft_ss(Pile **pileA, Pile **pileB)
{
	ft_sb(pileA, pileB);
	ft_sa(pileA, pileB);
	write(1, "ss\n", 3);
}	

	ft_pa(Pile **pileA, Pile **pileB)
{
	if (!pileB)
		return (0);
	write(1, "pa\n", 3);	
}

	ft_pb(Pile **pileA, Pile **pileB)
{
	if (!pileA)
		return (0);
	write(1, "pb\n", 3);
}

	ft_ra(Pile **pileA, Pile **pileB)
{
	//dernier eleemt doit pointer sur le premier et le premier pointer sur rien//
	write(1, "ra\n", 3);
}

	ft_rb(Pile **pileA, Pile **pileB)
{
	write(1, "rb\n", 3);
}

	ft_rr(Pile **pileA, Pile **pileB)
{
	ft_rb(pileA, pileB);
	ft_ra(pileA, pileB);
	write(1, "rr\n", 3);
}

	ft_rra(Pile **pileA, Pile **pileB)
{
	write(1, "rra\n", 3);
	
}

	ft_rrb(Pile **pileA, Pile **pileB)
{
	write(1, "rrb\n", 3);
	
}

	ft_rrr(Pile **pileA, Pile **pileB)
{
	ft_rra(pileA, pileB);
	ft_rrb(pileA, pileB);
	write(1, "rrr\n", 3);
}
