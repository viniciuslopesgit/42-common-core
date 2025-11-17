/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 02:08:31 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/17 21:22:14 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	free_data(t_fdf *data)
{
	int	y;
	if (data->map)
	{
		y = 0;
		while (y < data->height)
		{
			if (data->map[y])
				free(data->map[y]);
			y++;
		}
		free(data->map);
		data->map = NULL;
    }
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	gnl_cleanup();
	free(data);
}

int	close_window(t_fdf *data)
{
	free_data(data);
	exit(0);
	return(0);
}
