/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:50:33 by nharra            #+#    #+#             */
/*   Updated: 2019/10/19 13:41:48 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

int				find_middle(t_stack *a, size_t count);
size_t			half_to_b(t_stack *a, t_stack *b, size_t size);
size_t			half_to_a(t_stack *a, t_stack *b, size_t size);
void			sort_hard_3b(t_stack *b, t_stack *a);
void			sort_hard_3a(t_stack *a);
int				check_simple_a(t_stack *a, size_t size_a);
void			sort_stack_a_b(t_stack *a, t_stack *b, size_t size);
void			sort_stack_b_a(t_stack *a, t_stack *b, size_t size);
int				check_simple_b(t_stack *b, t_stack *a, size_t size_b);

#endif
