/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:02:02 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 15:28:09 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_think(t_philo *philo, t_info **info)
{
	philo->status->sleeping = false;
	philo->status->thinking = true;
	ft_print_phil(philo);
	usleep(100);
}

void	ft_sleep(t_philo *philo, t_info **info)
{
	philo->c1->busy = false;
	philo->c2->busy = false;
	pthread_mutex_unlock(philo->c1->mutex);
	pthread_mutex_unlock(philo->c2->mutex);
	philo->status->eating = false;
	philo->status->sleeping = true;
	ft_print_phil(philo);
	usleep(philo->info->t_sleep);
}

void	ft_forks_xtra(t_philo *philo)
{
		philo->status->thinking = false;
		philo->c1->busy = true;
		philo->c2->busy = true;
		philo->status->eating = true;
		philo->n_meal++;
}

void	ft_forks(t_philo *philo, t_info **info)
{
	int	p;
	int	n;

	n = philo->info->n_philo;
	p = philo->pos;
	pthread_mutex_lock(philo->c1->mutex);
	pthread_mutex_lock(philo->c2->mutex);
	if (philo->c1->busy == false && philo->c2->busy == false)
	{
		printf("%04lli\e[0;3%dm %d has taken a fork \e[0m\n", \
			time_since_start(), p, p);
		printf("%04lli\e[0;3%dm %d has taken a fork \e[0m\n", \
			time_since_start(), p, p);
		ft_forks_xtra(philo);
		philo->t_lmeal = gettimeofday_ms();
		ft_print_phil(philo);
		usleep(philo->info->t_eat);
	}
	else
	{
		pthread_mutex_unlock(philo->c1->mutex);
		pthread_mutex_unlock(philo->c2->mutex);
	}
}
