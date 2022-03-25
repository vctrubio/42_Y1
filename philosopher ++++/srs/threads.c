/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:01:03 by V                 #+#    #+#             */
/*   Updated: 2022/03/19 15:01:06 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int		ft_condition(t_philo *p)
{
	long long int ttime; //time since last meal

	ttime = gettimeofday_ms() - p->t_lmeal;
	if (p->t_lmeal > 0)
	{
		if (gettimeofday_ms() - p->t_lmeal > p->info->t_die)
		{
			// printf("philo %d check (%lld) vs |%lld|\n", p->pos, ttime, p->info->t_die);
			// printf("TRUE time of philo(%d) is %lld vs %lld \n", p->pos, gettimeofday_ms() - p->t_lmeal, p->info->t_die);
			p->status->dead = true;
			ft_print_phil(p);
			freenexit(p->info);
		}
	}
	if (p->n_meal >= p->info->max_nmeal && p->info->max_nmeal != 0)
	{
		printf("Philo(%d) as eating %d\n", p->pos, p->n_meal);
		return (0);
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(ft_condition(philo))
	{
		if (philo->status->thinking == true)
			{
			pthread_mutex_lock(&philo->info->slf);
			ft_forks(philo, &philo->info);
			pthread_mutex_unlock(&philo->info->slf);
		}
		if (philo->status->eating == true)
		{
			pthread_mutex_lock(&philo->info->slf);
			ft_sleep(philo, &philo->info);
			pthread_mutex_unlock(&philo->info->slf);
		}
		if (philo->status->sleeping == true)
		{
			pthread_mutex_lock(&philo->info->slf);
			ft_think(philo, &philo->info);
			pthread_mutex_unlock(&philo->info->slf);
		}	
	}
	return (0);
}


int	init_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_create(&info->th[i], NULL, &routine, &info->philo[i]) != 0)
			{
				perror("ERROR in creating threads- init_threads\n");
				return (0);
			}
		i++;
	}
	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_join(info->th[i], NULL) != 0)
		{
			perror("ERROR in joining threads- init_threads\n");
			return (0);
		}
		i++;
	}
	return (1);
}
