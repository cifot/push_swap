/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:50:53 by nharra            #+#    #+#             */
/*   Updated: 2019/10/05 13:41:22 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct	s_stack
{
	int		n;
	int		max_size;
	int		*data;
}				t_stack;

t_stack			*new_stack(long max_size);
long			check_size(char **argv, int start, int argc);
int				push_input(int argc, char **argv, t_stack *stack);
int				push(t_stack *stack, int n);
int				pop(t_stack *stack);
int				stack_is_sort(t_stack *stack);
int				stack_is_backsort(t_stack *stack, int start);
int				stack_swap(t_stack *a, t_stack *b, char *command);
int				stack_push(t_stack *a, t_stack *b, char *command);
int				stack_rotate(t_stack *a, t_stack *b, char *command);
int				is_min_than(t_stack *stack, int n);
int				is_max_than(t_stack *stack, int n);
int				find_middle_array(t_stack *stack, int start, char c);
int				contains_less_mid(t_stack *stack, int middle);
void			stack_delete(t_stack *stack);

#endif
