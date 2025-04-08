/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:32:12 by kali              #+#    #+#             */
/*   Updated: 2025/04/08 16:07:31 by kali             ###   ########.fr       */
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

//SHORTER
typedef pthread_mutex_t t_mutex;

//COMPILING, USED BEFORE IN PHILO STRUCT
typedef struct s_table t_table;

typedef struct s_philo
{
    int         philo_id;
    int         meals_eaten;
    long        last_eaten;
    t_mutex     *first_fork;
    t_mutex     *second_fork;
    pthread_t   philo_thread;
    t_table     *table;
}   t_philo;

struct  s_table
{
    long         nb_philos;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    long         nb_meals;
    long        start_dinner;
    bool        end_dinner;
    t_mutex     lock_write;
    t_mutex     lock_meal;
    t_mutex     lock_simulation;
    t_mutex     *forks;
    t_philo     *philos;
};

int main(int ac, char **av);

//PARSING
int    parsing(t_table *table, char **av);

//INITIALIZATION
void    init_table(t_table *table);
void    init_philos(t_table *table);

//DINNER
void    *dinner(void *data);

//MONITOR
void    *monitor(void *data);

//UTILS
int    ft_error(const char *str, int nb);
void    ft_clean(t_table *table);
long    get_current_time(void);
void    precise_usleep(long timestamp, t_table *table);
void	messages(int nb, t_philo *philo);

#endif
