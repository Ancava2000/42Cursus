#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>    //printf
# include <unistd.h>   //write, usleep
# include <stdlib.h>   //malloc, free   
# include <stdbool.h>  //bool
# include <limits.h>   //INT_MAX
# include <sys/time.h> //gettimeofday
# include <pthread.h>  //threads and mutex

//COLORS
# define RESET "\033[0m"
# define WHITE "\e[1;37m"
# define RED "\033[0;91m"
# define PINK "\033[0;95m"
# define GREEN "\033[0;92m"
# define BLUE "\033[0;94m"

//SHORTER
typedef pthread_mutex_t t_mutex;
//COMPILE (used before expanded)
typedef struct s_table  t_table;

typedef struct  s_philo
{
    unsigned int        philo_id;
    unsigned int        meals_eaten;
    unsigned long long  last_eaten;
    bool                full;  //for the waiter (check if a philo is full)
    bool                dead_status;  //for the waiter. Important in the one single case
    t_mutex             *first_fork;
    t_mutex             *second_fork;
    pthread_t           philo_thread;
    t_table             *table;
}                       t_philo;

struct  s_table
{
    unsigned int        nb_philos;
    unsigned long long  time_to_die;
    unsigned long long  time_to_eat;
    unsigned long long  time_to_sleep;
    int                 nb_meals;
    unsigned long long  dinner_start;
    bool                stop_flag;  //stop simulation
    t_philo             *philos;
    t_mutex             *forks;
    t_mutex             lock_write;  //write messages
    t_mutex             lock_dead;  //check and change dead_status
    t_mutex             lock_bool_stop;  //check and change stop_flag
    t_mutex             lock_meal; //check and change anything related to meals
    pthread_t           waiter;  //monitor
};

//MAIN
int					main(int ac, char **av);

//PARSING
int					atoi_int(const char *str);
int					atoi_ll(const char *str);

//INIT
int					init_dinner(t_table *table, int ac, char **av);

//DINNER
void	            *dinner(void *data);

//FORKS
void	            lock_forks(t_philo *philo);
void	            unlock_forks(t_philo *philo);

//MONITOR
void	            *waiter(void *data);
int	                check_dead(t_table *table, unsigned int i);
void                check_full(t_philo *philo);

//UTILS_STR
void				ft_error(char *message, int fd);

//UTILS_SIMULATION
void				messages(int messages, unsigned int id, unsigned long long time, t_table *table);
int					ft_clean(t_table *table);
unsigned long long	get_now_time(void);
unsigned long long	precise_usleep(t_table *table, unsigned long long time);

#endif