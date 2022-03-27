/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:00:21 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 15:22:12 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

uint64_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	time_since_start(void)
{
	static uint64_t	start = 0;

	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

void	ft_print_phil(t_philo *philo)
{
	int			p;
	uint64_t	timestamp;

	p = philo->pos;
	timestamp = time_since_start();
	if (philo->status->dead)
		printf("%04lli\e[0;3%dm %d died\e[0m\n", timestamp, p, p);
	else if (philo->status->eating)
		printf("%04lli\e[0;3%dm %d is eating\e[0m\n", timestamp, p, p);
	else if (philo->status->thinking)
		printf("%04lli\e[0;3%dm %d is thinking\e[0m\n", timestamp, p, p);
	else if (philo->status->sleeping)
		printf("%04lli\e[0;3%dm %d is sleeping\e[0m\n", timestamp, p, p);
}
