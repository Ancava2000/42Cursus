/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:55:33 by kali              #+#    #+#             */
/*   Updated: 2025/04/05 11:08:51 by kali             ###   ########.fr       */
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
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\33[0;93m"
# define BLUE "\33[0;94m"
# define WHITE "\33[1;37m"

typedef pthread_mutex_t t_mutex;

//Pointers for global mutexes. These are individuals mutex for each philosopher. CLEANER
typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*lock_write;
	t_mutex	*lock_meal;
}	t_mutexes;

//All philo data
typedef struct  s_philo
{
    int         meals_counter;
    int         nb_philos;
    int         philo_id;
    int         nb_meals;
    long	    time_to_die;
	long	    time_to_sleep;
	long	    time_to_eat;
	long	    start_time;
    long        last_eat;
    t_mutexes   philo_mutex; //access to mutexes
    pthread_t	philo_thread;
}   t_philo;


//All philo and mutexes data
typedef struct  s_table
{
    t_philo       *philos; //pointer to all data on philo struct (* cause dynamic, multiple)
    t_mutex       *forks; //pointer to forks mutex: left and right (* cause dynamic, multiple)
    t_mutex       lock_meal; //global mutex for general control of ALL philosophers
    t_mutex       lock_write; //global mutex for general control of ALL philosophers
}   t_table;

//MAIN
int	    main(int ac, char **av);

//PARSING
void    parse_av(int argc, char **av);
long    ft_atoi2(const char *str);

//INIT
void    init_table(t_table *table, t_philo *philo, t_mutex *forks, char **av);
void    init_forks(t_table *table, t_mutex *forks, int nb_forks);
void    init_philos(t_table *table, t_philo *philo, t_mutex *forks, char **av);

//SIMULATION
void    dinner(t_table *table, int count);

//UTILS
void	ft_error(const char *str, int nb);
void	messages(int nb, t_philo *philo);
long	current_time(void);
void	precise_usleep(long timestamp);
void	ft_clean(t_table *table, int count);

#endif