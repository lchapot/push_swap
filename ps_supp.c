/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_supp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:07:02 by lchapot           #+#    #+#             */
/*   Updated: 2022/09/27 18:23:37 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ps.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		len = 6;
		return (len);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}

void	ft_sa(Pile **pileA, Pile **pileB)
{
	write(1, "sa\n", 3);
		
}

void	ft_sb(Pile **pileA, Pile **pileB)
{
	write(1, "sb\n", 3);
}

	ft_ss(Pile **pileA, Pile **pileB)
{
	write(1, "ss\n", 3);
	
}	

	ft_pa(Pile **pileA, Pile **pileB)
{
	write(1, "pa\n", 3);
	
}

	ft_pb(Pile **pileA, Pile **pileB)
{
	write(1, "pb\n", 3);
	
}

	ft_ra(Pile **pileA, Pile **pileB)
{
	write(1, "ra\n", 3);
	
}

	ft_rb(Pile **pileA, Pile **pileB)
{
	write(1, "rb\n", 3);
	
}
	ft_rr(Pile **pileA, Pile **pileB)
{
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
	write(1, "rrr\n", 3);
	
}
