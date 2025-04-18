/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:50:19 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 13:57:29 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void redraw(t_fdf *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr); // limpa janela
    draw_map(data);
}

void set_initial_view(t_fdf *data, int win_width, int win_height)
{
    int margin = 100;
    int z_min, z_max;
    get_z_range(data, &z_min, &z_max);

	float cos_30 = cos(0.523599);
	float sin_30 = sin(0.523599);
	float min_x = (0 - (data->height - 1)) * cos_30;
	float max_x = ((data->width - 1) - 0) * cos_30;
	float min_y = (0 + 0) * sin_30 - z_max;
	float max_y = ((data->width - 1) + (data->height - 1)) * sin_30 - z_min;
	float iso_width = max_x - min_x;
	float iso_height = max_y - min_y;
	float zoom_x = (win_width - 2 * margin) / iso_width;
	float zoom_y = (win_height - 2 * margin) / iso_height;
	data->zoom = (zoom_x < zoom_y) ? zoom_x : zoom_y;
	float map_width = iso_width * data->zoom;
	float map_height = iso_height * data->zoom;
	data->shift_x = (win_width - map_width) / 2 - min_x * data->zoom;
	data->shift_y = (win_height - map_height) / 2 - min_y * data->zoom;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 65307)
	{
		get_next_line(-1);
        free_data(data);
        exit(0);
	}
	if (key == 61 || key == 65451)
		data->zoom += 5;
	if (key == 45 || key == 65453)
        data->zoom -= 5;
	if (key == 65364)
		data->shift_y -= 10;
	if (key == 65362)
        data->shift_y += 10;
	if (key == 65361)
        data->shift_x -= 10;
	if (key == 65363)
        data->shift_x += 10;

	redraw(data);
	return (0);
}
