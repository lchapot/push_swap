/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:31:57 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/17 18:46:28 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
		if (str[i][0] == '-')
			j++;
		while (str[i][j])
		{
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
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
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

int	duplicate(t_pile *stack)
{
	t_pile	*save;

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

int	notsort(t_pile	*lst)
{
	t_pile	*save;

	save = lst->next;
	while (save && lst->valeur < save->valeur)
	{
		lst = save;
		save = save->next;
	}
	if (!save)
		return (0);
	return (1);
}
