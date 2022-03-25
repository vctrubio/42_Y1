/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_optimisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:23:01 by V                 #+#    #+#             */
/*   Updated: 2022/03/16 18:23:35 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ptr_2_ptr(t_node *a, t_node *b)
{
	if (b->next)
		b->next->prev = a;
	if (a->prev)
		a->prev->next = b;
	a->next = b->next;
	b->next = a;
	if (a->prev)
		b->prev = a->prev;
	a->prev = b;
}

int		ft_check_ll(t_stack *l)
{
	t_node	*ptr;
	int		i;
	int		c;

	ptr = l->head;
	i = 1;
	c = 0;
	while (ptr)
	{
		if (ptr->next != NULL )
			if (ptr->nb > ptr->next->nb)
				i = 0;
		ptr = ptr->next;
		c++;
	}
	if (i == 1)
		l->sorted = true;
	else
		l->sorted = false;
	l->size = c;
	return (i);
}

void	ft_mmm(t_stack *l)
{
	int		*arr;
	int		i;

	ft_check_ll(l);
	arr = malloc(sizeof(int) * l->size);
	arr = ft_opt_arr(l, arr);
	if (l->size % 2)
		l->inf->mean = arr[l->size/2];
	else 
		l->inf->mean = arr[(l->size/2) - 1];
	i = 0;
	l->inf->min = arr[i];
	l->inf->max = arr[i];
	while (i < l->size)
	{
		if (arr[i] > l->inf->max)
			l->inf->max = arr[i];
		if (arr[i] < l->inf->min)
			l->inf->min = arr[i];
		i++;
	}
	free(arr);
}

