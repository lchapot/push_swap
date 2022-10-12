/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:07:10 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/11 13:48:39 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H

# define PS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct pile
{
	int		valeur;
	struct pile *next;
}			Pile;

int		ft_atoi(char *str);
void	ft_sa(Pile **pileA, Pile **pileB);
void	ft_sb(Pile **pileA, Pile **pileB);
	ft_ss(Pile **pileA, Pile **pileB);
ft_pa();
ft_pb();
ft_ra();
ft_rb();
ft_rr();
ft_rra();
ft_rrb();
ft_rrr();

#endif