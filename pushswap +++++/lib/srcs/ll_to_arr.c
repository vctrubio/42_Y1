/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_to_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:22:54 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 12:44:58 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_opt_arr(t_stack *l, int *arr)
{
	int	i;
	int	tmp;

	arr = ll_to_arr(l, arr);
	i = 0;
	while (i < l->size)
	{
		if (arr_sorted(arr, l->size))
			break ;
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	arr_sorted(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i +1;
		while (j < size)
		{
			if (arr[i] > arr[j++])
				return (0);
		}	
		i++;
	}
	return (1);
}

int	*ll_to_arr(t_stack *l, int *arr)
{
	int		i;
	t_node	*ptr;

	i = 0;
	ptr = l->head;
	while (ptr)
	{
		arr[i++] = ptr->nb;
		ptr = ptr->next;
	}
	arr[i] = 0;
	return (arr);
}

void	ft_ar_to_ll(t_stack *l, int *a, int size)
{
	t_node	*tmp;
	t_node	*prev;
	int		i;

	i = 0;
	prev = NULL;
	l->size = size;
	while (size--)
	{
		tmp = ft_rt_node(*a);
		a++;
		if (i == 0)
		{
			l->head = tmp;
			i++;
		}
		if (prev != NULL)
		{
			prev->next = tmp;
			tmp->prev = prev;
		}
		prev = tmp;
	}
	l->tail = tmp;
}
