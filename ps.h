/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:07:10 by lchapot           #+#    #+#             */
/*   Updated: 2022/09/26 18:25:26 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H

# define PS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct pile
{
	int	valeur;
	struct pile *previous;
	struct pile *next;
}	Pile;

ft_sa();
ft_sb();
ft_ss();
ft_pa();
ft_pb();
ft_ra();
ft_rb();
ft_rr();
ft_rra();
ft_rrb();
ft_rrr();

#endif