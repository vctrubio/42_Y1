/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:24:55 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/27 15:25:24 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

//destroy mutext, demalloc, exit
//nothing fucking ever works here
void	freenexit(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_destroy(info->chp[i].mutex);
	exit(1);
}
