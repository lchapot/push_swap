/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:07:10 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/30 19:07:41 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H

# define PS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct pile
{
	int		valeur;
	int		index;
	struct pile *next;
}			Pile;

long	ft_atoi(char *str);
// void	ft_sa(Pile **pileA);
// void	ft_sb(Pile **pileB);
// 	ft_ss(Pile **pileA, Pile **pileB);
// ft_pa();
// ft_pb();
// ft_ra();
// ft_rb();
// ft_rr();
// ft_rra();
// ft_rrb();
// ft_rrr();
#endif