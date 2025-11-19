#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

#define PHILO_MAX 200 // Macro constante

// argumentos do programa
typedef struct s_params
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_count;
}   t_params;

// estrutura principal do programa
typedef struct s_program
{
    t_params        params;
    long            start_time;
    int             someone_died;
    pthread_mutex_t     print_mutex;
    pthread_mutex_t     meal_mutex;
}   t_program;

// estrutura de cada filósofo
typedef struct s_philo
{
    int                 id;
    long                last_meal;
    int                 meals_eaten;
    int                 must_eat;
    pthread_mutex_t     *l_fork;
    pthread_mutex_t     *r_fork;
    t_program           *program;
} t_philo;

int     parse_args(t_params *params, int argc, char **argv);

// retorna timestamp em milissegundos.
long    get_time_ms(void);
// dorme com precisão usando usleep em loop.
void    ms_sleep(long ms);

void    init_program(t_program *program, t_params *params);
void    init_forks(pthread_mutex_t *forks, int count);
void    init_philos(t_philo *philos, t_program *program,
    pthread_mutex_t *forks, t_params *params);
void    thread_create(t_philo *philos, t_program *program);
void    print_status(t_philo *philo, char *status);
void    *death_monitor(void *arg);
void    destroy_all(t_program *program, pthread_mutex_t *forks);

#endif

/*
Um mutex (mutual exclusion) é um objeto que pode ser travado (lock) por uma única thread de cada vez.
Enquanto uma thread mantém o mutex bloqueado, nenhuma outra pode entrar na seção crítica protegida por ele.
*/