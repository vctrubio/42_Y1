/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:54:43 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/19 16:29:13 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "lib/libft.h"

typedef struct	s_struct
{
	int			*array;
	int			pos;
	int			size;
}				t_array; 

typedef struct s_pushswap
{
	t_stack	*a;
	t_stack	*b;
	bool	complete;
}				t_ps;

t_stack	*rt_init_stack(void);
void	init_ps(t_ps *ps);

//PRINTERS
void	ft_printf_arr(int *a, int size);
void	ft_print_node_t(t_node *n);
void	ft_print_node_h(t_node *n);

//OPS
void	ll_swap(t_stack *l, char c);
void	ll_rotate(t_stack *l, char c);
void	ll_rr(t_stack *l, char c);
void	ll_pushB(t_stack *a, t_stack *b);
void	ll_pushA(t_stack *a, t_stack *b);
void	ll_ss(t_stack *l, t_stack *lb);
void	ll_rr2(t_stack *l, t_stack *lb);

void	freenexit(t_ps *game);
t_array		*ft_validate_ps(int ac, char **args);

void	sort_small_less_than_three(t_stack *l);
void	sort_small_less_than_six(t_ps *ps);

void	ft_clr_split(char **str);
void	ft_exit(void);

#endif
