/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:55:27 by V                 #+#    #+#             */
/*   Updated: 2022/03/19 16:09:09 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	sort_small_less_than_three(t_stack *l)
{
	ft_mmm(l);
	if (l->size <= 2)
	{
		if (l->head->nb > l->head->next->nb)
			ll_swap(l, 'a');
	}
	else
	{
		if (l->inf->min == l->tail->nb && l->inf->max != l->head->nb)
			ll_rr(l, 'a');
		if (l->head->nb == l->inf->max && l->tail->nb != l->inf->min)
			ll_rotate(l, 'a');
		if (l->head->nb > l->head->next->nb)
			ll_swap(l, 'a');
		if (l->tail->nb == l->inf->min)
			ll_rr(l, 'a');
		if ((l->tail->nb != l->inf->min) && (l->tail->nb != l->inf->max))
		{
			ll_swap(l, 'a');
			ll_rotate(l, 'a');
		}
	}
}

void	sort_small_less_than_six(t_ps *ps)
{
	int mean;

	mean = ps->a->inf->mean;
	// printf("MEAN IS %d\n", mean);
	while(1)
	{
		ft_mmm(ps->a);
		if (ps->a->tail->nb == ps->a->inf->min)
			ll_rr(ps->a, 'a');
		if (ft_check_ll(ps->a) == 1)
			break;
		if (ps->a->size <= 3)
		{
			sort_small_less_than_three(ps->a);
			break;
		}
		if (ps->a->head->nb <= mean)
			ll_pushB(ps->a, ps->b);
		else if (ps->a->head->next->nb <= mean)
		{
			ll_swap(ps->a, 'a');
			ll_pushB(ps->a, ps->b);
		}
		else
			ll_rotate(ps->a, 'a');
	}
}
