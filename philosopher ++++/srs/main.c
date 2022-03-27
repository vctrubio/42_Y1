/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:01:16 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 15:23:24 by vrubio           ###   ########.fr       */
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
			if (ag[i][j] < '0' || ag[i][j] > '9')
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
		init_threads(info);
		freenexit(info);
	}
	else
		printf("!= arguments\n");
	return (0);
}
