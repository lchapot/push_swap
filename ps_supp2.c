/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_supp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:31:57 by lchapot           #+#    #+#             */
/*   Updated: 2022/10/11 15:32:43 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_atoi(char *str)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res < -32767 || res > 32767)
		return (33000);
	return (res);
}