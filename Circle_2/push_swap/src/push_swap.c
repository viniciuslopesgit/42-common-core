#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split_argv = NULL; // Para rastrear o resultado de ft_split

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
		else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		argv = split_argv; // Usa o resultado de ft_split como argv
	}
	init_stack_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	// Libera a memória alocada por ft_split, se aplicável
	if (split_argv)
	{
		for (int i = 0; split_argv[i]; i++)
			free(split_argv[i]);
		free(split_argv);
	}
	return (0);
}