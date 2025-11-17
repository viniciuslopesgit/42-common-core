#include "philosophers.h"

#define PHILO_MAX 200 // Macro constante

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int check_arg_content(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if ((arg[i] < '0') || (arg[i] > '9'))
            return (1);
        i++;
    }
    return (0);
}

int check_valid_args(int argc, char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]))
		return (write(2, "Invalid philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]))
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]))
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]))
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argc == 6 && (ft_atoi(argv[5]) <= 0 || check_arg_content(argv[5])))
		return (write(2, "Invalid must_eat value\n", 24), 1);
    return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 6)
		return (write(2, "Wrong argument count\n", 22), 1);
	if (check_valid_args(argc, argv))
		return (1);
	params.number_of_philosophers = ft_atoi(argv[1]);
	params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]);
	params.time_to_sleep = ft_atoi(argv[4]);
	params.must_eat_count = (argc == 6) ? ft_atoi(argv[5]) : -1;
	printf("Parsed OK: %d philosophers, die=%d eat=%d sleep=%d must_eat=%d\n",
		params.number_of_philosophers, params.time_to_die,
		params.time_to_eat, params.time_to_sleep, params.must_eat_count);
	return (0);
}