/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:10:19 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 18:21:40 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int	ft_abs_atoi(const char *s)
{
	int				sign;
	long long int	n;
	int				rtn;

	n = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (*s == '0')
		return (0);
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *(s++) - '0';
	if (n > 2147483647 || n < -2147483648)
		ft_exit();
	rtn = n * sign;
	return (rtn);
}

void	ll_print(t_node *tmp)
{

	t_node *s;

	s = tmp;
	while(s)
	{
		printf("%d ", s->nb);
		s = s->next;
	}
}

static void	do_pushswap(t_ps *pushswap)
{
	ft_mmm(pushswap->a);
	if (pushswap->a->size <= 3)
		sort_small_less_than_three(pushswap->a);
	else if (pushswap->a->size <= 6)
		sort_small_less_than_six(pushswap);
	else
		while (pushswap->a->sorted != true)
			init_pushto_b(pushswap);
	init_pushto_a(pushswap);

	if (ft_check_ll(pushswap->a))
	{
		ll_print(pushswap->a->head);
		printf("ture\n");
	}
	freenexit(pushswap);
}

void	ft_free_t_array(t_array *t)
{
	int	i;

	i = 0;
	while (i < t->size)
	{
		t->array[i] = '\0';
		i++;
	}
	free(t->array);
	t->array = NULL;
	free(t);
	t = NULL;
}


int	main(int ac, char **ag)
{
	t_ps	*pushswap;
	t_array	*rtarray;

	if (ac > 1)
		rtarray = ft_validate_ps(ac, ag);
	else
		exit(1);
	pushswap = malloc(sizeof(t_ps));
	pushswap->complete = false;
	pushswap->a = rt_init_stack();
	pushswap->b = rt_init_stack();
	ft_ar_to_ll(pushswap->a, rtarray->array, rtarray->size);
	do_pushswap(pushswap);
	ft_free_t_array(rtarray);
	return (1);
}

//remove printf(true) after testing.