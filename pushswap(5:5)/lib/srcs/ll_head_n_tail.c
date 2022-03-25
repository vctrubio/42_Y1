/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_head_n_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:22:14 by V                 #+#    #+#             */
/*   Updated: 2022/03/16 18:22:28 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*rt_ll_head(t_node *n)
{
	while (n)
	{
		if (n->prev == NULL)
			break;
		n = n->prev;
	}
	return (n);
}

t_node	*rt_ll_tail(t_node *n)
{
	while (n)
	{
		if (n->next == NULL)
			break;
		n = n->next;
	}
	return (n);
}

int		head_or_tail(t_stack *l, int nb)
{
	int		i;
	int		j;
	t_node	*tmp;
	t_node	*t2;
	
	tmp = l->head;
	t2 = l->tail;
	i = 0;
	while(tmp->nb != nb)
	{
		tmp = tmp->next;
		i++;
	}
	j = 0;
	while (t2->nb != nb)
	{
		t2 = t2->prev;
		j++;
	}
	if (i < j)
		return (1);
	else
		return (2);
}
