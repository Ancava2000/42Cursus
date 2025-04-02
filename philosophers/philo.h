/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:36:13 by acarro-v          #+#    #+#             */
/*   Updated: 2025/04/02 13:58:57 by kali             ###   ########.fr       */
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
# define WHITE "\e[1;37m"
# define MAGENTA "\033[0;95m"

// SHORTER
typedef pthread_mutex_t	t_mtx;

// COMPILE
// It is used in philos before it's written,
// declared here to indicate compiler that this struct exists
typedef struct s_table	t_table;

//CODES FOT TIME
typedef enum	e_time_code
{
	MILISECONDS,
	MICROSECONDS,
}	t_time_code;


// FORKS
typedef struct s_fork
{
	int			fork_id;
	t_mtx		fork; //used or not
}	t_fork;

// PHILOS
typedef struct s_philo
{
	int			philo_id;
	bool		full;
	long		last_eaten;
	int			meals_counter;
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_mtx		lock_philo; //each last time eaten (last_eaten)
	pthread_t	thread_id; //every philo is a thread, every philo does actions
	t_table		*table; //every philo has access to all the global values
}	t_philo;

// ALL DATA
// ./philo 5(number) 800(die in ms) 200(eat in ms) 200(sleep in ms)
struct	s_table
{
	long		nb_philos;
	long		nb_meals;
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
	long		start_time;
	long		nb_threads_run;
	bool		threads_ready;
	bool		end_dinner;
	t_mtx		lock_write; //when to write messages
	t_mtx		lock_simulation; //when to start, loop and end simulation
	pthread_t	check_end; //threads to check with function when philo dies
	t_philo		*philos;
	t_fork		*forks;
};

int		main(int ac, char **av);

//PARSING
void	parse_av(t_table *table, char **av);

//UTILS
void	ft_error(const char *str);
void	ft_error_2(void);
void	messages(int nb, t_philo *philo);
long	current_time(t_time_code code);
void	precise_usleep(long timestamp, t_table *table);

//INITIALIZATION
void	init_data(t_table *table);

//SIMULATION
void  	*launcher(void *data);

//SET AND GET VALUES WITH MUTEX
bool  	lock_get_bool(t_mtx *mutex, bool *value);
long  	lock_get_long(t_mtx *mutex, long *value);
void 	set_value_long(t_mtx *mutex, long *dest, long value);
void 	set_value_bool(t_mtx *mutex, bool *dest, bool value);
bool    simulation_finish(t_table *table);

//FREE
void	ft_clean(t_table *table);

//CHECK END SIMULATION (DEATH AND MEALS)
void  	*monitor(void *data);

//UTILS THREAD SYNCHRONIZATION
void    wait_threads(t_table *table);
void    count_nb_threads(t_mtx *mutex, long *value);
bool	all_threads_run(t_mtx *mutex, long *threads, long philo_nb);

#endif
