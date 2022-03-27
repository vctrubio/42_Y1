/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:01:52 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/27 13:02:20 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

t_stack	*rt_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->c = 0;
	stack->sorted = false;
	stack->inf = malloc(sizeof(t_ainfo));
	stack->inf->max = 0;
	stack->inf->min = 0;
	stack->inf->mean = 0;
	return (stack);
}

void	ll_ss(t_stack *l, t_stack *lb)
{
	ll_swap(l, 's');
	ll_swap(lb, 'z');
}

void	ll_rr2(t_stack *l, t_stack *lb)
{
	ll_rotate(l, 'r');
	ll_rotate(lb, 'z');
}

void	ft_clr_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
