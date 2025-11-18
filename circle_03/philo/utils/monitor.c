#include "../philosophers.h"

void	*death_monitor(void *arg)
{
	t_philo	*philos = (t_philo *)arg;
	t_program *program = philos[0].program;
	int	i;

	while (!program->someone_died)
	{
		i = 0;
		while (i < program->params.number_of_philosophers)
		{
			pthread_mutex_lock(&program->meal_mutex);
			if ((get_time_ms() - philos[i].last_meal) > program->params.time_to_die)
			{
				pthread_mutex_lock(&program->print_mutex);
				printf("%ld %d died\n", get_time_ms() - program->start_time, philos[i].id);
				program->someone_died = 1;
				pthread_mutex_unlock(&program->print_mutex);
				pthread_mutex_unlock(&program->meal_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&program->meal_mutex);
			i++;
		}

		// Verificar condição opcional de refeições completas
		if (program->params.must_eat_count > 0)
		{
			int	all_ate = 1;
			i = 0;
			while (i < program->params.number_of_philosophers)
			{
				if (philos[i].meals_eaten < program->params.must_eat_count)
					all_ate = 0;
				i++;
			}
			if (all_ate)
			{
				program->someone_died = 1;
				return (NULL);
			}
		}
		usleep(1000); // dormir pouco para não consumir CPU
	}
	return (NULL);
}
