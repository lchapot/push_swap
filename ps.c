/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:07 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/16 14:45:33 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	parse(int ac, char **av)
{
	t_pile	*stack;

	if (!is_arg_valid(av))
		return (write(2, "Error\n", 6), 0);
	if (ac <= 2)
		return (0);
	stack = init_list(ac, av);
	if (!duplicate(stack))
		return (free_list(&stack), write(2, "Error\n", 6), 0);
	if (!notsort(stack))
		return (free_list(&stack), 0);
	return (free_list(&stack), 1);
}

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
	{
		write(1, str, fd);
		str++;
	}
	write(1, "\n", fd);
}

int	main(int ac, char **av)
{
	t_pile	**stack_a;
	t_pile	**stack_b;

	if (!parse(ac, av))
		return (0);
	stack_a = malloc(sizeof(t_pile));
	stack_b = malloc(sizeof(t_pile));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = init_list(ac, av);
	*stack_b = NULL;
	if (ft_lstsize(*stack_a) <= 5)
		sortmini(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
