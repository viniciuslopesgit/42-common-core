/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:50:19 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 14:52:49 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	redraw(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
}

static void	calc_projection(t_fdf *data, t_init_view *view)
{
	view->cos_30 = cos(0.523599);
	view->sin_30 = sin(0.523599);
	view->min_x = (0 - (data->height - 1)) * view->cos_30;
	view->max_x = ((data->width - 1) - 0) * view->cos_30;
	view->min_y = (0 + 0) * view->sin_30 - view->z_max;
	view->max_y = ((data->width - 1) + (data->height - 1))
		* view->sin_30 - view->z_min;
	view->iso_width = view->max_x - view->min_x;
	view->iso_height = view->max_y - view->min_y;
}

static void	calc_zoom_shift(t_fdf *data, t_init_view *view,
	int win_width, int win_height)
{
	view->zoom_x = (win_width - 2 * view->margin) / view->iso_width;
	view->zoom_y = (win_height - 2 * view->margin) / view->iso_height;
	if (view->zoom_x < view->zoom_y)
		data->zoom = view->zoom_x;
	else
		data->zoom = view->zoom_y;
	view->map_width = view->iso_width * data->zoom;
	view->map_height = view->iso_height * data->zoom;
	data->shift_x = (win_width - view->map_width)
		/ 2 - view->min_x * data->zoom;
	data->shift_y = (win_height - view->map_height)
		/ 2 - view->min_y * data->zoom;
}

void	set_initial_view(t_fdf *data, int win_width, int win_height)
{
	t_init_view	view;

	view.margin = 100;
	get_z_range(data, &view.z_min, &view.z_max);
	calc_projection(data, &view);
	calc_zoom_shift(data, &view, win_width, win_height);
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
