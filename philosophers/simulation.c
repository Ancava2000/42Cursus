#include "philo.h"

void  eat(t_philo *philo)
{
  pthread_mutex_lock(&philo -> left_fork -> fork);
  message(1, philo);
  pthread_mutex_lock(&philo -> right_fork -> fork);
  message(2, philo);
  message(3, philo);
  set_value_bool(philo -> lock_philo, philo -> last_eaten, current_time());
  philo -> meals_counter++;
  if (philo -> table -> nb_meals > 0
      && philo -> meals_counter == philo -> table -> nb_meals)
      set_value_bool(philo -> lock_philo, philo -> full, (int)1);
  pthread_mutex_unlock(&philo -> left_fork -> fork);
  pthread_mutex_unlock(&philo -> right_fork -> fork);
}

void  *launcher(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;

    while (!(lock_unlock_bool(&philo -> table -> lock_simulation, &philo -> table -> threads_ready)))
        ;
    while(!(lock_unlock_bool(&philo -> table -> lock_simulation, &philo -> table -> end_dinner)))
    {
        if (philo -> full)
          break ;
      //write status and usllep precise
        eat(philo);
        messages(4, philo);
        precise_usleep(philo -> table -> time_to_sleep);
        messages(5, philo);
    }
}
