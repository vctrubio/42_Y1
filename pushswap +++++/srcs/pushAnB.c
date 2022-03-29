/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushAnB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:14:09 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/28 12:50:40 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	init_pushto_b(t_ps *ps)
{
	int	i;

	i = 0;
	ft_mmm(ps->a);
	while (i++ < ps->a->size)
	{
		if (ps->a->tail->nb == ps->a->inf->min)
			ll_rr(ps->a, 'a');
		if (ft_check_ll(ps->a) == 1)
			break ;
		if (ps->a->size <= 3)
		{
			sort_small_less_than_three(ps->a);
			break ;
		}
		if (ps->a->head->nb < ps->a->inf->mean)
			ll_push_b(ps->a, ps->b);
		else
			ll_rotate(ps->a, 'a');
	}
}

void	init_pushto_a_two(t_ps *ps)
{
	int	max;
	int	min;

	ll_max_b(ps->b, &max, &min);
	while (ps->b->head->nb != max)
	{
		if (ps->b->tail->nb == max)
			ll_rr(ps->b, 'b');
		else if (ps->b->head->nb == min)
			ll_rotate(ps->b, 'b');
		if (ps->b->head->nb == max)
			break ;
		else if (ps->b->head->nb > ps->b->head->next->nb)
			ll_swap(ps->b, 'b');
		if (head_or_tail(ps->b, max) == 2)
			while (ps->b->tail->nb != max)
				ll_rr(ps->b, 'b');
		else
			ll_rotate(ps->b, 'b');
	}
}

static void	check_a(t_stack *a)
{
	t_node	*ptr;

	ptr = a->head;
	if (ptr->nb > ptr->next->nb)
		ll_swap(a, 'a');
}

void	init_pushto_a(t_ps *ps)
{
	int	max;
	int	min;
	int	i;

	while (ps->b->head)
	{
		if (ll_desc(ps->b))
			break ;
		ll_max_b(ps->b, &max, &min);
		if (ps->b->head->nb == max)
			ll_push_a(ps->a, ps->b);
		check_a(ps->a);
		init_pushto_a_two(ps);
	}
	i = ll_size(ps->b);
	while (i--)
	{
		ll_push_a(ps->a, ps->b);
		if (ps->a->head->nb > ps->a->head->next->nb)
			ll_swap(ps->a, 'a');
	}
}
