/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:36:13 by acarro-v          #+#    #+#             */
/*   Updated: 2025/03/27 11:41:59 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> //pthread, mutex
# include <sys/time.h> //gettimeofday
# include <stdlib.h> //malloc, free
# include <stdio.h> //printf
# include <unistd.h> //usleep, write
# include <stdbool.h> // bool
# include <limits.h> //INT_MAX

// COLORS
# define RESET "\033[0m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"

// SHORTER
typedef pthread_mutex_t	t_mtx;

// COMPILE
// It is used in philos before it's written,
// declared here to indicate compiler that this struct exists
typedef struct s_table	t_table;

// FORKS
typedef struct s_fork
{
	int		fork_id;
	t_mtx	fork; //used or not
}	t_fork;

// PHILOS
typedef struct s_philo
{
	int			philo_id;
	int			full;
	long		last_eaten;
	int		meals_counter;
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_mtx		lock_philo;
	pthread_t	thread_id; //every philo is a thread
	t_table		*table; //every philo has access to all the global values
}	t_philo;

// ALL DATA
// ./philo 5 800 200 200
struct	s_table
{
	long	nb_philos;
	long	nb_meals;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
	long	start_time;
	t_mtx	lock_write;
	t_mtx	lock_eat;
	t_philo	*philos;
	t_fork	*forks;
};

int		main(int ac, char **av);
void	parse_av(t_table *table, char **av);
void	ft_error(const char *str);
void	ft_error_2(void);
void	init_data(t_table *table);
//void	start_simulation(t_table *table);
//void	ft_clean(t_table *table);

#endif
