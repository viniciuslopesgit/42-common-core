/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:31:16 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 14:23:27 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

static t_fdf	*init_fdf(char *file)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	get_dimensions(file, &data->width, &data->height);
	data->map = read_map(file, data->width, data->height);
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

static void	setup_window(t_fdf *data)
{
	int	win_size;

	win_size = 1000;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			win_size, win_size, "FDF - 42School");
	set_initial_view(data, win_size, win_size);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		write(1, "Error: Usage: ./fdf <filename>.fdf\n", 36);
		return (1);
	}
	data = init_fdf(argv[1]);
	if (!data)
	{
		write(2, "Error: Failed to read map\n", 26);
		return (1);
	}
	setup_window(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
