/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_inf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:22:33 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 19:31:12 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ll_max_b(t_stack *l, int *max, int *min)
{
	t_node	*ptr;

	ptr = l->tail;
	*max = ptr->nb;
	*min = ptr->nb;
	if (!ptr)
		return ;
	while (ptr)
	{
		if (ptr->nb > *max)
			*max = ptr->nb;
		if (ptr->nb < *min)
			*min = ptr->nb;
		ptr = ptr->prev;
	}
}

int	ll_max(t_stack *l)
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

int	ll_size(t_stack *l)
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
			break ;
		ptr = ptr->next;
	}
	return (i);
}

bool	ll_desc(t_stack *l)
{
	t_node	*ptr;

	ptr = l->head;
	while (ptr->next)
	{
		if (ptr->nb < ptr->next->nb)
			return (false);
		ptr = ptr->next;
	}
	return (true);
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
