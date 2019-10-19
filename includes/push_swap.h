/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:50:33 by nharra            #+#    #+#             */
/*   Updated: 2019/10/18 23:47:07 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int				find_middle(t_stack *a, size_t count);
size_t			half_to_b(t_stack *a, t_stack *b, size_t size);
void			sort_stack(t_stack *a, t_stack *b, size_t size);
void			sort_2a(t_stack *a);
int				check_simple_a(t_stack *a, size_t size_a);
int				check_simple_b(t_stack *b, size_t size_b);

#endif
