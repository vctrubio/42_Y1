/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:10:19 by V                 #+#    #+#             */
/*   Updated: 2022/03/19 17:08:48 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static void	init_pushtoB_else(t_ps *ps)
{
	if (ps->b->head != NULL && ps->b->head != ps->b->tail)
	{
		ft_mmm(ps->b);
		if (ps->b->head->nb < ps->b->inf->mean)
			ll_rr2(ps->a, ps->b);
		else
			ll_rotate(ps->a, 'a');
	}
	else
		ll_rotate(ps->a, 'a');
}

void	init_pushtoB(t_ps *ps)
{
	int	i;

	i = 0;
	ft_mmm(ps->a);
	while (i++ < ps->a->size)
	{
		if (ps->a->tail->nb == ps->a->inf->min)
			ll_rr(ps->a, 'a');
		if (ft_check_ll(ps->a) == 1)
			break;
		if (ps->a->size <= 3)
		{
			sort_small_less_than_three(ps->a);
			break;
		}
		if (ps->a->head->nb < ps->a->inf->mean)
			ll_pushB(ps->a, ps->b);
		else
			init_pushtoB_else(ps);
	}
}

static void	init_pushtoA2(t_ps *ps)
{
	int	max;

	max = ll_max(ps->b);
	while(ps->b->head->nb != max)
	{
		if (ps->b->tail->nb == max)
			ll_rr(ps->b, 'b');
		else if (ps->b->head->nb == ps->b->inf->min)
			ll_rotate(ps->b, 'b');
		if (ps->b->head->nb == max)
			break;
		else if (ps->b->head->nb > ps->b->head->next->nb)
			ll_swap(ps->b, 'b');
		if (head_or_tail(ps->b, max) == 2)
			while (ps->b->tail->nb != max)
				ll_rr(ps->b, 'b');
		else
			ll_rotate(ps->b, 'b');
	}
}

void	init_pushtoA(t_ps *ps)
{
	int max;
	int	i;

	while(ps->b->head)
	{
		if (ll_desc(ps->b))
			break;
		max = ll_max(ps->b);
		if (ps->b->head->nb == max)
			ll_pushA(ps->a, ps->b);
		init_pushtoA2(ps);
	}
	i = ll_size(ps->b);
	while(i--)
	{
		ll_pushA(ps->a, ps->b);
		if (ps->a->head->nb > ps->a->head->next->nb)
			ll_swap(ps->a, 'a');
	}
}

int main(int ac, char **ag)
{
	t_ps	*pushswap;
	t_stack	*stack;
	t_stack *bstack;
	t_array *rtarray;

	if (ac > 1)
		rtarray = ft_validate_ps(ac, ag);
	else
		ft_exit();
	pushswap = malloc(sizeof(t_ps));
	pushswap->complete = false;
	stack = rt_init_stack();
	pushswap->a = stack;
	bstack = rt_init_stack();
	pushswap->b = bstack;
	ft_ar_to_ll(stack, rtarray->array, rtarray->size);

	ft_mmm(pushswap->a);
	if (pushswap->a->size <= 3)
		sort_small_less_than_three(pushswap->a);
	else if (pushswap->a->size <= 6)
		sort_small_less_than_six(pushswap);
	else
		while (pushswap->a->sorted != true)
			init_pushtoB(pushswap);

	// printf("break\n");
	// ft_print_node_h(pushswap->a->head);
	// ft_print_node_h(pushswap->b->head);

	init_pushtoA(pushswap);

	// ft_print_node_h(pushswap->a->head);
	// int totalcount = pushswap->a->c + pushswap->b->c;
	// printf("TOTAL count %d\n", totalcount);

	freenexit(pushswap);
	free(rtarray->array);
	free(rtarray);
	return (1);
}
