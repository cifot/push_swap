/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:01:46 by nharra            #+#    #+#             */
/*   Updated: 2019/10/01 16:46:29 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# define BUFF_SIZE 1024

#include <string.h>

typedef struct		s_dlist
{
	void			*content;
	int				tag;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int				ft_atol(const char **str);
int				ft_strcmp(const char *s1, const char *s2);
int				get_next_line(const int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *dest, const char *src);
char			*ft_safe_strcat(char **dest, const char *src);
void			*ft_memalloc(size_t size);
void			ft_dlist_simple_del(t_dlist **lst);
void			ft_dlist_simple_delone(t_dlist **lst, t_dlist *ptr);
t_dlist			*ft_dlist_pushtag(t_dlist **lst, int tag);
t_dlist			*ft_dlist_push(t_dlist **lst, void *data, size_t size,
								int tag);
t_dlist			*ft_dlist_find_tag(t_dlist const *lst, const int tag);
void			ft_dlist_delone(t_dlist **lst, t_dlist *ptr,
								void (*del)(void *));
int				ft_dlist_is_sorted(t_dlist *lst);
void			ft_dlist_del(t_dlist **lst, void (*del)(void *));
void			op_sa(t_dlist **stack_a);
void			op_ss(t_dlist **stack_a, t_dlist **stack_b);
void			op_pa(t_dlist **stack_a, t_dlist **stack_b);
void			op_ra(t_dlist **stack);
void			op_rra(t_dlist **stack_a);
void			op_rr(t_dlist **stack_a, t_dlist **stack_b);
void			op_rrr(t_dlist **stack_a, t_dlist **stack_b);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
int				init_stack(t_dlist **stack, const char *numbers);

#endif
