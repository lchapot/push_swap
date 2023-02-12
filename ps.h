/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:27:04 by lchapot           #+#    #+#             */
/*   Updated: 2023/02/12 19:36:57 by lchapot          ###   ########.fr       */
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
	int			valeur;
	int			index;
	struct pile *next;
}			Pile;

void	insert_last(Pile **lst, int val, int index);
void	delete_node(Pile**lst, int val);
Pile	*find_prev_elem(Pile *lst, int val);
Pile	*init_list(int ac, char **av);

Pile	*ft_lstnew(int val, int index);
size_t	ft_lstsize(Pile *lst);
Pile	*ft_lstlast(Pile *lst);
void	free_list(Pile **lst);

int		is_sort(Pile *lst);
int		find_duplicate(Pile *stack);
int		is_arg_valid(char **str);
int		is_int(char **str);
long	ft_atoi(char *str);

int		ss(Pile *stack_a, Pile *stack_b);
int		rr(Pile **stack_a, Pile **stack_b);
int		rrr(Pile **stack_a, Pile **stack_b);
int		swap_stack(Pile *stack, char c);
int		rotate_stack(Pile **stack, char c);
int		reverse_rotate_stack(Pile **stack, char c);
int		push_stack(Pile **stack1, Pile **stack2, char c);

int		parse(int ac, char **av);
void	print_index(Pile **lst);
void	prinpile(Pile **lst);
void	ft_putendl_fd(char *str, int fd);

void	indexing(Pile *list);
int		find_index(Pile *stack, int x);
int		get_max_bits(Pile **lst);
void	radix_sort(Pile **stack_a, Pile **stack_b);

void	sort_2(Pile **stack, char c);
void	sort_3(Pile **stack, char c);
void	sort_4(Pile **stack_a, Pile **stack_b, int x);
void	sort_5(Pile **stack_a, Pile **stack_b);
void	sort_small(Pile **stack_a, Pile **stack_b);

#endif