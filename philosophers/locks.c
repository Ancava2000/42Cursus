#include "philo.h"

void set_value_bool(t_mtx *mutex, long *dest, long value)
{
    pthread_mutex_lock(mutex, NULL);
    *dest = value;
    pthread_mutex_unlock(mutex, NULL);
}

int  lock_unlock_bool(t_mtx *mutex, int *value)
{
    pthread_mutex_lock(mutex, NULL);
    if (value == 1)
    {
        pthread_mutex_unlock(mutex, NULL);
        return (1);
    }
    pthread_mutex_unlock(mutex, NULL);
    return (0);
}
