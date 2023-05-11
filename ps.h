/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapot <lchapot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:27:04 by lchapot           #+#    #+#             */
/*   Updated: 2023/03/16 19:05:26 by lchapot          ###   ########.fr       */
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
	struct pile	*next;
}			t_pile;

void	insert_last(t_pile **lst, int val, int index);
void	delete_node(t_pile**lst, int val);
t_pile	*find_prev_elem(t_pile *lst, int val);
t_pile	*init_list(int ac, char **av);

t_pile	*ft_lstnew(int val, int i);
size_t	ft_lstsize(t_pile *lst);
t_pile	*ft_lstlast(t_pile *lst);
void	free_list(t_pile **lst);

int		notsort(t_pile *lst);
int		duplicate(t_pile *stack);
int		is_arg_valid(char **str);
int		is_int(char **str);
long	ft_atoi(char *str);

int		swap_stack(t_pile *stack, char c);
int		rotate_stack(t_pile **stack, char c);
int		reverse_rotate_stack(t_pile **stack, char c);
int		push_stack(t_pile **stack_a, t_pile **stack_b, char c);

int		parse(int ac, char **av);
void	ft_putendl_fd(char *str, int fd);

void	indexing(t_pile *lst);
int		find_index(t_pile *stack, int x);
int		get_max_bits(t_pile **lst);
void	radix_sort(t_pile **stack_a, t_pile **stack_b);

void	sort_2(t_pile **stack, char c);
void	sort_3(t_pile **stack, char c);
void	sort_4(t_pile **stack_a, t_pile **stack_b, int x);
void	sort_5(t_pile **stack_a, t_pile **stack_b);
void	sortmini(t_pile **stack_a, t_pile **stack_b);

#endif
