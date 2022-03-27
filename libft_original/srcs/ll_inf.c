/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_inf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:22:33 by V                 #+#    #+#             */
/*   Updated: 2022/03/17 00:19:02 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ll_max(t_stack *l)
{
	t_node	*ptr;
	int		max;
	
	ft_mmm(l);
	ptr = l->tail;
	max = ptr->nb;
	if (!ptr)
		return (0);
	while (ptr)
	{
		if (ptr->nb > max)
			max = ptr->nb;
		ptr = ptr->prev;
	}
	return (max);
}

int		ll_size(t_stack *l)
{
	int		i;
	t_node	*ptr;

	i = 0;
	ptr = l->head;
	if (!ptr)
		return (0);
	while (ptr)
	{
		i++;
		if (ptr->next == NULL)
			break;
		ptr = ptr->next;
	}
	return (i);
}

bool	ll_desc(t_stack *l)
{
	t_node	*ptr;

	ptr = l->head;
	while(ptr->next)
	{
		if (ptr->nb < ptr->next->nb)
			return (false);
		ptr = ptr->next;
	}
	return true;
}

t_node	*ft_rt_node(int i)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	n->nb = i;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
