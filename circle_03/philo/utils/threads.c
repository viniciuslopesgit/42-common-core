#include "../philosophers.h"

void	print_status(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->program->print_mutex);
	if (!philo->program->someone_died)
	{
		timestamp = get_time_ms() - philo->program->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->program->print_mutex);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);

	while (!philo->program->someone_died)
	{
		// Pegar 1º garfo
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");

		// Pegar 2º garfo
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");

		// Comer
		pthread_mutex_lock(&philo->program->meal_mutex);
		philo->last_meal = get_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->program->meal_mutex);

		print_status(philo, "is eating");
		ms_sleep(philo->program->params.time_to_eat);

		// Soltar forks
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		// Verificar se já terminou
		if (philo->must_eat != -1 &&
			philo->meals_eaten >= philo->must_eat)
			break;

		// Dormir
		print_status(philo, "is sleeping");
		ms_sleep(philo->program->params.time_to_sleep);

		// Pensar
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	thread_create(t_philo *philos, t_program *program)
{
	pthread_t	threads[PHILO_MAX];
    pthread_t   monitor;
	int			i;

	i = 0;
	while (i < program->params.number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
		i++;
	}

    pthread_create(&monitor, NULL, death_monitor, philos);

	i = 0;
	while (i < program->params.number_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
    pthread_join(monitor, NULL);
}

/*
Explicação
print_status()
Usa print_mutex para evitar logs sobrepostos.
Imprime: <timestamp> <id> <status>.
philo_routine()
Loop infinito enquanto ninguém morreu.
Pega fork esquerdo e direito (mutex lock).
Come, atualiza last_meal, incrementa meals_eaten.
Solta os forks (mutex unlock).
Dorme e pensa.
Ainda não implementámos a verificação de morte.
thread_create()
Cria uma thread para cada filósofo.
Espera todas terminarem (pthread_join).
*/