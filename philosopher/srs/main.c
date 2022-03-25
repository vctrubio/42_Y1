/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:01:16 by V                 #+#    #+#             */
/*   Updated: 2022/03/19 15:01:40 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static void	ft_validate_philo(char **ag)
{
	int	i;
	int	j;

	i = 1;
	while (ag[i])
	{
		j = 0;
		while (ag[i][j])
		{
			if(ag[i][j] < '0' || ag[i][j] > '9')
				exit(1);
			j++; 
		}
		i++;
	}
}

//n_philo, t_die, t_eat, t_sleep, max_nmeals
int	main(int ac, char **ag)
{
	t_info	*info;
	int		i;

	if (ac == 5 || ac == 6)
	{
		ft_validate_philo(ag);
		info = init_info(ag);
	
		// printf("Philosopher;(%d),t_eat(%lld), t_die(%lld), t_sleep(%lld), max_meal(%d)\n", info->n_philo, info->t_eat, info->t_die, info->t_sleep, info->max_nmeal);
		// i = -1;
		// while (++i < info->n_philo)
		// 	printf("PHILO %d with c%d | c%d is not dead%d but thinking%d\n", info->philo[i].pos, info->philo[i].c1->pos, info->philo[i].c2->pos, info->philo[i].status->dead, info->philo[i].status->thinking);
		
		init_threads(info);
		freenexit(info);
	}

	return (0);
}
