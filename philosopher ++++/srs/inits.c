/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:01:53 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 15:24:17 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	init_chp(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		info->chp[i].mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(info->chp[i].mutex, NULL);
		info->chp[i].busy = false;
		info->chp[i].pos = i;
		i++;
	}
}

void	init_sts(t_philo *p)
{
	p->status = malloc(sizeof(t_status));
	p->status->eating = false;
	p->status->sleeping = false;
	p->status->thinking = true;
	p->status->dead = false;
}

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		info->philo[i].info = info;
		info->philo[i].pos = i;
		info->philo[i].t_lmeal = 0;
		info->philo[i].n_meal = 0;
		info->philo[i].c1 = &info->chp[i];
		info->philo[i].c2 = &info->chp[(i + 1) % info->n_philo];
		init_sts(&info->philo[i]);
		i++;
	}
}

//n_philo, t_die, t_eat, t_sleep, max_nmeals
t_info	*init_info(char **ag)
{
	t_info	*info;
	int		n;

	n = ft_atoi(ag[1]);
	info = malloc(sizeof(t_info));
	info->philo = malloc(sizeof(t_philo) * n);
	info->chp = malloc(sizeof(t_chps) * n);
	info->th = malloc(sizeof(pthread_t) * n);
	info->n_philo = n;
	info->t_die = ft_atoi(ag[2]);
	info->t_eat = ft_atoi(ag[3]) * 1000;
	info->t_sleep = ft_atoi(ag[4]) * 1000;
	if (ag[5])
		info->max_nmeal = ft_atoi(ag[5]);
	else
		info->max_nmeal = 0;
	info->t_start = gettimeofday_ms();
	init_chp(info);
	init_philo(info);
	return (info);
}
