#include "../head.h"

//destroy mutext, demalloc, exit
//nothing fucking ever works here
void	freenexit(t_info *info)
{
	int i;

	i = -1;
	while(++i < info->n_philo)
	{
		pthread_mutex_destroy(info->chp[i].mutex);

			// free(&info->chp[i]);
			// free(&info->philo[i].status);
			// free(&info->philo[i]);
		
		// pthread_mutex_destroy(&info->slf);
	}
	// free(info);
	exit(1);
}
