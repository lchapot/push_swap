/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:31:57 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 16:22:40 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	is_sort(Pile	*lst)
{
	Pile	*after;

	after = lst->next;
	while (after && lst->valeur < after->valeur)
	{
		lst = after;
		after = after->next;
	}
	if (!after)
		return (0);
	return (1);
}

int	find_duplicate(Pile *stack)
{
	Pile	*save;

	if (!stack)
		return (0);
	while (stack)
	{
		save = stack->next;
		while (save)
		{
			if (stack->valeur == save->valeur)
				return (0);
			save = save->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	is_arg_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	if (!is_int(str))
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) >= -2147483648 && ft_atoi(str[i]) <= 2147483647
			&& str[i][0] != '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	sign;
	long	res;
	long	i;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
