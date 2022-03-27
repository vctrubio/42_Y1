/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:30:23 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/27 15:31:18 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

typedef struct s_status
{
	bool		eating;
	bool		sleeping;
	bool		thinking;
	bool		dead;
}				t_status;

typedef struct s_chps
{
	int				pos;
	bool			busy;
	pthread_mutex_t	*mutex;
}				t_chps;

typedef struct s_philo
{
	struct s_info	*info;
	long long int	t_lmeal;
	int				pos;
	t_chps			*c1;
	t_chps			*c2;
	t_status		*status;
	int				n_meal;
}				t_philo;

typedef struct s_info
{
	t_philo			*philo;
	t_chps			*chp;
	pthread_mutex_t	slf;
	pthread_t		*th;
	int				n_philo;
	long long int	t_die;
	long long int	t_eat;
	long long int	t_sleep;
	long long int	t_start;
	int				max_nmeal;
}				t_info;

t_info		*init_info(char **ag);
int			ft_atoi(const char *s);
int			init_threads(t_info *info);

uint64_t	gettimeofday_ms(void);
uint64_t	time_since_start(void);
void		ft_print_phil(t_philo *philo);

void		freenexit(t_info *info);
void		ft_forks(t_philo *philo, t_info **info);
void		ft_sleep(t_philo *philo, t_info **info);
void		ft_think(t_philo *philo, t_info **info);

//COLOR CODE PRINTF
# define C1 	"\e[0;30m" //BLK
# define C2 	"\e[0;31m" //RED
# define C3 	"\e[0;32m" //GRN
# define C4 	"\e[0;33m" //YEL
# define C5 	"\e[0;34m" //BLU
# define C6 	"\e[0;35m" //MAG
# define C7 	"\e[0;36m" //CYN
# define C8 	"\e[0;37m" //WHT
# define CRESET "\e[0m"

#endif