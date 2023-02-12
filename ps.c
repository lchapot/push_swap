/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:51 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 19:33:20 by lchapot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	parse(int ac, char **av)
{
	Pile	*stack;

	if (!is_arg_valid(av))
		return (write(2, "Error\n", 6), 0);
	if (ac <= 2)
		return (0);
	stack = iniPile(ac, av);
	if (!find_duplicate(stack))
		return (free_list(&stack), write(2, "Error\n", 6), 0);
	if (!is_sort(stack))
		return (free_list(&stack), 0);
	return (free_list(&stack), 1);
}

void	print_index(Pile **lst)
{
	Pile	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		printf("%i\n", ptr->index);
		ptr = ptr->next;
	}
	printf("\n");
}

void	prinpile(Pile **lst)
{
	Pile	*tmp;

	if (!*lst || !lst)
		return ;
	printf("\n");
	tmp = *lst;
	while (tmp)
	{
		printf("%i\n", tmp->valeur);
		tmp = tmp->next;
	}
	printf("\n");
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
	Pile	**stack_a;
	Pile	**stack_b;

	if (!parse(ac, av))
		return (0);
	stack_a = malloc(sizeof(Pile));
	stack_b = malloc(sizeof(Pile));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = iniPile(ac, av);
	*stack_b = NULL;
	if (ft_lstsize(*stack_a) <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
