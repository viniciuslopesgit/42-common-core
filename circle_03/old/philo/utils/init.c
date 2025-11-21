#include "../philosophers.h"

/*
init_program
Copia os argumentos para dentro da struct principal
Guarda o timestamp inicial
Cria dois mutexes internos:
print_mutex: evita mensagens sobrepostas
meal_mutex: protege leitura/atualização de last_meal
init_forks
Inicializa cada mutex do array de forks
init_philos
Configura cada filósofo com:
id (1…N)
último tempo de refeição
contador de refeições
ponteiros para garfo esquerdo e direito (com lógica circular!)
*/

void    init_program(t_program *program, t_params *params)
{
    program->params = *params;
    program->start_time = get_time_ms();
    program->someone_died = 0;

    pthread_mutex_init(&program->print_mutex, NULL);
    pthread_mutex_init(&program->meal_mutex, NULL);
}

void    init_forks(pthread_mutex_t *forks, int count)
{
    int i;

    i = 0;
    while(i < count)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}

void    init_philos(t_philo *philos, t_program *program,
                    pthread_mutex_t *forks, t_params *params)
{
    int i;

    i = 0;
    while(i < params->number_of_philosophers)
    {
        philos[i].id = i + 1;
        philos[i].program = program;
        philos[i].meals_eaten = 0;
        philos[i].last_meal = get_time_ms();

        if (params->must_eat_count > 0)
            philos[i].must_eat = params->must_eat_count;
        else
            philos[i].must_eat = -1;

        if (philos[i].id % 2 == 0)
        {
            // pares: esquerda depois direita
            philos[i].l_fork = &forks[i];
            philos[i].r_fork = &forks[(i + 1) % params->number_of_philosophers];
        }
        else
        {
            // impares:  direita depois esquerda
            philos[i].r_fork = &forks[i];
            philos[i].l_fork = &forks[(i + 1) % params->number_of_philosophers];
        }
        i++;
    }
}

void    destroy_all(t_program *program, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&program->print_mutex);
    pthread_mutex_destroy(&program->meal_mutex);

    while(i < program->params.number_of_philosophers)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}