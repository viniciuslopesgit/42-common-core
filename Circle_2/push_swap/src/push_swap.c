/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:41:45 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/15 19:31:44 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	cleanup(t_node **a, char **split_argv)
{
	int	i;

	if (a)
		free_stack(a);
	if (split_argv)
	{
		i = 0;
		while (split_argv[i])
			free(split_argv[i++]);
		free(split_argv);
	}
}

void	validate_and_init(char **argv, t_node **a, char **split_argv, int argc)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			if (argc == 2)
				cleanup(a, split_argv);
			else
				cleanup(a, NULL);
			exit(1);
		}
		i++;
	}
	init_stack_a(a, argv + 1);
}

static void	handle_input(int argc, char **argv, char ***split_argv, t_node **a)
{
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		*split_argv = ft_split(argv[1], ' ');
		argv = *split_argv;
	}
	validate_and_init(argv, a, *split_argv, argc);
}

static void	sort_stack(t_node **a, t_node **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	handle_input(argc, argv, &split_argv, &a);
	sort_stack(&a, &b);
	cleanup(&a, split_argv);
	return (0);
}
