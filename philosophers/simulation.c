void  launcher(t_table *table)
{
  int i;

  i = -1;
  if (table -> nb_philos == 1)
    ;
  else
    while (++i < table -> nb_philos)
      {
        if (phtread_create(&table -> philos[i].thread_id, NULL, &philo_routine,  &table -> philos[i]) != 0)
            ft_error("Error creating thread");
      }
    i = -1
    while (++i < table -> nb_philos)
    {
      if (phtread_join(table -> philos[i].thread_id, NULL) != 0)
          ft_error("Error joining threads");
    }
}
